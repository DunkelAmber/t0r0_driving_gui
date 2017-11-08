#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <vector>

#include <QWidget>
#include <QtCore>
#include <QSlider>

#include <ros/ros.h>
#include <std_msgs/UInt8MultiArray.h>

#include "def.cpp"

class Joystick : public QWidget
{
	Q_OBJECT

	public:
		explicit Joystick(QWidget *parent = 0);

	private:
        QSlider *x, *y, *z;
        std::vector<uint8_t> arm_pose;
        std_msgs::UInt8MultiArray arm_pose_msg;

    public slots:
        void resetSlider();

        void xSliderMoved();
        void ySliderMoved();
        void zSliderMoved();

};

#endif
