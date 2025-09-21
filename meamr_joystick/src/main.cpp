#include "meamr_joystick/joystick_extra_node.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<meamr_joystick::JoystickExtraNode>());
  rclcpp::shutdown();
  return 0;
}
