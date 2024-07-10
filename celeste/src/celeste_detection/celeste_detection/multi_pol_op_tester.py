import sys
import numpy as np

import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from nav_msgs.msg import Odometry
from rclpy.qos import QoSProfile


class PolTester(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')
        self.traverse = 0
        self.subscription = self.create_subscription(
            String,
            'topic',
            self.listener_callback,
            10)

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)


def main(args=None):
    rclpy.init(args=args)
    multi_pol_op_tester = PolTester()
    while rclpy.ok() and multi_pol_op_tester.traverse <= 2:

        rclpy.spin_once(multi_pol_op_tester)

    multi_pol_op_tester.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
