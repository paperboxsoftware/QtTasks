#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QObject>

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
//    connect(ui->pushButton,SIGNAL(clicked(bool)),ui->lineEdit,SLOT(setEnabled(bool)));
//    connect(ui->lineEdit,SIGNAL(text(QString)),this,SLOT(validateSlot(QString)));
//    connect(ui->lineEdit,SIGNAL(text()),ui->textEdit,SLOT(setText(QString)));
//    connect(this,SIGNAL(validateSignal(bool)),ui->textEdit,SLOT(setText(QString)));
connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(buttonClicked()));
}

void MainWindow::on_actionAbout_triggered(){
  QMessageBox::about(0, "About", "PaperBoxSoftWare Card Validator v 0.1");
}


MainWindow::~MainWindow()
{
    delete ui;
}



bool MainWindow::validateSlot(QString cardNumber)
{

}

void MainWindow::buttonClicked()
{
    QString cardNumber = ui->lineEdit->text();
   // QString::iterator strIt = cardNumber.begin();
    QVector<int> intVector;

    for(auto it : cardNumber)
    {
        //QVariant var = it;
        //int number = it.toInt();
        int number = it.digitValue();
        intVector.push_back(number);
//        ++strIt;
    }

    for(auto it : intVector)
    {
         qDebug() << it;
    }

    qDebug() << "nocha";
    qDebug() << intVector.isEmpty();


//    for(int i = 0; i < cardNumber.length();++i){
//        intVector.push_back(cardNumber[i].toInt());
//    }

    auto sum = 0;
    bool isValid = false;

    for(auto it : intVector){
        sum += (it-48);
    }
    qDebug() << "sum is" << sum;
qDebug() << sum%10;
    sum %=  10;
   // auto vSize = sizeof(intVector)/sizeof(int);
  auto vSize =  intVector.size();
    qDebug() << (sum%10==0);

    qDebug() << vSize;
    if(sum == 0 && vSize == 16){
        isValid = true;
    }
    else if(sum == 1 && vSize == 16){
        isValid = true;
    }




    if(isValid)
    ui->textEdit->append("card is valid");
//    else if(intVector[0]==4)
// ui->textEdit->append("card is visa");
    else
        ui->textEdit->append("pidor");

    emit(validateSignal(isValid)) ;


}

