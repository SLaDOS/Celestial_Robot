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
        '''TODO
        sequence = [0, 1]

        for i in range(1, goal_handle.request.order):
            sequence.append(sequence[i] + sequence[i-1])

        goal_handle.succeed()

        result = Return.Result()
        result.sequence = sequence'''

        return result


def main(args=None):
    rclpy.init(args=args)

    return_action_server = ReturnActionServer()

    rclpy.spin(return_action_server)


if __name__ == '__main__':
    main()
