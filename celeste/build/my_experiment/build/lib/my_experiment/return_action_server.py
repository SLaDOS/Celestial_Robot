import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node

from celeste_interfaces.action import Return


class ReturnActionServer(Node):

    def __init__(self):
        super().__init__('return_action_server')
        self._action_server = ActionServer(
            self,
            Return,
            'return',
            self.execute_callback)

    def execute_callback(self, goal_handle):
        self.get_logger().info('Returning...')
        goal_handle.succeed()
        result = Return.Result()
        return result


def main(args=None):
    rclpy.init(args=args)

    return_action_server = ReturnActionServer()

    rclpy.spin(return_action_server)


if __name__ == '__main__':
    main()
