#ifndef ROVERSHOW_H
#define ROVERSHOW_H

#include <QWidget>
#include <QPainter>

class RoverShow : public QWidget
{
    Q_OBJECT
public:
    explicit RoverShow(QWidget *parent = 0);

signals:

public slots:
    void signalFrontObstacle(bool obstacle);
    void signalBackObstacle(bool obstacle);
    void signalLeftObstacle(bool obstacle);
    void signalRightObstacle(bool obstacle);

private:
    bool left_free, right_free, front_free, back_free;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // ROVERSHOW_H
