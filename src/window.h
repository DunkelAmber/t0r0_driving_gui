#ifndef WINDOW_H
#define WINDOW_H

#include "joystick.h"
#include "joypad.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QPushButton>

class Window : public QWidget
{
	Q_OBJECT

	public:
		explicit Window(QWidget *parent = 0);

	private:
		// Subwindows
        Joystick *joystick_emulator;
        Joypad *joypad_emulator;

        QGridLayout *main_layout;
        QVBoxLayout *joystick_layout, *joypad_layout;

        QGroupBox *joystick_box, *joypad_box;

        QPushButton *disp_joystick, *disp_joypad;

    public slots:
        void showJoystick();
        void showJoypad();
};

#endif // WINDOW_H
