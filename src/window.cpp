#include "window.h"

// Constructor
Window::Window(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("T0R0 Driving Gui");

    int argc;
    char **argv;

	// Setup Ros
//	ros::init(argc, argv, "gui_window");
//	ros::NodeHandle nh;



    joystick_box = new QGroupBox("Joystick");
    joystick_layout = new QVBoxLayout();

        disp_joystick = new QPushButton("Joystick Emulator");

    joystick_layout->addWidget(disp_joystick, 0);
    joystick_box->setLayout(joystick_layout);

    joypad_box = new QGroupBox(tr("Joypad"));
    joypad_layout = new QVBoxLayout();

        disp_joypad = new QPushButton("Joypad Emulator");

    joypad_layout->addWidget(disp_joypad, 0);
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
