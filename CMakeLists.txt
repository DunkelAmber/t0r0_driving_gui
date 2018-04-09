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
find_package(Qt5Gui REQUIRED)
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Gui_INCLUDE_DIRS})

set(HEADER_FILES src/window.h src/joystick.h src/joypad.h src/startbutton.h src/imagebutton.h src/batteryindicator.h src/rovershow.h)
set(SOURCE_FILES src/main.cpp  src/window.cpp src/joystick.cpp src/joypad.cpp src/startbutton.cpp src/imagebutton.cpp src/batteryindicator.cpp src/rovershow.cpp  src/def.cpp)

add_executable(driving_gui ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(driving_gui Qt5Core Qt5Widgets Qt5Gui ${catkin_LIBRARIES})
