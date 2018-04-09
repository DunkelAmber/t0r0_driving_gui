#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>

class ImageButton : public QPushButton
{
    Q_OBJECT

public:
    ImageButton(QString image_path, QWidget *parent = 0);

public slots:
    void setConnected(bool state);

private:
    QString path;
    bool connected;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // IMAGEBUTTON_H
