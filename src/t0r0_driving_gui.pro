#-------------------------------------------------
#
# Project created by QtCreator 2017-10-12T15:34:29
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app

SOURCES += main.cpp window.cpp joystick.cpp joypad.cpp startbutton.cpp rovershow.cpp batteryindicator.cpp imagebutton.cpp def.cpp

HEADERS  += window.h joystick.h joypad.h startbutton.h rovershow.h batteryindicator.h imagebutton.h

RESOURCES += ../Images/joystick.png
