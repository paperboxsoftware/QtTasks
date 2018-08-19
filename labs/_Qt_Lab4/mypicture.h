#ifndef MYPICTURE_H
#define MYPICTURE_H

#include <QWidget>
#include <QPainter>
#include "mainwindow.h"
#include <QDebug>

class MyPicture : public QWidget
{
    Q_OBJECT


public:
    explicit MyPicture(QWidget *parent = 0);


protected:
  virtual  void paintEvent ( QPaintEvent * event );

signals:

public slots:
void scaleChanged(int);
private:
  QPixmap* m_pixmap;
    double m_scale;
};

#endif // MYPICTURE_H
