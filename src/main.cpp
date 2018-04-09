#include <QApplication>
#include <QDesktopWidget>

#include "window.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  QDesktopWidget *desktop = app.desktop();

  Window window(desktop->screenGeometry());
  window.showMaximized();

  return app.exec();
}
