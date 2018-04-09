#include "startbutton.h"

StartButton::StartButton(QWidget *parent) : QPushButton(parent)
{
    border = QColor(250, 0, 0);

    rover_on = false;

    startup_timer = new QTimer(this);
    startup_timer->setInterval(2);
    startup_timer->setSingleShot(false);

    connect(this, SIGNAL(clicked()), this, SLOT(onClick()));
    connect(startup_timer, SIGNAL(timeout()), this, SLOT(startupTimeout()));
}

void StartButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(Qt::NoPen);
    QRadialGradient border_grad(QPoint(this->width() / 2, this->height()), this->width() / 2);
    border_grad.setColorAt(0.9, border);
    border_grad.setColorAt(1, QColor(0, 0, 0));
    painter.setBrush(border_grad);
    painter.drawEllipse(QPoint(this->width() / 2, this->height()), this->width() / 2, this->height());

    painter.setPen(QColor(0, 0, 0));
    QRadialGradient background(QPoint(this->width() / 2, this->height()), this->width() / 2);
    background.setColorAt(1, QColor(30, 30, 30));
    background.setColorAt(0, QColor(80, 80, 80));
    painter.setBrush(background);
    painter.drawEllipse(QPoint(this->width() / 2, this->height()), this->width() / 2 - 10, this->height()- 10);

    painter.setPen(Qt::SolidLine);
    if(rover_on)
        painter.drawText(this->width() / 2 - 32, this->height() - 20, "Disconnect");
    else
        painter.drawText(this->width() / 2 - 24, this->height() - 20, "Connect");

}

void StartButton::onClick()
{
    if(!rover_on)
    {
        fade_count = 0;
        emit toBeConnected();
        startup_timer->start();
    }
    else
    {   rover_on = false;
        emit toBeDisconnected();
        border = QColor(250, 0, 0);
        this->update();
    }
}

void StartButton::startupTimeout()
{
    if(!rover_on)
    {
        if(fade_count < 250)
        {
            border = QColor(250 - fade_count, 0, 0);
            this->update();
            fade_count++;
        }
        else
        {
            border = QColor(fade_count - 250, 0, 0);
            this->update();
            fade_count++;
        }

        if(fade_count == 500)
        {
            fade_count = 0;
        }
    }
    else if(rover_on && fade_count < 500)
    {
        if(fade_count < 250)
        {
            border = QColor(0, 250 - fade_count, 0);
            this->update();
            fade_count++;
        }
        else
        {
            border = QColor(0, fade_count - 250, 0);
            this->update();
            fade_count++;
        }
    }
    else
    {
        border = QColor(0, 250, 0);
        this->update();
        startup_timer->stop();
    }
}

void StartButton::confirmStartup()
{
    rover_on = true;
}
