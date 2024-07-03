import time
import numpy as np

import rclpy
from rclpy.executors import MultiThreadedExecutor
from rclpy.action import ActionServer
from rclpy.node import Node
from rclpy.qos import QoSProfile

from celeste_interfaces.action import Return
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

BURGER_MAX_LIN_VEL = 0.22
BURGER_MAX_ANG_VEL = 1.0
TURN_SPEED_COEFFICIENT = 0.06
MIN_TURN_SPEED = 0.1
# BURGER_MAX_ANG_VEL = 2.84


def constrain(input_vel, low_bound, high_bound):
    if input_vel < low_bound:
        input_vel = low_bound
    elif input_vel > high_bound:
        input_vel = high_bound
    else:
        input_vel = input_vel
    return input_vel


def check_linear_limit_velocity(velocity):
    return constrain(velocity, -BURGER_MAX_LIN_VEL, BURGER_MAX_LIN_VEL)


def check_angular_limit_velocity(velocity):
    return constrain(velocity, -BURGER_MAX_ANG_VEL, BURGER_MAX_ANG_VEL)


class ReturnActionServer(Node):

    def __init__(self):
        super().__init__('return_action_server')

        self.target_position = (0, 0)
        self.action_server = ActionServer(
            self,
            Return,
            'return',
            self.execute_callback)
        self.vel_publisher = self.create_publisher(Twist, 'cmd_vel', QoSProfile(depth=10))
        self.odom_subscriber = self.create_subscription(Odometry,
                                                        'odom',
                                                        callback=self.odom_subscriber,
                                                        qos_profile = QoSProfile(depth=10))
        self.action_count = 0

    def odom_subscriber(self, msg):
        self.orientation = msg.pose.pose.orientation
        self.position = msg.pose.pose.position

    def execute_callback(self, goal_handle):
        start = time.time()
        self.get_logger().info('Rotating...')
        feedback_msg = Return.Feedback()
        result = Return.Result()

        vector_to_target = (self.target_position[0] - self.position.x, self.target_position[1] - self.position.y)

        twist = Twist()
        twist.linear.x = 0.0
        twist.linear.y = 0.0
        twist.linear.z = 0.0
        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = 0.0

        while 1:
            angle = self.angle_to_go(vector_to_target)
            current = twist.angular.z
            control = check_angular_limit_velocity(TURN_SPEED_COEFFICIENT * angle)
            if MIN_TURN_SPEED > control > 0:
                control = MIN_TURN_SPEED
            elif -MIN_TURN_SPEED < control < 0:
                control = - MIN_TURN_SPEED
            if (control-current) > 0.01:
                control = current + 0.01
            elif (control-current) < -0.01:
                control = current - 0.01

            if abs(angle) < 0.5:
                self.get_logger().info('Success')
                result.success = True
                break
            twist.angular.z = control
            self.get_logger().info(f'{angle:.1f} degrees to go, angular velocity: {control:.2f},current:{current:.2f}')
            self.vel_publisher.publish(twist)
            feedback_msg.remaining = angle
            goal_handle.publish_feedback(feedback_msg)
            if time.time()-start > 5:
                self.get_logger().info('Failed')
                result.success = False
                break

        goal_handle.succeed()
        twist.angular.z = 0.0
        self.vel_publisher.publish(twist)

        return result

    def angle_to_go(self, target_vector):
        z = self.orientation.z
        w = self.orientation.w
        theta = 2 * np.arctan2(z, w)
        current_heading = (np.cos(theta), np.sin(theta))

        dot_product = np.dot(current_heading, target_vector)
        current_heading_magnitude = np.linalg.norm(current_heading)
        target_vector_magnitude = np.linalg.norm(target_vector)
        cos_angle = dot_product / (current_heading_magnitude * target_vector_magnitude)
        cos_angle = np.clip(cos_angle, -1.0, 1.0)
        angle = np.arccos(cos_angle)
        cross_product = current_heading[0] * target_vector[1] - current_heading[1] * target_vector[0]
        if cross_product < 0:
            angle = -angle
        angle_degrees = np.degrees(angle)

        return angle_degrees


def main(args=None):

    rclpy.init(args=args)
    return_action_server = ReturnActionServer()

    executor = MultiThreadedExecutor()
    executor.add_node(return_action_server)
    executor.spin()


if __name__ == '__main__':
    main()
