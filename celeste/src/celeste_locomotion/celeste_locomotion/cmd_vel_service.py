import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from celeste_interfaces.srv import Velocity

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
        self.get_logger().info(f'I heard: angular - {request.angular}, linear - {request.linear}')
        self.command_velocity(request.linear, request.angular)
        return response

def main(args=None):
    rclpy.init(args=args)
    node = CmdVelService()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
