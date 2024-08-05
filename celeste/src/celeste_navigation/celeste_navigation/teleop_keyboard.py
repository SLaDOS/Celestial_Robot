import os
import select
import sys
import time

import rclpy
from rclpy import Future
from rclpy.node import Node

from geometry_msgs.msg import Twist
from geometry_msgs.msg import Point
from rcl_interfaces.srv import SetParametersAtomically
from rclpy.qos import QoSProfile
from rclpy.parameter import Parameter
from nav_msgs.msg import Odometry


if os.name == 'nt':
    import msvcrt
else:
    import termios
    import tty

BURGER_MAX_LIN_VEL = 0.22
BURGER_MAX_ANG_VEL = 2.84

WAFFLE_MAX_LIN_VEL = 0.26
WAFFLE_MAX_ANG_VEL = 1.82

LIN_VEL_STEP_SIZE = 0.01
ANG_VEL_STEP_SIZE = 0.1

TURTLEBOT3_MODEL = os.environ['TURTLEBOT3_MODEL']

msg = """
Control Your TurtleBot3!
---------------------------
Moving around:
        w
   a    s    d
        x

w/x : increase/decrease linear velocity (Burger : ~ 0.22)
a/d : increase/decrease angular velocity (Burger : ~ 2.84)

space key, s : force stop

CTRL-C to quit
"""

e = """
Communications Failed
"""


def get_key(settings):
    if os.name == 'nt':
        return msvcrt.getch().decode('utf-8')
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''

    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key


def print_vels(target_linear_velocity, target_angular_velocity):
    print('currently:\tlinear velocity {0}\t angular velocity {1} '.format(
        target_linear_velocity, target_angular_velocity))


def make_simple_profile(current, target, step):
    if target > current:
        current = min(target, current + step)
    elif target < current:
        current = max(target, current - step)
    else:
        current = target

    return current


def constrain(input_vel, low_bound, high_bound):
    if input_vel < low_bound:
        input_vel = low_bound
    elif input_vel > high_bound:
        input_vel = high_bound
    else:
        input_vel = input_vel

    return input_vel


class Teleop(Node):
    def __init__(self):
        super().__init__('teleop_keyboard')
        self.odom_sub = self.create_subscription(Odometry, 'odom', self.odom_callback, 10)
        self.velocity_from_odom = 0
        self.pub = self.create_publisher(Twist, 'cmd_vel', 10)
        self.client = self.create_client(SetParametersAtomically, '/cmd_vel_service/set_parameters_atomically')
        self.request = SetParametersAtomically.Request()

    def odom_callback(self, msg):
        self.velocity_from_odom = msg.twist.twist.linear.x

    def send_parameter(self, para: bool):
        param = Parameter(name='CX_return', value=para)
        self.request.parameters = [param.to_parameter_msg()]
        self.client.call_async(self.request)
        self.get_logger().info(f'set CX_return {para}')


def check_linear_limit_velocity(velocity):
    return constrain(velocity, -BURGER_MAX_LIN_VEL, BURGER_MAX_LIN_VEL)


def check_angular_limit_velocity(velocity):
    return constrain(velocity, -BURGER_MAX_ANG_VEL, BURGER_MAX_ANG_VEL)


def main():
    settings = None
    if os.name != 'nt':
        settings = termios.tcgetattr(sys.stdin)

    rclpy.init()
    node = Teleop()

    status = 0
    target_linear_velocity = 0.0
    target_angular_velocity = 0.0
    twist = Twist()
    try:
        print(msg)
        while 1:
            # Wait for a key
            key = get_key(settings)
            if key == 'w':
                target_linear_velocity = \
                    check_linear_limit_velocity(target_linear_velocity + LIN_VEL_STEP_SIZE)
                status = status + 1
                print_vels(target_linear_velocity, target_angular_velocity)
                node.send_parameter(False)
            elif key == 'x':
                target_linear_velocity = \
                    check_linear_limit_velocity(target_linear_velocity - LIN_VEL_STEP_SIZE)
                status = status + 1
                print_vels(target_linear_velocity, target_angular_velocity)
                node.send_parameter(False)
            elif key == 'a':
                target_angular_velocity = \
                    check_angular_limit_velocity(target_angular_velocity + ANG_VEL_STEP_SIZE)
                status = status + 1
                print_vels(target_linear_velocity, target_angular_velocity)
                node.send_parameter(False)
            elif key == 'd':
                target_angular_velocity = \
                    check_angular_limit_velocity(target_angular_velocity - ANG_VEL_STEP_SIZE)
                status = status + 1
                print_vels(target_linear_velocity, target_angular_velocity)
                node.send_parameter(False)
            elif key == ' ' or key == 's':
                target_linear_velocity = 0.0
                target_angular_velocity = 0.0
                print_vels(target_linear_velocity, target_angular_velocity)
                node.send_parameter(False)
            elif key == 'r':
                node.send_parameter(True)
                continue
            elif key == '\x03':
                break

            if status == 50:
                print(msg)
                status = 0

            twist.linear.x = target_linear_velocity
            twist.linear.y = 0.0
            twist.linear.z = 0.0
            twist.angular.x = 0.0
            twist.angular.y = 0.0
            twist.angular.z = target_angular_velocity

            node.pub.publish(twist)
            rclpy.spin_once(node)
            # if node.velocity_from_odom != 0 and target_linear_velocity != 0:
            #     print(f'{abs(target_linear_velocity / node.velocity_from_odom):.2e}')

    except Exception as e:
        print(e)

    finally:
        twist = Twist()
        twist.linear.x = 0.0
        twist.linear.y = 0.0
        twist.linear.z = 0.0

        twist.angular.x = 0.0
        twist.angular.y = 0.0
        twist.angular.z = 0.0

        node.pub.publish(twist)

        if os.name != 'nt':
            termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)


if __name__ == '__main__':
    main()
