#include "mypicture.h"
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>


MyPicture::MyPicture(QWidget *parent): QWidget(parent)
{
    this->m_pixmap = new QPixmap;
    bool b = m_pixmap->load(":/pictures/Images/WomanAndDog.jpg");
        //  this->m_pixmap = new QPixmap("WomanAndDog.jpg");
           qDebug() << "b is" << b ;
}

void MyPicture::paintEvent ( QPaintEvent * event ){
if(m_pixmap){
 qDebug() <<"*" << *m_pixmap;
    QPainter painter(this);
   painter.scale(m_scale/100, m_scale/100);

    painter.drawPixmap(0,0,*m_pixmap);
}

 }


 void MyPicture::scaleChanged(int val){
     m_scale=val;
     this->repaint();
 }
