#include <QTimer>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "USBInterface/USBInterfaceClass.h"

using namespace std;
USBInterface* USB = new USBInterface;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    StateCounter = 0;
    setWindowTitle(QString::fromUtf8("Propel Clock Server"));
    resize(400,200);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    QHBoxLayout* hLayout = new QHBoxLayout();
    layout->addLayout(hLayout);

    btnConnect = new QPushButton("Connect HID");
    btnDisconnect = new QPushButton("Disconnet HID");

    lblHid = new QLabel("HID does not opended!");

    hLayout->addWidget(btnConnect);
    hLayout->addWidget(btnDisconnect);
    hLayout->addWidget(lblHid);

    lblSend = new QLabel("Send Message:");
    //lblSend->setFont();
    layout->addWidget(lblSend);

    txtMsg = new QLineEdit("Hola");
    txtMsg->setMaxLength(16);
    layout->addWidget(txtMsg);

    btnSend = new QPushButton("Send");
    layout->addWidget(btnSend );

    lblSpeed = new QLabel("Speed Motor");
    layout->addWidget(lblSpeed);

    slider = new QSlider(Qt::Horizontal);
    slider->setValue(33);
    layout->addWidget(slider);


    myTimer = new QTimer;
    myTimer->setInterval(15);

    setCentralWidget(centralWidget);
    connect(btnConnect, SIGNAL(clicked()), this, SLOT(sigConnectButton()));
    connect(btnDisconnect, SIGNAL(clicked()), this, SLOT(sigDisonnectButton()));
    connect(btnSend, SIGNAL(clicked()), this, SLOT(sigSendBuffer()));
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
    StateCounter++;
    if(StateCounter>=67)StateCounter = 0;

    int msec = slider->value()*10;
    if(StateCounter*15 <msec)Latch=0x01;
    else Latch=0x00;

    if(ReadyToSend&&StateCounter==0)
    {
        MessageSending = true;
    }

    if(MessageSending)
    {
        MsgCounter++;
        switch(MsgCounter)
        {
            ////////////////
            case 0:
                Tout = 0x0F;
                break;
            case 1:
                Tout = 0x0E;
                break;
            ///////////////
            case 2:
                Tout = 0x0F;
                break;
            case 3:
                Tout = 0x0D;
                break;
            case 4:
                Tout = OutBuffer[0]&0x0F;
                break;
            case 5:
                Tout = (OutBuffer[0]&0xF0)>>4;
                break;
            case 6:
                MsgCounter = -1;
                MessageSending = false;
                ReadyToSend = false;
                break;

        }
    }
    else Tout = 0x0F;

    out = (Latch<<4)|Tout;

    USB->SendOutputPort((unsigned char) out);

}
void MainWindow::SendBuffer(std::string Text)
{
    int i;
    std::string temp;
    int Dummy = (int)(8-(Text.length()/2));
    for(i = 0; i< Dummy; i++)
        temp.append(" ");

    temp.append(Text);
    for(i = Dummy + Text.length(); i< 16; i++)
        temp.append(" ");

    for(i=0; i<16; i++)
    {
        OutBuffer[0] = temp[0];
    }

}

void MainWindow::sigSendBuffer()
{
    SendBuffer(txtMsg->text().toStdString());
    ReadyToSend=true;
    MsgCounter=-1;
}
