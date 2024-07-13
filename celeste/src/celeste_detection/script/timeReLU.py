import rclpy

if __name__ == '__main__':
    node = rclpy.create_node("rospy_rate_test")
    rate = node.create_rate(5)  # ROS Rate at 5Hz

    while not rclpy.ok():
        node.get_logger().info("Hello")
        rate.sleep()
