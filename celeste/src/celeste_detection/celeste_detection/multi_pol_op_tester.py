import sys
import time

import numpy as np
import argparse
from scipy.spatial.transform import Rotation

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile

from std_msgs.msg import String
from std_msgs.msg import Int32MultiArray
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry

POL_NUM = 8


class PolTester(Node):
    def __init__(self):
        super().__init__('multi_pol_op_tester')
        self.traverse = 0
        self.pol_data = [0.0] * POL_NUM
        self.pol_data_received = True  # Fixme
        self.odom_data = None
        self.odom_data_received = False
        self.yaw = None
        qos_profile = QoSProfile(depth=10)  # TODO: Why 1000
        self.vel_publisher = self.create_publisher(Twist, 'cmd_vel', qos_profile)
        self.pol_subscriptions = [self.create_subscription(msg_type=Int32MultiArray,
                                                           topic='pol_op_' + str(i),

                                                           callback=
                                                           lambda msg, topic_num=i:
                                                           self.pol_sub_callback(msg, topic_num),

                                                           qos_profile=qos_profile
                                                           )
                                  for i in range(POL_NUM)]
        self.odom_subscription = self.create_subscription(Odometry, 'odom', self.odom_sub_callback, qos_profile)

    def pol_sub_callback(self, msg, topic_num):
        self.pol_data[topic_num] = msg.data

    def odom_sub_callback(self, msg):
        self.odom_data_received = True
        self.odom_data = msg
        orientation = msg.pose.pose.orientation
        quat = [orientation.x, orientation.y, orientation.z, orientation.w]
        rot = Rotation.from_quat(quat)
        self.yaw = rot.as_euler('xyz', degrees=False)[2]

    def command_velocity(self, linear: float, angular: float):
        twist = Twist()

        twist.linear.x = float(linear)
        twist.linear.y = 0.0
        twist.linear.z = 0.0

        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = float(angular)

        self.vel_publisher.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    node = PolTester()

    # Wait for sensor data
    while rclpy.ok() and not (node.odom_data_received and node.pol_data_received):
        rclpy.spin_once(node)
        node.get_logger().info("Awaiting pol/odom data. Start the sensor nodes.")
        time.sleep(1)

    # Move to zero on odometry
    goal_yaw = 0
    error_yaw = node.yaw - goal_yaw
    rate = node.create_rate(100)
    start_time = time.time()

    while abs(error_yaw) > 0.011:  # TODO: Why 0.011
        rclpy.spin_once(node)
        node.get_logger().info(str(error_yaw))
        node.command_velocity(0, -0.3 * error_yaw)
        error_yaw = node.yaw - goal_yaw
        # rate.sleep()  # fixme: blocks
        if time.time() - start_time > 10:
            node.get_logger().info('Time exceeded')
            break

    node.command_velocity(0, 0)
    node.get_logger().info('Moved to zero on odometry')
    rate.destroy()

    # TODO: continue
    # while rclpy.ok() and node.traverse <= 2 * np.pi:
    #     rclpy.spin_once(node)
    #     node.get_logger().info("Awaiting pol/odom data. Start the sensor nodes.")

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
