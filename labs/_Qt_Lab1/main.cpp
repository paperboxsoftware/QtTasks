#include "spider.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QTranslator translator;
//    translator.load("spider_ru.qm");

    translator.load(QLocale::system(),"spider","_");

    QApplication::installTranslator(&translator);

    QTranslator translator2;
    translator2.load(QLocale::system(),"qtbase","_");

    QApplication::installTranslator(&translator2);


    Spider w;
    w.show();

    return a.exec();
}
