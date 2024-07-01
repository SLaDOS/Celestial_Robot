import statistics
import rclpy
import numpy as np


from nav_msgs.msg import Odometry
from rclpy.qos import QoSProfile


x_last_ten = []


def quaternion_to_heading_vector(q):
    z = q.z
    w = q.w
    # Extract the angle theta from the quaternion
    theta = 2 * np.arctan2(z, w)

    # Compute the heading vector
    heading_vector = (np.cos(theta), np.sin(theta))

    return heading_vector


def angle_to_target(current_heading, target_vector):
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


def get_average_x(msg):
    global x_last_ten
    x_last_ten.append(msg.twist.twist.linear.x)
    if len(x_last_ten) > 10:
        x_mean = statistics.mean(x_last_ten)
        print(f'{x_mean:.15f}')
        x_last_ten = []


def listener_callback(msg):
    quaternion = msg.pose.pose.orientation
    target_vector = (0.0, 1.0)
    target_vector_normalized = target_vector / np.linalg.norm(target_vector)
    current_heading = quaternion_to_heading_vector(quaternion)
    angle_to_turn = angle_to_target(current_heading, target_vector_normalized)
    print(f'{angle_to_turn:.1f}')


def main(args=None):
    rclpy.init(args=args)
    node = rclpy.create_node('inspector')
    pub = node.create_subscription(Odometry, 'odom', callback=listener_callback, qos_profile=QoSProfile(depth=10))

    rclpy.spin(node)


if __name__ == '__main__':
    main()
