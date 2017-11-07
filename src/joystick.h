#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QWidget>
#include <QtCore>
#include <QSlider>

// #include <ros/ros.h>
// #include <std_msgs/String.h>
// #include <std_msgs/UInt8MultiArray.h>

#define SLIDER_ZERO 127

class Joystick : public QWidget
{
	Q_OBJECT

	public:
		explicit Joystick(QWidget *parent = 0);

	private:
        QSlider *x, *y, *z;

    public slots:
        void resetSlider();

        void xSliderMoved();
        void ySliderMoved();
        void zSliderMoved();
		
};

#endif
