#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QString>
#include <QSignalMapper>
#include <QGridLayout>
#include <QComboBox>
#include <QStackedLayout>


class mainWindow : public QWidget
{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = 0);
    ~mainWindow();
private:
    QHBoxLayout* mainLayout;
    QLineEdit* edit;
    QLabel* label;
    QHBoxLayout* hLayout;
    QSpinBox* spinBox;
    QSlider* slider;


    QVBoxLayout* buttonLayout;
    QVBoxLayout* vLayout;
    QSignalMapper* mapper;
    QGridLayout* gLayout;

    QStackedLayout* stackLayout;
    QComboBox* combo;

    QVBoxLayout*demoStackLayout;

    QSpacerItem* mSpacerItem;


signals:
    void mySignal(int);
public slots:
    int mySlot(QString);
   void ChangeLayout(QObject *pNewLayout);
//    int mySlot(int);
};

#endif // MAINWINDOW_H
