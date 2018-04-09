#ifndef NEWBUTTON_H
#define NEWBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QTimer>

class StartButton : public QPushButton
{
    Q_OBJECT

public:
    StartButton(QWidget *parent = 0);

signals:
    void toBeConnected();
    void toBeDisconnected();

public slots:
    void confirmStartup();

private:
    QColor border;
    QTimer *startup_timer;

    int fade_count;
    bool rover_on;

private slots:
    void onClick();
    void startupTimeout();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // NEWBUTTON_H
