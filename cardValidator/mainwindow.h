#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "validator.h"
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QVector<int> transformString(QString& string);

    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionAbout_triggered();


public slots:
    bool validateSlot(QString);
    void buttonClicked();
signals:
    void validateSignal(bool);
};

#endif // MAINWINDOW_H
