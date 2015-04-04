/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnConnect;
    QPushButton *btnDisconnect;
    QSlider *sldThrotle;
    QDial *dialPolling;
    QLabel *lblThortle;
    QLabel *lblRudder;
    QLabel *lblAileron;
    QLabel *lblElevator;
    QLabel *Elevation;
    QSlider *sldRudder;
    QSlider *sldAileron;
    QSlider *sldElevator;
    QLabel *lblPollingTime;
    QSpinBox *numElevation;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(557, 426);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btnConnect = new QPushButton(centralWidget);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(10, 10, 114, 32));
        btnDisconnect = new QPushButton(centralWidget);
        btnDisconnect->setObjectName(QStringLiteral("btnDisconnect"));
        btnDisconnect->setEnabled(false);
        btnDisconnect->setGeometry(QRect(10, 40, 114, 32));
        sldThrotle = new QSlider(centralWidget);
        sldThrotle->setObjectName(QStringLiteral("sldThrotle"));
        sldThrotle->setGeometry(QRect(70, 90, 451, 31));
        sldThrotle->setMaximum(254);
        sldThrotle->setOrientation(Qt::Horizontal);
        sldThrotle->setTickPosition(QSlider::TicksBelow);
        dialPolling = new QDial(centralWidget);
        dialPolling->setObjectName(QStringLiteral("dialPolling"));
        dialPolling->setGeometry(QRect(150, 0, 91, 91));
        dialPolling->setMinimum(5);
        dialPolling->setMaximum(100);
        dialPolling->setPageStep(1);
        dialPolling->setValue(50);
        dialPolling->setWrapping(true);
        lblThortle = new QLabel(centralWidget);
        lblThortle->setObjectName(QStringLiteral("lblThortle"));
        lblThortle->setGeometry(QRect(10, 100, 51, 16));
        lblRudder = new QLabel(centralWidget);
        lblRudder->setObjectName(QStringLiteral("lblRudder"));
        lblRudder->setGeometry(QRect(10, 130, 51, 16));
        lblAileron = new QLabel(centralWidget);
        lblAileron->setObjectName(QStringLiteral("lblAileron"));
        lblAileron->setGeometry(QRect(10, 160, 62, 16));
        lblElevator = new QLabel(centralWidget);
        lblElevator->setObjectName(QStringLiteral("lblElevator"));
        lblElevator->setGeometry(QRect(10, 190, 51, 16));
        Elevation = new QLabel(centralWidget);
        Elevation->setObjectName(QStringLiteral("Elevation"));
        Elevation->setGeometry(QRect(10, 240, 62, 16));
        sldRudder = new QSlider(centralWidget);
        sldRudder->setObjectName(QStringLiteral("sldRudder"));
        sldRudder->setGeometry(QRect(70, 120, 451, 31));
        sldRudder->setMaximum(254);
        sldRudder->setOrientation(Qt::Horizontal);
        sldRudder->setTickPosition(QSlider::TicksBelow);
        sldAileron = new QSlider(centralWidget);
        sldAileron->setObjectName(QStringLiteral("sldAileron"));
        sldAileron->setGeometry(QRect(70, 150, 451, 31));
        sldAileron->setMaximum(254);
        sldAileron->setOrientation(Qt::Horizontal);
        sldAileron->setTickPosition(QSlider::TicksBelow);
        sldElevator = new QSlider(centralWidget);
        sldElevator->setObjectName(QStringLiteral("sldElevator"));
        sldElevator->setGeometry(QRect(70, 180, 451, 31));
        sldElevator->setMaximum(254);
        sldElevator->setOrientation(Qt::Horizontal);
        sldElevator->setTickPosition(QSlider::TicksBelow);
        lblPollingTime = new QLabel(centralWidget);
        lblPollingTime->setObjectName(QStringLiteral("lblPollingTime"));
        lblPollingTime->setGeometry(QRect(250, 30, 131, 16));
        numElevation = new QSpinBox(centralWidget);
        numElevation->setObjectName(QStringLiteral("numElevation"));
        numElevation->setGeometry(QRect(80, 240, 131, 24));
        numElevation->setMaximum(254);
        numElevation->setValue(20);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 557, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        btnConnect->setText(QApplication::translate("MainWindow", "Connect!", 0));
        btnDisconnect->setText(QApplication::translate("MainWindow", "Disconnect!", 0));
        lblThortle->setText(QApplication::translate("MainWindow", "Throtle", 0));
        lblRudder->setText(QApplication::translate("MainWindow", "Rudder", 0));
        lblAileron->setText(QApplication::translate("MainWindow", "Aileron", 0));
        lblElevator->setText(QApplication::translate("MainWindow", "Elevator", 0));
        Elevation->setText(QApplication::translate("MainWindow", "Elevation", 0));
        lblPollingTime->setText(QApplication::translate("MainWindow", "Polling Time: 10", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
