cmake_minimum_required(VERSION 2.8.3)
project(t0r0_driving_gui)

find_package(catkin REQUIRED COMPONENTS roscpp)
include_directories(${catkin_INCLUDE_DIRS})
include_directories(include ${catkin_INCLUDE_DIRS})
catkin_package()

find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
include(${QT_USE_FILE})

qt4_wrap_cpp(MOC_FILES src/window.h src/joystick.h src/joypad.h)

set(SOURCE_FILES src/main.cpp src/window.cpp src/joystick.cpp src/joypad.cpp src/def.cpp ${MOC_FILES})

add_executable(driving_gui ${SOURCE_FILES})
target_link_libraries(driving_gui ${QT_LIBRARIES} ${catkin_LIBRARIES})
