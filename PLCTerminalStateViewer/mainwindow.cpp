#include <QTimer>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "USBInterface/USBInterfaceClass.h"

using namespace std;
USBInterface* USB = new USBInterface;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(QString::fromUtf8("Checkable QPushButton Example"));
        resize(400,300);

        QWidget* centralWidget = new QWidget(this);
        centralWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        QVBoxLayout* layout = new QVBoxLayout(centralWidget);

        QHBoxLayout* hLayout = new QHBoxLayout();
        layout->addLayout(hLayout);

        btnConnect = new QPushButton("Connect HID");
        btnDisconnect = new QPushButton("Disconnet HID");

        lblHid = new QLabel("HID does not opended!");
        layout->addWidget(lblHid);

        hLayout->addWidget(btnConnect);
        hLayout->addWidget(btnDisconnect);
        hLayout->addWidget(lblHid);

        QHBoxLayout* hLayoutInputs = new QHBoxLayout();
        layout->addLayout(hLayoutInputs);

        int i;
        for(i = 0; i<8; i++)
        {
            QString temptext;
            temptext.append("Bit ");
            temptext.append(QString::number(i));

            inputButtons[i] = new QPushButton(temptext);
            inputButtons[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            inputButtons[i]->setCheckable(true);
            hLayoutInputs->addWidget(inputButtons[i]);

        }
        myTimer = new QTimer;
        myTimer->setInterval(10);

        setCentralWidget(centralWidget);
        connect(btnConnect, SIGNAL(clicked()), this, SLOT(sigConnectButton()));
        connect(btnDisconnect, SIGNAL(clicked()), this, SLOT(sigDisonnectButton()));
        connect(myTimer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::sigConnectButton()
{
    USB->EnumerateHIDs();
    USB->HIDOpen(0x3995,0x0001);
    USB->HIDDescription();
    if(USB->HIDisOpen)
    {
        lblHid->setText("HID Opened: VendorID:0x3995 ProductID:0x0001");
        myTimer->start(10);
    }
    else lblHid->setText("Error: HID does not Opened");

    /*USB->SendOutputPort((unsigned char) 0x01);
    usleep(1000000);
    USB->SendOutputPort((unsigned char) 0x02);
    usleep(1000000);

    USB->ReciveBuffer();
    USB->PrintBufferIN();
    usleep(20000);
    USB->ReciveBuffer();
    USB->PrintBufferIN();*/
}
void MainWindow::sigDisonnectButton()
{
    if(USB->HIDisOpen) lblHid->setText("HID Closed");
    myTimer->stop();
    USB->HIDClose();
}

void MainWindow::timerTimeout()
{
    int i;
    char cOutputBuffer = 0x00;
    for(i = 0; i<8; i++)
    {
        cOutputBuffer|=inputButtons[i]->isChecked()<<i;
    }
    USB->SendOutputPort(cOutputBuffer);
    cout << cOutputBuffer << endl;
}
