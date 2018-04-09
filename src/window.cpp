#include "window.h"

// Constructor
Window::Window(QRect screen, QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0, 0, screen.width(), screen.height());   // -50

    // set black background
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    connected = false;

    // Custom elements
    start_button = new StartButton(this);
    start_button->setGeometry(this->width()/ 2 - 100, this->height() - 100, 200, 100);

    rover = new RoverShow(this);
    rover->setGeometry(300, 0, this->width() - 600, this->height() - 100);

    battery1 = new BatteryIndicator(this);
    battery1->setGeometry(this->width() / 2 + 200, this->height() - 80, 21, 70);
    battery2 = new BatteryIndicator(this);
    battery2->setGeometry(this->width() / 2 + 230, this->height() - 80, 21, 70);
    battery3 = new BatteryIndicator(this);
    battery3->setGeometry(this->width() / 2 + 260, this->height() - 80, 21, 70);
    battery4 = new BatteryIndicator(this);
    battery4->setGeometry(this->width() / 2 + 290, this->height() - 80, 21, 70);
    battery5 = new BatteryIndicator(this);
    battery5->setGeometry(this->width() / 2 + 320, this->height() - 80, 21, 70);
    battery6 = new BatteryIndicator(this);
    battery6->setGeometry(this->width() / 2 + 350, this->height() - 80, 21, 70);
    battery7 = new BatteryIndicator(this);
    battery7->setGeometry(this->width() / 2 + 380, this->height() - 80, 21, 70);
    battery8 = new BatteryIndicator(this);
    battery8->setGeometry(this->width() / 2 + 410, this->height() - 80, 21, 70);
    battery9 = new BatteryIndicator(this);
    battery9->setGeometry(this->width() / 2 + 440, this->height() - 80, 21, 70);
    battery10 = new BatteryIndicator(this);
    battery10->setGeometry(this->width() / 2 + 470, this->height() - 80, 21, 70);

    battery2->setCharge(70);
    battery3->setCharge(45);
    battery4->setCharge(10);
}
