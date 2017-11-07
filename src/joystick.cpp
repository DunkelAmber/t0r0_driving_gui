#include "joystick.h"

// Constructor
Joystick::Joystick(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Joystick Emulator");

//	ros::init(int argc, char **argv, "joystick_emulator");
//	ros::NodeHandle joystick_nh;

    x = new QSlider(this);
    x->setGeometry(30, 10, 20, 200);
    x->setOrientation(Qt::Vertical);
    x->setRange(0, 255);
    x->setValue(127);

    y = new QSlider(this);
    y->setGeometry(10, 220, 200, 20);
    y->setOrientation(Qt::Horizontal);
    y->setRange(0, 255);
    y->setValue(127);

    z = new QSlider(this);
    z->setGeometry(160, 10, 20, 200);
    z->setOrientation(Qt::Vertical);
    z->setRange(0, 255);
    z->setValue(127);

    connect(x, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));
    connect(y, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));
    connect(z, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));

    connect(x, SIGNAL(valueChanged(int)), this, SLOT(xSliderMoved()));
    connect(y, SIGNAL(valueChanged(int)), this, SLOT(ySliderMoved()));
    connect(z, SIGNAL(valueChanged(int)), this, SLOT(zSliderMoved()));
}

void Joystick::resetSlider()
{
    x->setValue(SLIDER_ZERO);
    y->setValue(SLIDER_ZERO);
    z->setValue(SLIDER_ZERO);
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
