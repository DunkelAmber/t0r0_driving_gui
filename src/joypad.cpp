#include "joypad.h"

// Constructor
Joypad::Joypad(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("Joypad Emulator");

//	ros::init(int argc, char **argv, "joypad_emulator");
//	ros::NodeHandle joypad_nh;

    sx = new QSlider(this);
    sx->setOrientation(Qt::Vertical);
    sx->setGeometry(20, 20, 30, 200);
    sx->setRange(0, 255);
    sx->setValue(SLIDER_ZERO);

    dx = new QSlider(this);
    dx->setOrientation(Qt::Vertical);
    dx->setGeometry(110, 20, 30, 200);
    dx->setRange(0, 255);
    dx->setValue(SLIDER_ZERO);

    all = new QSlider(this);
    all->setOrientation(Qt::Vertical);
    all->setGeometry(70, 20, 30, 200);
    all->setRange(0, 255);
    all->setValue(SLIDER_ZERO);

    connect(sx, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));
    connect(dx, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));
    connect(all, SIGNAL(sliderReleased()), this, SLOT(resetSlider()));

    connect(sx, SIGNAL(valueChanged(int)), this, SLOT(sxSliderMoved()));
    connect(dx, SIGNAL(valueChanged(int)), this, SLOT(dxSliderMoved()));
    connect(all, SIGNAL(sliderMoved(int)), this, SLOT(allSliderMoved()));
}

void Joypad::resetSlider()
{
    sx->setValue(SLIDER_ZERO);
    dx->setValue(SLIDER_ZERO);
    all->setValue(SLIDER_ZERO);
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
