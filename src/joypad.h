#ifndef JOYPAD_H
#define JOYPAD_H

#include <QWidget>
#include <QtCore>
#include <QSlider>

// #include <ros/ros.h>
// #include <std_msgs/String.h>
// #include <std_msgs/UInt8MultiArray.h>

#define SLIDER_ZERO 127

class Joypad : public QWidget
{
	Q_OBJECT

	public:
		explicit Joypad(QWidget *parent = 0);

	private:
        QSlider *dx, *sx, *all;

    public slots:
        void resetSlider();

        void sxSliderMoved();
        void dxSliderMoved();
        void allSliderMoved();
		
};

#endif
