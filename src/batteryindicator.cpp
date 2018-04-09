#include "batteryindicator.h"

BatteryIndicator::BatteryIndicator(QWidget *parent) : QWidget(parent)
{
    charge = 100;
    in_use = false;
}

void BatteryIndicator::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Battery charge colors
    QColor fully(0, 60, 200);
    QColor good(0, 200, 0);
    QColor med(200, 200, 0);
    QColor low(200, 0, 0);

    // Draw battery package
    painter.setPen(QColor(80, 80, 80));
    painter.setBrush(QColor(80, 80, 80));
    painter.drawRect(5, 0, 10, 3);
    painter.drawRect(0, 3, 20, 5);
    painter.drawLine(0, 3, 0, 60);
    painter.drawLine(20, 3, 20, 60);
    painter.drawRect(0, 58, 20, 5);

    // Draw battery charge
    if(charge > GOODCHARGE)
    {
        painter.setPen(fully);
        painter.setBrush(fully);
    }
    else if(charge > MEDCHARGE)
    {
        painter.setPen(good);
        painter.setBrush(good);
    }
    else if(charge > LOWCHARGE)
    {
        painter.setPen(med);
        painter.setBrush(med);
    }
    else
    {
        painter.setPen(low);
        painter.setBrush(low);
    }

    painter.drawRect(1, 8 + (50 - charge / 2), 18, charge / 2);

    painter.setPen(QColor(255, 255, 255));
    painter.rotate(90);
    if(charge == 100)
        painter.drawText(18, -6, QString::number(charge) + "%");
    else if(charge > 9)
        painter.drawText(18, -6, " " + QString::number(charge) + "%");
    else
        painter.drawText(18, -6, "  " + QString::number(charge) + "%");
    painter.rotate(-90);

    // Draw in-use gradient
    if(in_use)
        painter.setPen(QColor(50, 200, 255));
    else
        painter.setPen(Qt::NoPen);

    painter.drawLine(0, 68, 20, 68);
    painter.drawLine(0, 69, 20, 69);
    painter.drawLine(0, 70, 20, 70);
}

void BatteryIndicator::setCharge(int charge)
{
    this->charge = charge;
    this->update();
}

void BatteryIndicator::setInUse(bool status)
{
    in_use = true;
    this->update();
}
