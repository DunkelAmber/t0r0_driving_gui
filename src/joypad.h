#ifndef JOYPAD_H
#define JOYPAD_H

#include <vector>

#include <QWidget>
#include <QtCore>
#include <QSlider>
#include <QTimer>

#include <ros/ros.h>
#include <std_msgs/UInt8MultiArray.h>

#include "def.cpp"

class Joypad : public QWidget
{
	Q_OBJECT

	public:
		explicit Joypad(QWidget *parent = 0);

	private:
        QSlider *dx, *sx, *all;
        QTimer *ros_timer;

        std::vector<uint8_t> joypad_cmds;
        std_msgs::UInt8MultiArray joypad_msg;
        ros::Publisher joypad_topic;

    public slots:
        void resetSlider();

        void sxSliderMoved();
        void dxSliderMoved();
        void allSliderMoved();

        void rosLoop();
};

#endif
