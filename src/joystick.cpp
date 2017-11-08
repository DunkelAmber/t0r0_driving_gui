#include "joystick.h"

// Constructor
Joystick::Joystick(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Joystick Emulator");

    ros::init(int argc, char **argv, "joystick_emulator");
    ros::NodeHandle joystick_emulator_nh;
    ros::Publisher arm_pose_topic = joystick_emulator_nh.advertise<std_msgs::UInt8MultiArray>("arm_pose", 1);

    ros::Rate loop_rate(LOOP_RATE);

    x = new QSlider(this);
    x->setGeometry(30, 10, 20, 200);
    x->setOrientation(Qt::Vertical);
    x->setRange(AXES_MIN, AXES_MAX);
    x->setValue(AXES_ZERO);

    y = new QSlider(this);
    y->setGeometry(10, 220, 200, 20);
    y->setOrientation(Qt::Horizontal);
    y->setRange(AXES_MIN, AXES_MAX);
    y->setValue(AXES_ZERO);

    z = new QSlider(this);
    z->setGeometry(160, 10, 20, 200);
    z->setOrientation(Qt::Vertical);
    z->setRange(AXES_MIN, AXES_MAX);
    z->setValue(AXES_ZERO);

    connect(x, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));
    connect(y, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));
    connect(z, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));

    connect(x, SIGNAL(valueChanged(int)), this, SLOT(xSliderMoved()));
    connect(y, SIGNAL(valueChanged(int)), this, SLOT(ySliderMoved()));
    connect(z, SIGNAL(valueChanged(int)), this, SLOT(zSliderMoved()));

    while(ros::ok())
    {
        arm_pose.clear();
        arm_pose.push_back(x->value());
        arm_pose.push_back(y->value());
        arm_pose.push_back(z->value());
        arm_pose.push_back(AXES_ZERO);
        arm_pose.push_back(AXES_ZERO);
        arm_pose.push_back(AXES_ZERO);
        arm_pose.push_back(AXES_ZERO);

        arm_pose_msg.data = arm_pose;
        arm_pose_topic.publish(arm_pose_msg);

        loop_rate.sleep();
        ros::spinOnce();
    }
}

void Joystick::resetSlider()
{
    x->setValue(AXES_ZERO);
    y->setValue(AXES_ZERO);
    z->setValue(AXES_ZERO);
}

void Joystick::xSliderMoved()
{

}

void Joystick::ySliderMoved()
{

}

void Joystick::zSliderMoved()
{

}
