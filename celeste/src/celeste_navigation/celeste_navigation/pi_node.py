"""
**WARNING**: If the cmd_vel_node is running then starting
this node will cause the robot to move!

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
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, Vector3
from std_msgs.msg import String
from celeste_interfaces.msg import CueMsg, CxActivity
from celeste_interfaces.srv import Velocity
import argparse
import numpy as np
import cx_model


class PiNode(Node):
    def __init__(self, args):
        super().__init__('pi_node')
        self.cx = cx_model.CentralComplex()
        self.velocity = 0.0
        self.pub = self.create_publisher(CxActivity, args.publish_topic, 10)
        self.client = self.create_client(Velocity, 'update_velocity')

        self.create_subscription(CueMsg, args.subscribe_topic, self.cue_callback, 10)
        self.create_subscription(Odometry, 'odom', self.odom_callback, 10)

        self.get_logger().info('Running...')

    def cue_callback(self, msg):
        self.get_logger().info(f'Cue info: (R: {msg.contrast}, T: {msg.theta})')

        current_angle = msg.theta
        CXMotor = self.cx.unimodal_monolithic_CX(current_angle, self.velocity)

        cx_status = self.cx.get_status()
        self.cx_status_publish(cx_status)

        self.get_logger().debug(f'CX_MOTOR:{CXMotor}')

        # If CXMotor small enough, then allow forward movement,
        # else set linear velocity to zero and turn on the spot.
        # Threshold of CXMotor < 1 arbitrarily chosen.

        angular = 0.7
        linear = 0.1

        request = Velocity.Request()
        request.linear = linear if abs(CXMotor) < 1 else 0
        if CXMotor != 0:
            request.angular = angular if CXMotor > 0 else -angular
        else:
            request.angular = 0

        self.client.call_async(request)

    def odom_callback(self, msg):
        self.velocity = msg.twist.twist.linear.x

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

    parser = argparse.ArgumentParser(description='PI Node Arguments')
    parser.add_argument('-s', '--subscribe', default='pol_cue',
                        help='Set the subscription topic, '
                             'must be of type celeste_interfaces/msg/CueMsg')
    parser.add_argument('-p', '--publish', default='cx_status',
                        help='Override the CX status publisher.')
    parser.parse_args(['-h'])

    args, unknown = parser.parse_known_args()

    pi_node = PiNode(args)
    rclpy.spin(pi_node)

    pi_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
