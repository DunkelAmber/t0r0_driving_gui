#include "window.h"

// Constructor
Window::Window(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("T0R0 Driving Gui");

    int argc = 0;
    char *argv[1];

	// Setup Ros
    ros::init(argc, argv, "gui_main_window");
    ros::NodeHandle nh;

    joystick_subscriber = nh.subscribe("/joystick", 1, &Window::joystickCallback, this);
    joypad_subscriber = nh.subscribe("/joypad", 1, &Window::joypadCallback, this);

    joystick_box = new QGroupBox("Joystick");
    joystick_layout = new QVBoxLayout();

        joystick_data = new QLabel("000 000 000 000 000 000 000");
        disp_joystick = new QPushButton("Joystick Emulator");

    joystick_layout->addWidget(joystick_data);
    joystick_layout->addWidget(disp_joystick);
    joystick_box->setLayout(joystick_layout);

    joypad_box = new QGroupBox("Joypad");
    joypad_layout = new QVBoxLayout();

        joypad_data = new QLabel("000 000");
        disp_joypad = new QPushButton("Joypad Emulator");

    joypad_layout->addWidget(joypad_data);
    joypad_layout->addWidget(disp_joypad);
    joypad_layout->addStretch(2);
    joypad_box->setLayout(joypad_layout);

    main_layout = new QGridLayout(this);
    main_layout->addWidget(joystick_box, 0, 0);
    main_layout->addWidget(joypad_box, 1, 0);

    connect(disp_joystick, SIGNAL(clicked(bool)), this, SLOT(showJoystick()));
    connect(disp_joypad, SIGNAL(clicked(bool)), this, SLOT(showJoypad()));
}

void Window::showJoystick()
{
    joystick_emulator = new Joystick();
    joystick_emulator->show();
}

void Window::showJoypad()
{
    joypad_emulator = new Joypad();
    joypad_emulator->show();
}

void Window::joystickCallback(const std_msgs::UInt8MultiArray::ConstPtr& msg)
{
    QString data;

    data  = QString::number(msg->data[0]) + " ";
    data += QString::number(msg->data[1]) + " ";
    data += QString::number(msg->data[2]) + " ";
    data += QString::number(msg->data[3]) + " ";
    data += QString::number(msg->data[4]) + " ";
    data += QString::number(msg->data[5]) + " ";
    data += QString::number(msg->data[6]) + " ";

    joystick_data->setText(data);
}

void Window::joypadCallback(const std_msgs::UInt8MultiArray::ConstPtr& msg)
{
    QString data;

    data = QString::number(msg->data[0]) + " ";
    data += QString::number(msg->data[1]) + " ";

    joypad_data->setText(data);
}
