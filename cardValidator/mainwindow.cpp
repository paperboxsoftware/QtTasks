#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QObject>
#include <QStack>

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

connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(buttonClicked()));
}

void MainWindow::on_actionAbout_triggered(){
  QMessageBox::about(0, "About", "PaperBoxSoftWare Card Validator v 0.1");
}

//void MainWindow::keyPressEvent(*event)
//{
//    if(event == Qt::Key_Enter){

//    }
//}

MainWindow::~MainWindow()
{
    delete ui;
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

    QVector<int> backVector;
            //(intVector.rbegin(),intVector.rend());
    QVector<int>::reverse_iterator rBeg = intVector.rbegin();
    QVector<int>::reverse_iterator rEnd = intVector.rend();

    while(rBeg!=rEnd){
        backVector.push_back(*rBeg);
        rBeg++;
    }

    int sum = 0;
    int cardLength    = intVector.size();
    int parity    = (cardLength-1) % 2;


       for (auto rBeg: backVector)
       {
//         cDigit[0]  = pPurported[i-1];
//         int nDigit = atoi(cDigit);

         if (parity == cardLength % 2)
           rBeg = rBeg * 2;

         sum += rBeg/10;
         sum += rBeg%10;
         cardLength--;
       }
       bool isValid = (0 == sum % 10) ;


    ui->textEdit->clear();
    if(isValid)
    ui->textEdit->append("card is valid");

    else
        ui->textEdit->append("card is not valid");

    emit(validateSignal(isValid)) ;


}

