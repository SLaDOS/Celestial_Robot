from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='celeste_navigation',
            output='screen',
            executable='cmd_vel',
            # name='cmd_vel',
        ),
        Node(
            package='celeste_navigation',
            output='screen',
            executable='pi_imu',
        ),
        Node(
            package='celeste_navigation',
            output='screen',
            executable='pol_cue_detector',
        ),

    ])
