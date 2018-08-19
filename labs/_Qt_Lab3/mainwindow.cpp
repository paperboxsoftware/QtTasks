#include "mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QDebug>

#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QAbstractSlider>
#include <QValidator>

#include <QVBoxLayout>
#include <QSignalMapper>
#include <QSpacerItem>

mainWindow::mainWindow(QWidget *parent)
    : QWidget(parent)
{
    // 2
    QPushButton * buttonExit = new QPushButton(QObject::tr("Exit"),this);
    // 3
    connect(buttonExit,SIGNAL(clicked(bool)),SLOT(close()));

    //   QBoxLayout* pLayout;
    //   QPushButton * buttonExit2 = new QPushButton(QObject::tr("Exit"),this);
    //   pLayout->addWidget(buttonExit2);
    //   this->setLayout(pLayout);



    edit = new QLineEdit(this);
    label = new QLabel(this);

    spinBox = new QSpinBox(this);
    slider = new QSlider(Qt::Horizontal,this);

//    mainLayout->addWidget(label);
//    mainLayout->addWidget(edit);
//    mainLayout->addWidget(spinBox);
//    mainLayout->addWidget(slider);





    spinBox->setMaximum(25);
    slider->setRange(0,25);
//    slider->setMinimum(0);
//    slider->setMaximum(25);
    slider->setTickPosition(QSlider::TicksBelow);
    slider->setTickInterval(10);

    edit->setMaxLength(10);
   // QValidator*
 //   edit->setValidator();

    QIntValidator* qValid = new QIntValidator(0,25,spinBox);
    edit->setValidator(qValid);

    label->setMinimumWidth(10);
    label->setMinimumHeight(10);
    label->setFrameStyle(QFrame::Raised | QFrame::Box);
    label->setText("Not Set");
   // label->lineWidth(1);

//--------------------------------------------------------------------------------------//
// Синхронизация
//--------------------------------------------------------------------------------------//
// синхронизация
    connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    connect(slider,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));
   // connect(spinBox,SIGNAL(valueChanged(int)),edit,SLOT(setText(QString)));

    connect(edit,SIGNAL(textChanged(QString)),this,SLOT(mySlot(QString)));
    connect(this,SIGNAL(mySignal(int)),spinBox,SLOT(setValue(int)));

//    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(mySlot(QString)));
//    connect(this,SIGNAL(textChanged(QString)),label,SLOT(setText(QString)));

 connect( spinBox, SIGNAL(valueChanged(QString)),label , SLOT(setText(QString)));
 connect( spinBox, SIGNAL(valueChanged(QString)),edit , SLOT(setText(QString)));



//   mainLayout->addLayout(vLayout);
//   mainLayout->addLayout(hLayout);
//  mainLayout->addWidget(buttonExit);


//--------------------------------------------------------------------------------------//
// Компоновки
//--------------------------------------------------------------------------------------//

  QPushButton * horizontal = new QPushButton(QObject::tr("Horizontal"),this);
  QPushButton * vertical = new QPushButton(QObject::tr("Vertical"),this);
  QPushButton* grid = new QPushButton(QObject::tr("grid"),this);
  QPushButton* stack = new QPushButton(QObject::tr("stack"),this);

  mSpacerItem = new QSpacerItem(100,10);


  mainLayout = new QHBoxLayout;
 this->setLayout(mainLayout);

  hLayout = new QHBoxLayout;

  hLayout->addWidget(edit);
  hLayout->addWidget(spinBox);
  hLayout->addWidget(slider,1);
  hLayout->addWidget(label);
  hLayout->addItem(mSpacerItem);

 // this->setLayout(hLayout);  //у виджета уже есть компоновка. НЕЛЬЗЯ!!!
Qt::Alignment alv= Qt::AlignCenter;
  vLayout = new QVBoxLayout;
  vLayout->addWidget(edit,1,alv);
  vLayout->addWidget(spinBox,1,alv);
  vLayout->addWidget(slider,1,alv);
  vLayout->addWidget(label,1,alv);
  vLayout->addItem(mSpacerItem);


  //gLayout
  gLayout = new QGridLayout;

  gLayout->addWidget(edit,1,1);
  gLayout->addWidget(spinBox,1,2);
  gLayout->addWidget(slider,2,1);
  gLayout->addWidget(label,2,2);




  buttonLayout = new QVBoxLayout;
  buttonLayout->addWidget(horizontal);
  buttonLayout->addWidget(vertical);
  buttonLayout->addWidget(grid);
  buttonLayout->addWidget(stack);




  stackLayout=new QStackedLayout();
  stackLayout->addWidget(slider);
  stackLayout->addWidget(spinBox);
  stackLayout->addWidget(edit);
  stackLayout->setStackingMode(QStackedLayout::StackAll);

  //ComboBox
     combo=new QComboBox();
     combo->addItem("slider");
     combo->addItem( "spinBox" );
     combo->addItem( "edit" );
     combo->hide();

     connect( combo, SIGNAL(activated(int)),
     stackLayout, SLOT(setCurrentIndex(int)));

        demoStackLayout = new QVBoxLayout();
        Qt::Alignment align = Qt::AlignCenter;
        demoStackLayout->addWidget(combo, 0,align);
        demoStackLayout->addWidget(label,0, align);
        demoStackLayout->addLayout(stackLayout);
        demoStackLayout->addItem(mSpacerItem);



mapper = new QSignalMapper(this);
mapper->setMapping(vertical,vLayout);
mapper->setMapping(horizontal,hLayout);
mapper->setMapping(grid,gLayout);
mapper->setMapping(stack,demoStackLayout);




connect( horizontal, SIGNAL(clicked(bool)),mapper,SLOT(map()));
connect( vertical, SIGNAL(clicked(bool)),mapper , SLOT(map()));
connect(grid,SIGNAL(clicked(bool)),mapper,SLOT(map()));
connect(stack,SIGNAL(clicked(bool)),mapper,SLOT(map()));

connect( mapper, SIGNAL(mapped(QObject*)), this, SLOT(ChangeLayout(QObject*)) );

mainLayout->addLayout(hLayout);
//mainLayout->addLayout(vLayout);
mainLayout->addLayout(buttonLayout);
mainLayout->addWidget(buttonExit);






}

mainWindow::~mainWindow()
{
    QLayoutItem* pItem = mainLayout->itemAt(0);
        mainLayout->removeItem(pItem);
        delete hLayout;
        delete vLayout;
        delete gLayout;

        delete stackLayout;
        delete demoStackLayout;
}

int mainWindow::mySlot(QString myStr)
{
    int n = myStr.toInt();

    emit (mySignal(n));
}



void mainWindow::ChangeLayout(QObject *pNewLayout)
{
 //получить указатель на текущую вложенную компоновку
 //0-индекс  вложенной компоновки в mainLayout.
    QLayoutItem* pItem= mainLayout->itemAt(0);
    //исключить текущую вложенную компоновку из главной компоновки
    mainLayout->removeItem(pItem);
    //вставить новую вложенную компоновку в главную компоновку
    mainLayout->insertLayout(0,static_cast<QLayout*>(pNewLayout));
    if(pNewLayout==demoStackLayout)
    {
      combo->setVisible(true);
        //скрываем все элементы управления
          spinBox->hide();
          edit->hide();
          slider->hide();
      //отображаем только текущий
          stackLayout->currentWidget()->show();
      stackLayout->setStackingMode(QStackedLayout::StackOne);
   }
   else
   {
      combo->setVisible(false);
      stackLayout->setStackingMode(QStackedLayout::StackAll);
    }

}
