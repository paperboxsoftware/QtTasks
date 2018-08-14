#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap background(":/CC-Cards-640x353.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);

    this->setFixedSize(background.size());


}

void MainWindow::on_actionAbout_triggered(){
  QMessageBox::about(0, "About", "PaperBoxSoftWare Card Validator v 0.1");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

QVector<int> MainWindow::transformString(QString& string)
{
 QVector<int> transformedString;
 QString::iterator strIt = string.begin();

 for(auto it : transformedString)
 {
     QVariant var = *strIt;
     int number = var.toInt();
     transformedString.push_back(number);
 }

 return transformedString;
}

QVector<int> MainWindow::mySlot(QString string)
{
 QVector<int> transformedString;
 QString::iterator strIt = string.begin();

 for(auto it : transformedString)
 {
     QVariant var = *strIt;
     int number = var.toInt();
     transformedString.push_back(number);
 }

// return transformedString;
 emit (mySignal(transformedString));
}
