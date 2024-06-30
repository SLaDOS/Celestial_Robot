import time

import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from rclpy.qos import QoSProfile

from celeste_interfaces.action import Return
from geometry_msgs.msg import Twist


class ReturnActionServer(Node):

    def __init__(self):
        super().__init__('return_action_server')
        self._action_server = ActionServer(
            self,
            Return,
            'return',
            self.execute_callback)
        self._publisher = self.create_publisher(Twist, 'cmd_vel', QoSProfile(depth=10))
        self._count = 0

    def execute_callback(self, goal_handle):
        self._count += 1
        self.get_logger().info(f'Count: {self._count}')
        self.get_logger().info('Returning...')

        twist = Twist()
        twist.linear.x = 0.0
        twist.linear.y = 0.0
        twist.linear.z = 0.0
        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = 1.0
        self._publisher.publish(twist)
        self.get_logger().info('Waiting...')
        time.sleep(1)
        twist.linear.x = 0.0
        twist.linear.y = 0.0
        twist.linear.z = 0.0
        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = 0.0
        self.get_logger().info('Stop')
        self._publisher.publish(twist)

        goal_handle.succeed()
        result = Return.Result()
        result.success = False
        return result


def main(args=None):
    qos = QoSProfile(depth=10)

    rclpy.init(args=args)

    return_action_server = ReturnActionServer()

    rclpy.spin(return_action_server)


if __name__ == '__main__':
    main()
