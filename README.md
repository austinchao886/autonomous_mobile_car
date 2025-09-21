# MEAMR Autonomous Car (ROS2)

This repository contains the **ROS2 packages** for our autonomous car project.
The system integrates URDF-based robot description, drive model, navigation,
and custom exploration planners.

---

## 📂 Packages Overview

### 🔹 `meamr_description`
- Contains the **URDF/xacro files** that describe the robot’s geometry, sensors, and joints.
- Defines the robot model used by RViz, Gazebo, and Nav2.

### 🔹 `meamr_drive_model`
- Subscribes to `cmd_vel` (from the standard `geometry_msgs/Twist` topic).
- Extracts velocity information and sends it to the **MCU via UART**.
- Works together with the `transport_drivers` package for serial communication.
    - **Subscribes**: `/serial_read`
    - **Publishes**: `/serial_write` (⚠️ you must publish your velocity command here!)

### 🔹 `meamr_bringup`
- Launch files to start the robot system (URDF + drive model + nav stack).

### 🔹 `meamr_nav`
- Navigation stack integration (maps, configs, launch files for Nav2).

### 🔹 `rrtstar_planner`
- Custom **RRT\*** global planner for autonomous exploration and path planning.

### 🔹 `meamr_joystick`
- Joystick teleop support for manual driving and testing.

---

## 📦 External Dependencies

Some packages are not included in this repo because they are maintained externally.  
You need to **clone them separately** into your workspace:

- [rf2o_laser_odometry](https://github.com/MAPIRlab/rf2o_laser_odometry)  
  (Laser odometry for 2D LiDAR)

- [sllidar_ros2](https://github.com/Slamtec/sllidar_ros2)  
  (LiDAR driver for Slamtec RPLiDAR)

- [transport_drivers](https://github.com/ros-drivers/transport_drivers)  
  (ROS2 transport-layer protocol drivers, required for UART)

Clone them into your `src/` folder:
```bash
cd ~/my_ws/src
git clone https://github.com/MAPIRlab/rf2o_laser_odometry.git
git clone https://github.com/Slamtec/sllidar_ros2.git
git clone https://github.com/ros-drivers/transport_drivers.git
