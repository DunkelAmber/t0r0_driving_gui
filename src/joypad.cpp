#include "joypad.h"

// Constructor
Joypad::Joypad(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Joypad Emulator");

    int argc = 0;
    char *argv[1];

    ros::init(argc, argv, "joypad_emulator");
    ros::NodeHandle joypad_emulator_nh;
    joypad_topic = joypad_emulator_nh.advertise<std_msgs::UInt8MultiArray>("joypad", 1);

    sx = new QSlider(this);
    sx->setOrientation(Qt::Vertical);
    sx->setGeometry(20, 20, 30, 200);
    sx->setRange(AXES_MIN, AXES_MAX);
    sx->setValue(AXES_ZERO);

    dx = new QSlider(this);
    dx->setOrientation(Qt::Vertical);
    dx->setGeometry(110, 20, 30, 200);
    dx->setRange(AXES_MIN, AXES_MAX);
    dx->setValue(AXES_ZERO);

    all = new QSlider(this);
    all->setOrientation(Qt::Vertical);
    all->setGeometry(70, 20, 30, 200);
    all->setRange(AXES_MIN, AXES_MAX);
    all->setValue(AXES_ZERO);

    ros_timer = new QTimer(this);
    ros_timer->setInterval(100);
    ros_timer->setSingleShot(false);

    connect(sx, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));
    connect(dx, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));
    connect(all, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));

    connect(sx, SIGNAL(valueChanged(int)), this, SLOT(sxSliderMoved()));
    connect(dx, SIGNAL(valueChanged(int)), this, SLOT(dxSliderMoved()));
    connect(all, SIGNAL(sliderMoved(int)), this, SLOT(allSliderMoved()));

    connect(ros_timer, SIGNAL(timeout()), this, SLOT(rosLoop()));

    ros_timer->start();
}

void Joypad::resetSlider()
{
    sx->setValue(AXES_ZERO);
    dx->setValue(AXES_ZERO);
    all->setValue(AXES_ZERO);
}

void Joypad::allSliderMoved()
{
    sx->setValue(all->value());
    dx->setValue(all->value());
}

void Joypad::sxSliderMoved()
{

}

void Joypad::dxSliderMoved()
{

}

void Joypad::rosLoop()
{
    joypad_cmds.clear();
    joypad_cmds.push_back(sx->value());
    joypad_cmds.push_back(dx->value());

    joypad_msg.data = joypad_cmds;
    joypad_topic.publish(joypad_msg);

    ros::spinOnce();
}
