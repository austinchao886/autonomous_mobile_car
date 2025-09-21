#include "meamr_joystick/joystick_extra_node.hpp"

namespace meamr_joystick
{

JoystickExtraNode::JoystickExtraNode(const rclcpp::NodeOptions & options)
: Node("joystick_extra_node", options), last_r1_state_(false)
{
  joy_sub_ = this->create_subscription<sensor_msgs::msg::Joy>(
    "/joy", 10, std::bind(&JoystickExtraNode::joyCallback, this, std::placeholders::_1));

  clamping_pub_ = this->create_publisher<std_msgs::msg::Bool>("/clamping", 10);

  RCLCPP_INFO(this->get_logger(), "JoystickExtraNode started.");
}

void JoystickExtraNode::joyCallback(const sensor_msgs::msg::Joy::SharedPtr msg)
{
  if (msg->buttons.size() <= 5) return;

  bool r1_pressed = msg->buttons[5];

  if (r1_pressed != last_r1_state_) {
    std_msgs::msg::Bool output;
    output.data = r1_pressed;
    clamping_pub_->publish(output);

    // if (r1_pressed) {
    //   RCLCPP_INFO(this->get_logger(), "R1 pressed → Published /clamping: true");
    // } else {
    //   RCLCPP_INFO(this->get_logger(), "R1 released → Published /clamping: false");
    // }
  }

  last_r1_state_ = r1_pressed;
}


}  // namespace meamr_joystick
