#include "imagebutton.h"

ImageButton::ImageButton(QString image_path, QWidget *parent) : QPushButton(parent)
{
    path = image_path;
    connected = false;
}

void ImageButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setPen(Qt::NoPen);

    QLinearGradient light(70, 35, 80, 35);
    if(connected)
        light.setColorAt(0, QColor(130, 180, 255));
    else
        light.setColorAt(0, QColor(255, 120, 120));
    light.setColorAt(1, QColor(239, 235, 231));
    painter.setBrush(light);
    painter.drawRect(70, 0, 10, 70);

    painter.setBrush(QColor(200, 200, 200));
    painter.drawRect(0, 0, 70, 70);

    painter.drawImage(10, 10, QImage(path));
}

void ImageButton::setConnected(bool state)
{
    connected = state;
    this->update();
}
