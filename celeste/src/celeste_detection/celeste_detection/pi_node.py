import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, Vector3
from std_msgs.msg import String
from celeste_interfaces.msg import CueMsg, CxActivity  # Adjust imports based on actual package structure
from celeste_interfaces.srv import Velocity  # Adjust imports based on actual package structure
import argparse
import numpy as np
import cx_model


def clean_velocity(lin_vel, factor=100):
    if factor == 0:
        return 0
    return ((lin_vel * factor) // 1) / factor


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

        cx_status = []
        self.cx.get_status(cx_status)
        self.cx_status_publish(cx_status)

        angular = 0.7
        linear = 0.1

        request = Velocity.Request()
        request.linear = linear if abs(CXMotor) < 1 else 0
        request.angular = angular if CXMotor > 0 else -angular if CXMotor != 0 else 0

        self.client.call_async(request)

    def odom_callback(self, msg):
        linear_velocity = clean_velocity(msg.twist.twist.linear.x)
        self.velocity = linear_velocity

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
    parser.add_argument('-s', '--subscribe_topic', type=str, required=True,
                        help='Set the subscription topic, must be of type bb_util/cue_msg')
    parser.add_argument('-p', '--publish_topic', type=str, default='cx_status',
                        help='Override the CX status publisher.')

    args, unknown = parser.parse_known_args()

    pi_node = PiNode(args)

    rclpy.spin(pi_node)

    pi_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
