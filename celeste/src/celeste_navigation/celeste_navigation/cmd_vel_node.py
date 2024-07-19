import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from celeste_interfaces.srv import Velocity

BURGER_MAX_LIN_VEL = 0.22
BURGER_MAX_ANG_VEL = 2.84

class CmdVelService(Node):
    def __init__(self):
        super().__init__('cmd_vel_service')
        self.cmd_publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        self.cmd_service = self.create_service(Velocity, 'update_velocity', self.cmd_callback)

    def command_velocity(self, linear, angular):
        msg = Twist()
        msg.linear.x = linear
        msg.linear.y = 0.0
        msg.linear.z = 0.0

        msg.angular.x = 0.0
        msg.angular.y = 0.0
        msg.angular.z = angular

        self.cmd_publisher.publish(msg)

    def cmd_callback(self, request, response):
        angular = request.angular
        linear = request.linear
        self.get_logger().info(f'I heard: angular - {angular}, linear - {linear}')
        if abs(angular) > BURGER_MAX_ANG_VEL:
            response.success = False
            self.get_logger().warn(f'angular exceed limit ({BURGER_MAX_ANG_VEL})')
        elif abs(linear) > BURGER_MAX_LIN_VEL:
            self.get_logger().warn(f'linear exceed limit ({BURGER_MAX_LIN_VEL})')
            response.success = False
        else:
            self.command_velocity(request.linear, request.angular)
            response.success = True
        return response


def main(args=None):
    rclpy.init(args=args)
    node = CmdVelService()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
