"""
**file**: pi_node.py

**brief**: Host a CX model subscribed to a single cue topic.

This node hosts a CentralComplex model and allows an operator to run a
path integration experiment.

Start this node (make sure the cmd_vel_service is not running) to start
the CentralComplex. Drive the robot manually (using turtlebot3_teleop_key
or any other suitable method) to a target location. Stop teleoperation.
Start the cmd_vel_node to allow this node to communicate
with the motors on the turtlebot. The robot will then home.

If you actually want to run path integration experiments then there
may be ways to streamline this process but as a proof of principle
this was sufficient.

"""
import argparse
import numpy as np
from scipy.spatial.transform import Rotation

import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, Vector3
from std_msgs.msg import String
from celeste_interfaces.msg import CueMsg, CxActivity
from celeste_interfaces.srv import Velocity
from celeste_navigation import cx_model
from sensor_msgs.msg import JointState



class PiNode(Node):
    def __init__(self, args):
        super().__init__('pi_node')
        self.cx = cx_model.CentralComplex()
        self.vel_from_odom = 0.0
        self.yaw_from_odom = 0.0
        self.vel_from_joint = 0.0
        self.pub = self.create_publisher(CxActivity, 'cx_status', 10)
        self.client = self.create_client(Velocity, 'update_velocity')

        self.create_subscription(CueMsg, 'pol_cue', self.cue_callback, 10)
        self.create_subscription(Odometry, 'odom', self.odom_callback, 10)
        self.create_subscription(JointState, 'joint_states', self.joint_callback, 10)

        self.get_logger().info('Running...')

    def joint_callback(self, msg):
        self.vel_from_joint = (msg.velocity[0]+msg.velocity[1])/2

    def cue_callback(self, msg):
        self.get_logger().info(f'Cue info: (R: {msg.contrast}, T: {msg.theta})')

        current_angle = msg.theta
        CXMotor = self.cx.unimodal_monolithic_CX(current_angle, self.vel_from_odom)
        cx_status = self.cx.get_status()
        self.cx_status_publish(cx_status)

        self.get_logger().info(f'CX_MOTOR:{CXMotor}')

        # If CXMotor small enough, then allow forward movement,
        # else set linear velocity to zero and turn on the spot.
        # Threshold of CXMotor < 1 arbitrarily chosen.

        angular = 0.7
        linear = 0.1

        # TODO: Stop (about 1s) and wait for sensor reading
        request = Velocity.Request()
        request.linear = linear if abs(CXMotor) < 1.0 else 0.0
        if CXMotor != 0.0:
            request.angular = angular if CXMotor > 0.0 else -angular
        else:
            request.angular = 0.0

        self.client.call_async(request)

    def odom_callback(self, msg):
        self.vel_from_odom = msg.twist.twist.linear.x

        orientation = msg.pose.pose.orientation
        quat = [orientation.x, orientation.y, orientation.z, orientation.w]
        rot = Rotation.from_quat(quat)
        self.yaw_from_odom = rot.as_euler('xyz', degrees=False)[2]

        # TODO:use odom to test
        angular = 0.7
        linear = 0.1
        CXMotor = self.cx.unimodal_monolithic_CX(self.yaw_from_odom, self.vel_from_joint)
        cx_status = self.cx.get_status()
        self.cx_status_publish(cx_status)
        self.get_logger().info(f'CX_MOTOR:{CXMotor}')
        request = Velocity.Request()
        request.linear = linear * float(abs(CXMotor) < 1.0)
        request.angular = angular * np.sign(CXMotor)
        self.client.call_async(request)
        # TODO: end

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
