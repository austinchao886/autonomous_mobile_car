cmake_minimum_required(VERSION 3.8)
project(meamr_drive_model)

# 編譯器警告設定
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 套件依賴
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2 REQUIRED)

# Include 路徑設定
include_directories(
  include
)

# 可執行檔設定
add_executable(meamr_base_node
  src/main.cpp
  src/meamr_base.cpp
  src/serial_interface.cpp
  src/dd_kinematic_model.cpp
)

# 相依套件與連結
ament_target_dependencies(meamr_base_node
  rclcpp
  std_msgs
  geometry_msgs
  nav_msgs
  tf2
)

# 安裝可執行檔
install(TARGETS meamr_base_node
  DESTINATION lib/${PROJECT_NAME}
)

# 安裝資料夾（如 launch/ config/）
install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME}
)


# 測試用 Lint
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# ament 尾端設定
ament_package()
