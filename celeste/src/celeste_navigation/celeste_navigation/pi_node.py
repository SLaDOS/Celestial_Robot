"""
**file**: pi_node.py

**brief**: Host a CX model subscribed to a single cue topic.

This node hosts a CentralComplex model and allows an operator to run a
path integration experiment.

Start this node to start the CentralComplex.

Start node "teleop" to drive the robot manually to a target location, then press r to return.

Restart this node to reset the CentralComplex, i.e., set current location as CX_motor=0.

If you actually want to run path integration experiments then there
may be ways to streamline this process but as a proof of principle
this was sufficient.

"""
import argparse
import time

import numpy as np
from scipy.spatial.transform import Rotation

import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data
from nav_msgs.msg import Odometry
# from geometry_msgs.msg import Quaternion, Vector3
from std_msgs.msg import Int32MultiArray
from celeste_interfaces.msg import CueMsg, CxActivity
from celeste_interfaces.srv import Velocity
from celeste_navigation import cx_model
from sensor_msgs.msg import JointState

N_POL_OPS = 8


class PiNode(Node):
    cx_threshold = 10  # the threshold robot decide to turn
    timer_sec = 0.05  # the rate cx_motor is computed
    keep_turn_sec = 0.1  # every time turn for 0.1 seconds
    keep_move_sec = 1.5  # every move forward for at least 1.5 seconds
    cx_motor_amplifier = 10e6  #

    def __init__(self, args):
        super().__init__('pi_node')
        self.cx = cx_model.CentralComplex()
        self.vel_from_odom = 0.0
        self.yaw_from_odom = 0.0
        self.yaw_from_pol = 0.0
        self.vel_from_joint = 0.0
        self.pol_op_received = [0] * N_POL_OPS
        self.previous_cx_motor = 0.0
        self.keep_move_round = 0
        self.keep_turn_round = 0

        self.pub = self.create_publisher(CxActivity, 'cx_status', 10)
        self.cmd_vel_client = self.create_client(Velocity, 'update_velocity')
        self.create_subscription(CueMsg, 'pol_cue', self.cue_callback, qos_profile_sensor_data)
        self.create_subscription(Odometry, 'odom', self.odom_callback, qos_profile_sensor_data)
        self.create_subscription(JointState, 'joint_states', self.joint_callback, qos_profile_sensor_data)
        [
            self.create_subscription(Int32MultiArray,
                                     f'pol_op_{i}',
                                     self.create_pol_callback(i),
                                     qos_profile_sensor_data)
            for i in range(N_POL_OPS)
        ]

        self.create_timer(PiNode.timer_sec, self.timer_callback)
        self.get_logger().info('Running...')

    def timer_callback(self):
        """
        Called at a fix rate
        """
        # cx_motor = self.cx.unimodal_monolithic_CX(self.yaw_from_pol, self.vel_from_joint)
        cx_motor = self.cx.unimodal_monolithic_CX(self.yaw_from_odom, self.vel_from_joint)  # todo: use odom to test
        cx_status = self.cx.get_status()
        self.cx_status_publish(cx_status)
        self.commend_velocity_sharply(cx_motor)

        # cpu1_l = np.mean(self.cx.CPU1[:8] * np.exp(1j * np.linspace(0, 2*np.pi, 8, endpoint=False)))
        # cpu1_r = np.mean(self.cx.CPU1[8:] * np.exp(1j * np.linspace(0, 2*np.pi, 8, endpoint=False)))
        # self.get_logger().info(f"CPU1: L = {np.angle(cpu1_l, deg=True):.0f}:{abs(cpu1_l):.4f}, "
        #                        f"R = {np.angle(cpu1_r, deg=True):.0f}:{abs(cpu1_r):.4f}")
        # cpu4_l = np.mean(self.cx.CPU4[:8] * 10e6 * np.exp(1j * np.linspace(0, 2 * np.pi, 8, endpoint=False)))
        # cpu4_r = np.mean(self.cx.CPU4[8:] * 10e6 * np.exp(1j * np.linspace(0, 2 * np.pi, 8, endpoint=False)))
        # self.get_logger().info(f"CPU4: L = {np.angle(cpu4_l, deg=True):.0f}:{abs(cpu4_l):.4f}, "
        #                        f"R = {np.angle(cpu4_r, deg=True):.0f}:{abs(cpu4_r):.4f}")

    def commend_velocity_smoothly(self, cx_motor):
        """If CXMotor small enough, then allow forward movement,
        else set linear velocity to zero and turn on the spot.
        Threshold of CXMotor < 1 arbitrarily chosen.

        :param cx_motor: computed from CX model
        :return: None
        """
        angular = 0.7
        linear = 0.1

        request = Velocity.Request()
        cx_motor = cx_motor * PiNode.cx_motor_amplifier
        self.get_logger().info(f'CX_MOTOR:{cx_motor}')
        request.linear = linear * float(abs(cx_motor) < PiNode.cx_threshold)
        request.angular = angular * np.sign(cx_motor)

        self.cmd_vel_client.call_async(request)

    def commend_velocity_sharply(self, cx_motor):
        """
        Compared with commend_velocity_smoothly(), this function turns faster,
        but can only turn or move at one time, so robot can wait for sensors reading

        :param cx_motor: computed from CX model
        :return:
        """
        angular = 1.2
        linear = 0.1

        request = Velocity.Request(linear=0.0, angular=0.0)
        cx_motor = cx_motor * PiNode.cx_motor_amplifier
        self.get_logger().info(f'CX_MOTOR:{cx_motor}')
        if self.keep_move_round > 0 or self.keep_turn_round > 0:
            if self.keep_move_round > 0:
                self.keep_move_round -= 1
            elif self.keep_turn_round > 0:
                self.keep_turn_round -= 1
                if self.keep_turn_round == 0:
                    request = Velocity.Request(linear=0.0, angular=0.0)
                    self.cmd_vel_client.call_async(request)
                    self.reset_pol_received()
        elif np.sign(cx_motor)*np.sign(self.previous_cx_motor) != -1 and abs(cx_motor) > PiNode.cx_threshold:
            # Wait for all pols read before turn
            if all([received >= 1 for received in self.pol_op_received]):
                request.angular = angular * np.sign(cx_motor)
                self.cmd_vel_client.call_async(request)
                self.keep_turn_round = PiNode.keep_turn_sec / PiNode.timer_sec
        else:
            request.linear = linear
            self.cmd_vel_client.call_async(request)
            self.keep_move_round = PiNode.keep_move_sec / PiNode.timer_sec

        self.previous_cx_motor = cx_motor

    def create_pol_callback(self, index):
        def callback(msg):
            self.pol_op_received[index] += 1
        return callback

    def joint_callback(self, msg):
        self.vel_from_joint = (msg.velocity[0]+msg.velocity[1])/2

    def cue_callback(self, msg):
        self.yaw_from_pol = msg.theta

    def reset_pol_received(self):
        self.pol_op_received = [0] * N_POL_OPS

    def odom_callback(self, msg):
        self.vel_from_odom = msg.twist.twist.linear.x

        orientation = msg.pose.pose.orientation
        quat = [orientation.x, orientation.y, orientation.z, orientation.w]
        rot = Rotation.from_quat(quat)
        self.yaw_from_odom = rot.as_euler('xyz', degrees=False)[2]

    def cx_status_publish(self, status):
        msg = CxActivity()
        msg.tl2 = status[0]
        msg.cl1 = status[1]
        msg.tb1 = status[2]
        msg.cpu4 = status[3]
        msg.mem = status[4]
        msg.cpu1 = status[5]
        self.pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    # parser = argparse.ArgumentParser(description='PI Node Arguments')
    # parser.add_argument('-s', '--subscribe', default='pol_cue',
    #                     help='Set the subscription topic, '
    #                          'must be of type celeste_interfaces/msg/CueMsg')
    # parser.add_argument('-p', '--publish', default='cx_status',
    #                     help='Override the CX status publisher.')
    # args = parser.parse_args()
    pi_node = PiNode(args)
    rclpy.spin(pi_node)

    pi_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
