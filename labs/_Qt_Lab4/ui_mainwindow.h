/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mypicture.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_exit;
    QAction *actionAbout;
    QAction *actioncommand;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSlider;
    QLabel *label_3;
    QPushButton *pushButton;
    MyPicture *widget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuInformation;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(682, 487);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images/Images/icon2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pictures/Images/icon2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/pictures/Images/iconInfo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon2);
        actionAbout->setIconVisibleInMenu(true);
        actioncommand = new QAction(MainWindow);
        actioncommand->setObjectName(QStringLiteral("actioncommand"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/pictures/Images/spider1.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actioncommand->setIcon(icon3);
        actioncommand->setIconVisibleInMenu(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFrameShape(QFrame::Box);

        horizontalLayout_2->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout->addWidget(spinBox);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(label);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFrameShape(QFrame::Box);

        horizontalLayout_3->addWidget(label_3);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 3);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setIcon(icon3);
        pushButton->setCheckable(true);

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        widget = new MyPicture(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widget, 4, 0, 1, 3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 682, 21));
        menuBar->setAutoFillBackground(false);
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuInformation = new QMenu(menuBar);
        menuInformation->setObjectName(QStringLiteral("menuInformation"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(lineEdit);
        label->setBuddy(spinBox);
        label_3->setBuddy(horizontalSlider);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuInformation->menuAction());
        menu->addSeparator();
        menu->addSeparator();
        menu->addAction(action_exit);
        menu->addAction(actioncommand);
        menuInformation->addAction(actionAbout);
        menuInformation->addAction(actioncommand);
        mainToolBar->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(QString)), lineEdit, SLOT(setText(QString)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));
        QObject::connect(action_exit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(mainToolBar, SIGNAL(actionTriggered(QAction*)), MainWindow, SLOT(close()));
        QObject::connect(pushButton, SIGNAL(clicked()), action_exit, SLOT(trigger()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), widget, SLOT(scaleChanged(int)));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), statusBar, SLOT(showMessage(QString)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\224\320\270\320\267\320\260\320\271\320\275\320\265\321\200", Q_NULLPTR));
        action_exit->setText(QApplication::translate("MainWindow", "&exit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_exit->setToolTip(QApplication::translate("MainWindow", "Exit from program", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_exit->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "About Program", Q_NULLPTR));
        actionAbout->setIconText(QApplication::translate("MainWindow", "About Program", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "About program", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actioncommand->setText(QApplication::translate("MainWindow", "command", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        centralWidget->setStatusTip(QApplication::translate("MainWindow", "\320\235\320\270\321\207\320\265\320\263\320\276 \320\275\320\265 \320\264\320\265\320\273\320\260\321\216\342\200\246", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        label_2->setText(QApplication::translate("MainWindow", "&LineEditBuddy", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "&SpinBuddy", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Sli&DerBuddy", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", Q_NULLPTR));
        menuInformation->setTitle(QApplication::translate("MainWindow", "Information", Q_NULLPTR));
        mainToolBar->setWindowTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
