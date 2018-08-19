#include "spider.h"
#include <QDebug>
#include <QIcon>
#include <QPixmap>
#include <QBrush>
#include <QApplication>
#include <QDesktopWidget>
#include <QCursor>
#include <QBitmap>
#include <QColorDialog>
#include <QFileDialog>


Spider::Spider(QWidget *parent)
    : QWidget(parent)
{
   qDebug() << this->windowFlags();

   Qt::WindowFlags flags;

   flags = Qt::Window;

   flags |= Qt::WindowStaysOnTopHint;
   flags |= Qt::CustomizeWindowHint;
   flags |= Qt::WindowTitleHint;
   flags |= Qt::WindowCloseButtonHint;
   flags |= Qt::WindowMaximizeButtonHint;
   flags |= Qt::WindowMinimizeButtonHint;


   this->setWindowFlags(flags);


   qDebug() << this->windowFlags();

   //Qt::WindowState f = Qt::WindowMaximized;

   //this->setWindowState(f);

   //qDebug() << this->windowState();

   this->setWindowTitle(tr("Hello"));

   qDebug() << this->windowTitle();

   QIcon icon("icon2.ico");

   this->setWindowIcon(icon);

   qDebug() << this->windowIcon();

// QPalette pal = Qt::black;

// this->setPalette(pal);

// qDebug() << this->palette();

// QPallete - палитра / набор цветов, три группы цветов. QPalette::ColorGroup - active, inactive
//ColorRole

    QPalette myPalette;
    myPalette.setColor(QPalette::Active,QPalette::Window,QColor(Qt::red));
    myPalette.setColor(QPalette::Inactive,QPalette::Window,QColor(Qt::green));

   // this->setPalette(myPalette);

    QPixmap myPic;//("Disney_42.png");
    bool b = myPic.load("Disney_42.png");
    qDebug() << b;
    QBrush myBrush(myPic);

    myPalette.setBrush(QPalette::Inactive,QPalette::Window,myBrush);

    this->setPalette(myPalette);

    this->setWindowOpacity(0.8);

    QPoint point = this->pos();
    QRect rect = this->geometry();
    QRect rect2 = this->rect();

    qDebug() << point << rect << rect2;
    // QPoint(0,0) QRect(0,0 640x480) QRect(0,0 640x480)



    QDesktopWidget* pScreen = QApplication::desktop();
    QRect rectScreen = pScreen->screenGeometry();
    // QRect(0,0 1920x1080)

   // this->setGeometry(rectScreen);

    this->move(rectScreen.center());

   //this->move(QPoint(rectScreen.width()/2,rectSreen.width()/2));
    qDebug() << rectScreen;
    QPoint myPoint(rectScreen.width()/2,rectScreen.height()/2);
    this->move(myPoint);

    QSize scrSize(myPoint.x(),myPoint.y());
    this->resize(scrSize);

    //this->setFixedHeight(300);

    QSize myPicSize = myPic.size();
   // this->setMaximumSize(myPicSize);
    this->setMinimumSize(myPicSize);

//10 - cursor
    this->setCursor(Qt::CrossCursor);


    // Cursor from image

    QPixmap spider("super_spy.bmp");
    spider.setMask(QBitmap("super_spy.bmp"));
    QCursor curSpider(spider);
    spCursor = &curSpider;

    this->setCursor(*spCursor);
// 8 Dialogs & Backgrounds
//    QColorDialog::getColor();
    QColor color2 = QColorDialog::getColor();
            if (color2.isValid()){
              myPalette.setColor (QPalette::Active, QPalette::Background, color2);
             this->setPalette(myPalette);
            }
QString fileName = QFileDialog::getOpenFileName();
if(!fileName.isNull()){
    QPixmap background(fileName);
    myPalette.setBrush(QPalette::Inactive, QPalette::Window, background);
    this->setPalette(myPalette);
}
// translations
// add tr() method to code in 42 string - name of program
// lupdate from qtcreator-external-lupdate



}

Spider::~Spider()
{

}
