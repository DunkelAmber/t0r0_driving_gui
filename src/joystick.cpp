#include "joystick.h"

// Constructor
Joystick::Joystick(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Joystick Emulator");

    int argc = 0;
    char *argv[1];

    ros::init(argc, argv, "joystick_emulator");
    ros::NodeHandle nh;
    joystick_topic = nh.advertise<std_msgs::UInt8MultiArray>("joystick", 1);
    joystick_subscriber = nh.subscribe("/joystick", 1, &Joystick::joystickCallback, this);

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

    ros_timer = new QTimer(this);
    ros_timer->setInterval(100);
    ros_timer->setSingleShot(false);

    connect(x, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));
    connect(y, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));
    connect(z, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));

    connect(x, SIGNAL(valueChanged(int)), this, SLOT(xSliderMoved()));
    connect(y, SIGNAL(valueChanged(int)), this, SLOT(ySliderMoved()));
    connect(z, SIGNAL(valueChanged(int)), this, SLOT(zSliderMoved()));

    connect(ros_timer, SIGNAL(timeout()), this, SLOT(rosLoop()));

    ros_timer->start();
}

void Joystick::closeEvent(QCloseEvent *event)
{
    ros_timer->stop();
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

void Joystick::rosLoop()
{
    joystick_cmds.clear();
    joystick_cmds.push_back(x->value());
    joystick_cmds.push_back(y->value());
    joystick_cmds.push_back(z->value());
    joystick_cmds.push_back(AXES_ZERO);
    joystick_cmds.push_back(AXES_ZERO);
    joystick_cmds.push_back(AXES_ZERO);
    joystick_cmds.push_back(AXES_ZERO);

    joystick_msg.data = joystick_cmds;
    joystick_topic.publish(joystick_msg);

    ros::spinOnce();
}

void Joystick::joystickCallback(const std_msgs::UInt8MultiArray::ConstPtr& msg)
{
    QString data;

    data  = QString::number(msg->data[0]) + " ";
    data += QString::number(msg->data[1]) + " ";
    data += QString::number(msg->data[2]) + " ";
    data += QString::number(msg->data[3]) + " ";
    data += QString::number(msg->data[4]) + " ";
    data += QString::number(msg->data[5]) + " ";
    data += QString::number(msg->data[6]) + " ";
}
