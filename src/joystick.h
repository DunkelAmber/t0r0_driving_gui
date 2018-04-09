#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <vector>

#include <QWidget>
#include <QtCore>
#include <QSlider>
#include <QTimer>

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
    QTimer *ros_timer;

    std::vector<uint8_t> joystick_cmds;
    std_msgs::UInt8MultiArray joystick_msg;
    ros::Publisher joystick_topic;
    ros::Subscriber joystick_subscriber;

    void closeEvent(QCloseEvent *event);
    void joystickCallback(const std_msgs::UInt8MultiArray::ConstPtr& msg);

private slots:
    void resetSlider();
    void xSliderMoved();
    void ySliderMoved();
    void zSliderMoved();

    void rosLoop();

};

#endif
