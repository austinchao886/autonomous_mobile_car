import os

from launch_ros.actions import Node
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():    
    config_file_teleop = os.path.join(
        get_package_share_directory('meamr_joystick'),
        'config',
        'js_params.yaml'
    )
    
    print("Configuration file path: ", config_file_teleop)
    
    teleop_node = Node(
        package='teleop_twist_joy',
        executable='teleop_node',
        name='meamr_joystick_node',
        output='screen',
        parameters=[ config_file_teleop ],
        remappings=[
            ('/cmd_vel', '/cmd_vel_joy')],
    )
    
    joy_node = Node(
        package='joy',
        executable='joy_node',
        name='joy_node',
        output='screen',
        parameters=[{'deadzone': 0.15, 'autorepeat_rate': 20.0}]
    )

    # Custom jot functionality node
    extra_node = Node(
        package='meamr_joystick',
        executable='joystick_extra_node',
        name='joystick_extra_node',
        output='screen'
    )

    return LaunchDescription([teleop_node, joy_node, extra_node])
