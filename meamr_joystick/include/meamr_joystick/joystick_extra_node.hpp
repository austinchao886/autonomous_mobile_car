#ifndef MEAMR_JOYSTICK_EXTRA_NODE_HPP
#define MEAMR_JOYSTICK_EXTRA_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "std_msgs/msg/bool.hpp"

namespace meamr_joystick
{

class JoystickExtraNode : public rclcpp::Node
{
public:
  explicit JoystickExtraNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

private:
  void joyCallback(const sensor_msgs::msg::Joy::SharedPtr msg);
  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub_;
  rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr clamping_pub_;

  bool last_r1_state_;
};

}  // namespace meamr_joystick

#endif  // MEAMR_JOYSTICK_EXTRA_NODE_HPP
