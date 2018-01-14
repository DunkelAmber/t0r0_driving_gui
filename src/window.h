#ifndef WINDOW_H
#define WINDOW_H

#include "joystick.h"
#include "joypad.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QString>

#include <ros/ros.h>
#include <std_msgs/UInt8MultiArray.h>

class Window : public QWidget
{
	Q_OBJECT

	public:
		explicit Window(QWidget *parent = 0);

	private:
		// Subwindows
        Joystick *joystick_emulator;
        Joypad *joypad_emulator;

        // Window elements
        QGridLayout *main_layout;
        QVBoxLayout *joystick_layout, *joypad_layout;

        QGroupBox *joystick_box, *joypad_box;

        QPushButton *disp_joystick, *disp_joypad;
        QLabel *joystick_data, *joypad_data;

        // ROS
        ros::Subscriber joystick_subscriber;
        ros::Subscriber joypad_subscriber;

        // Methods
        void joystickCallback(const std_msgs::UInt8MultiArray::ConstPtr& msg);
        void joypadCallback(const std_msgs::UInt8MultiArray::ConstPtr& msg);

    public slots:
        void showJoystick();
        void showJoypad();
};

#endif // WINDOW_H
