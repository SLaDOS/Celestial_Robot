from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='my_experiment',
            # namespace='',
            executable='return_action_server',
            name='return_action_server8848'
        ),
    ])
