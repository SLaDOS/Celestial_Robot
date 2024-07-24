import time
import datetime
import math
import numpy as np
from scipy.spatial.transform import Rotation

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
import rosbag2_py
from rclpy.serialization import serialize_message

from std_msgs.msg import Int32MultiArray
from std_msgs.msg import Float64
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from turtlebot3_msgs.srv import Sound

POL_NUM = 8
TEST_NUM = 12
BAG_PATH = datetime.datetime.now().strftime('my_bags/test_%Y_%m_%d-%H_%M/')
BOOKEND = 3  # second(s)


def relu(x):
    """
    ReLU function. Clip negative values to zero.
    :param x: The value to clip
    :return: 0 if value < 0, otherwise the value.
    """
    return x * (x > 0)


def play_sound(key):
    sound_client = rclpy.create_node('speaker').create_client(Sound, 'sound')
    request = Sound.Request()
    request.value = key
    print("Sound playing...")
    sound_client.call_async(request)


class PolTester(Node):
    def __init__(self):
        super().__init__('multi_pol_op_tester')
        self.pol_data = [0.0] * POL_NUM
        self.pol_data_received = [False]*POL_NUM
        self.odom_data = None
        self.odom_data_received = False
        self.yaw = None
        qos_profile = QoSProfile(depth=10)
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

        # Initialize rosbag2 writer
        self.writer = rosbag2_py.SequentialWriter()
        storage_options = rosbag2_py.StorageOptions(
            uri=BAG_PATH + datetime.datetime.now().strftime('pol_op_tester_%Y_%m_%d-%H_%M_%S'),
            storage_id='sqlite3',
        )
        converter_options = rosbag2_py.ConverterOptions('cdr', 'cdr')
        self.writer.open(storage_options, converter_options)
        for subscription in self.pol_subscriptions:
            topic = rosbag2_py.TopicMetadata(name=subscription.topic,
                                             type='std_msgs/msg/Int32MultiArray',
                                             serialization_format='cdr')
            self.writer.create_topic(topic)
        topic = rosbag2_py.TopicMetadata(name='yaw',
                                         type='std_msgs/msg/Float64',
                                         serialization_format='cdr')
        self.writer.create_topic(topic)

    def write_all(self):
        for i in range(len(self.pol_subscriptions)):
            pol_msg = Int32MultiArray(data=self.pol_data[i])
            self.writer.write(
                self.pol_subscriptions[i].topic,
                serialize_message(pol_msg),
                self.get_clock().now().nanoseconds)
        yaw_msg = Float64(data=self.yaw)
        self.writer.write(
            'yaw',
            serialize_message(yaw_msg),
            self.get_clock().now().nanoseconds)

    def pol_sub_callback(self, msg, topic_num):
        self.pol_data[topic_num] = msg.data
        self.pol_data_received[topic_num] = True
        # print(f'{topic_num} heard')

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

    def bookend(self, t=BOOKEND):
        self.get_logger().info('<Bookend>')
        start_time = time.time()
        current_time = time.time()
        while rclpy.ok() and current_time - start_time < t:
            time.sleep(0.1)
            rclpy.spin_once(self)
            current_time = time.time()
            self.write_all()


def main(args=None):
    rclpy.init(args=args)
    play_sound(1)
    print('Test start')
    for i in range(TEST_NUM):
        print(f'{i+1} in {TEST_NUM}')
        node = PolTester()

        # Wait for sensor data
        node.get_logger().info("Awaiting pol/odom data. Start the sensor nodes.")
        while rclpy.ok() and not (node.odom_data_received and (sum(node.pol_data_received) >= POL_NUM)):
            rclpy.spin_once(node, timeout_sec=1)
        node.get_logger().info(f"Test{i+1} start. Moving to initial orientation...")

        # Move to start position
        if i == 0:
            start_yaw = node.yaw
        error_yaw = node.yaw - start_yaw
        start_time = time.time()

        while abs(error_yaw) > 0.011:
            rclpy.spin_once(node)
            # node.get_logger().info(str(error_yaw))
            cmd_angular = -0.3 * error_yaw
            cmd_angular = math.copysign(max(0.15, abs(cmd_angular)), cmd_angular)  # minimum speed
            node.command_velocity(0, cmd_angular)
            error_yaw = node.yaw - start_yaw
            # rate.sleep()  # blocks, maybe not use it
            if time.time() - start_time > 10:
                node.get_logger().info('Time exceeded')
                return

        node.command_velocity(0, 0)
        node.get_logger().info('Moved to initial orientation')

        # Pre-rotation wait, to have a time that it will be flat in the plot
        node.bookend()

        # Rotate
        node.get_logger().info('Start rotating...')
        corrected_yaw = node.yaw if node.yaw >= 0 else 2 * np.pi + node.yaw
        last_measure = corrected_yaw
        traverse = 0
        while rclpy.ok() and traverse <= 2*np.pi:
            process = int(traverse/(2*np.pi/50)) + 1
            print('\r['+process*'='+relu(50-process)*' '+']', end='')

            rclpy.spin_once(node)
            node.command_velocity(0, 0.3)
            time.sleep(0.5)
            node.command_velocity(0, 0)
            rclpy.spin_once(node)
            corrected_yaw = node.yaw if node.yaw >= 0 else 2 * np.pi + node.yaw
            traverse = traverse + relu(corrected_yaw - last_measure)
            last_measure = corrected_yaw
            node.pol_data_received = [False] * POL_NUM
            # Wait for all sensors read
            while sum(node.pol_data_received) < POL_NUM:
                rclpy.spin_once(node)
            else:
                node.write_all()
        else:
            print()
        node.command_velocity(0, 0)
        node.get_logger().info('Stop rotating')

        # Post rotation wait
        node.bookend()

        node.destroy_node()
    play_sound(0)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
