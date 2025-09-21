#include "rclcpp/rclcpp.hpp"
#include "meamr_drive_model/meamr_base.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto serial_interface = std::make_shared<SerialInterface>();
    auto meamr_base = std::make_shared<MeamrBase>(serial_interface);

    if (meamr_base->Init() != 0)
    {
        RCLCPP_ERROR(meamr_base->get_logger(), "Failed to initialize MeamrBase.");
        return 1;
    }

    auto executor = std::make_shared<rclcpp::executors::MultiThreadedExecutor>();
    executor->add_node(meamr_base);
    executor->add_node(serial_interface);

    executor->spin();

    rclcpp::shutdown();
    return 0;
}
