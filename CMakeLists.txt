cmake_minimum_required(VERSION 2.8.11)

project(t0r0_driving_gui)

add_compile_options(-fPIC)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(catkin REQUIRED COMPONENTS roscpp)
include_directories(${catkin_INCLUDE_DIRS})
include_directories(include ${catkin_INCLUDE_DIRS})

catkin_package()

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp src/window.h src/joystick.h src/joypad.h src/window.cpp src/joystick.cpp src/joypad.cpp src/def.cpp)

add_executable(driving_gui ${SOURCE_FILES})
target_link_libraries(driving_gui Qt5Core Qt5Widgets ${catkin_LIBRARIES})
