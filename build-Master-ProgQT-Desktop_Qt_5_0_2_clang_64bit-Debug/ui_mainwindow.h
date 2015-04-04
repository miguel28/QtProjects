/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Hex_File;
    QAction *actionSave_Hex_File;
    QAction *actionQuit;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabControl;
    QPushButton *btnVerify;
    QPushButton *btnDelete;
    QPushButton *btnDeleted;
    QPushButton *btnWrite;
    QPushButton *btnAutoProg;
    QLabel *lblState;
    QPushButton *pushButton_7;
    QPushButton *btnAutoConnect;
    QFrame *frmDevice;
    QProgressBar *progressBar;
    QLabel *label_2;
    QPushButton *btnRead;
    QWidget *tabFlash;
    QWidget *tabEeprom;
    QWidget *tabZIF;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(601, 467);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionOpen_Hex_File = new QAction(MainWindow);
        actionOpen_Hex_File->setObjectName(QStringLiteral("actionOpen_Hex_File"));
        actionSave_Hex_File = new QAction(MainWindow);
        actionSave_Hex_File->setObjectName(QStringLiteral("actionSave_Hex_File"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 551, 391));
        tabControl = new QWidget();
        tabControl->setObjectName(QStringLiteral("tabControl"));
        btnVerify = new QPushButton(tabControl);
        btnVerify->setObjectName(QStringLiteral("btnVerify"));
        btnVerify->setGeometry(QRect(140, 10, 141, 51));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Icons/verified.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnVerify->setIcon(icon);
        btnVerify->setIconSize(QSize(32, 32));
        btnDelete = new QPushButton(tabControl);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setGeometry(QRect(10, 60, 131, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../Icons/DeleteRed.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelete->setIcon(icon1);
        btnDelete->setIconSize(QSize(32, 32));
        btnDeleted = new QPushButton(tabControl);
        btnDeleted->setObjectName(QStringLiteral("btnDeleted"));
        btnDeleted->setGeometry(QRect(140, 60, 141, 51));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../Icons/Cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDeleted->setIcon(icon2);
        btnDeleted->setIconSize(QSize(32, 32));
        btnWrite = new QPushButton(tabControl);
        btnWrite->setObjectName(QStringLiteral("btnWrite"));
        btnWrite->setGeometry(QRect(10, 110, 131, 51));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../Icons/Arrow Down.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWrite->setIcon(icon3);
        btnWrite->setIconSize(QSize(32, 32));
        btnAutoProg = new QPushButton(tabControl);
        btnAutoProg->setObjectName(QStringLiteral("btnAutoProg"));
        btnAutoProg->setGeometry(QRect(140, 110, 141, 51));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../../../Icons/system-software-update.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAutoProg->setIcon(icon4);
        btnAutoProg->setIconSize(QSize(32, 32));
        lblState = new QLabel(tabControl);
        lblState->setObjectName(QStringLiteral("lblState"));
        lblState->setGeometry(QRect(290, 10, 241, 91));
        lblState->setFrameShape(QFrame::StyledPanel);
        lblState->setFrameShadow(QFrame::Sunken);
        lblState->setTextFormat(Qt::PlainText);
        lblState->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lblState->setMargin(0);
        pushButton_7 = new QPushButton(tabControl);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(280, 110, 131, 51));
        pushButton_7->setIconSize(QSize(32, 32));
        btnAutoConnect = new QPushButton(tabControl);
        btnAutoConnect->setObjectName(QStringLiteral("btnAutoConnect"));
        btnAutoConnect->setGeometry(QRect(410, 110, 131, 51));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../../../Icons/USB1.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAutoConnect->setIcon(icon5);
        btnAutoConnect->setIconSize(QSize(32, 32));
        frmDevice = new QFrame(tabControl);
        frmDevice->setObjectName(QStringLiteral("frmDevice"));
        frmDevice->setGeometry(QRect(20, 160, 511, 151));
        frmDevice->setFrameShape(QFrame::StyledPanel);
        frmDevice->setFrameShadow(QFrame::Raised);
        progressBar = new QProgressBar(tabControl);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 320, 511, 23));
        progressBar->setValue(50);
        label_2 = new QLabel(tabControl);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 340, 62, 16));
        btnRead = new QPushButton(tabControl);
        btnRead->setObjectName(QStringLiteral("btnRead"));
        btnRead->setGeometry(QRect(10, 10, 134, 51));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../../../Icons/Upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRead->setIcon(icon6);
        btnRead->setIconSize(QSize(32, 32));
        tabWidget->addTab(tabControl, QString());
        tabFlash = new QWidget();
        tabFlash->setObjectName(QStringLiteral("tabFlash"));
        tabFlash->setContextMenuPolicy(Qt::CustomContextMenu);
        tabWidget->addTab(tabFlash, QString());
        tabEeprom = new QWidget();
        tabEeprom->setObjectName(QStringLiteral("tabEeprom"));
        tabWidget->addTab(tabEeprom, QString());
        tabZIF = new QWidget();
        tabZIF->setObjectName(QStringLiteral("tabZIF"));
        tabWidget->addTab(tabZIF, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 601, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_Hex_File);
        menuFile->addAction(actionSave_Hex_File);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(btnAutoConnect, SIGNAL(clicked()), MainWindow, SLOT(sigAutoConnect()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen_Hex_File->setText(QApplication::translate("MainWindow", "Open Hex File", 0));
        actionSave_Hex_File->setText(QApplication::translate("MainWindow", "Save Hex File", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        btnVerify->setText(QApplication::translate("MainWindow", "Verify", 0));
        btnDelete->setText(QApplication::translate("MainWindow", "Delete", 0));
        btnDeleted->setText(QApplication::translate("MainWindow", "Deleted?", 0));
        btnWrite->setText(QApplication::translate("MainWindow", "Write", 0));
        btnAutoProg->setText(QApplication::translate("MainWindow", "Auto Program", 0));
        lblState->setText(QApplication::translate("MainWindow", "Master Prog QT+", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "PushButton", 0));
        btnAutoConnect->setText(QApplication::translate("MainWindow", "AutoConnect", 0));
        label_2->setText(QApplication::translate("MainWindow", "Progress", 0));
        btnRead->setText(QApplication::translate("MainWindow", "Read Hex", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabControl), QApplication::translate("MainWindow", "Control", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabFlash), QApplication::translate("MainWindow", "Flash", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabEeprom), QApplication::translate("MainWindow", "Eeprom", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabZIF), QApplication::translate("MainWindow", "ZIF", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
