#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(ui->btnDisconnect, SIGNAL(released()), this, SLOT(Disconnect()));
    connect(ui->btnConnect, SIGNAL(released()), this, SLOT(Connect()));
    connect(ui->dialPolling,SIGNAL(sliderMoved(int)),this,SLOT(PollingChanged(int)));
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerTimeout()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TimerTimeout()
{
    //usb->WriteString("Hello World!\n");
    usb->StreamWriteBegin();
    usb->StreamWriteChar(0x31);
    usb->StreamWriteChar(0x32);
    usb->StreamWriteChar((char)ui->sldThrotle->value());
    usb->StreamWriteChar((char)ui->sldRudder->value());
    usb->StreamWriteChar((char)ui->sldAileron->value());
    usb->StreamWriteChar((char)ui->sldElevator->value());
    usb->StreamWriteChar((char)ui->numElevation->value());
    usb->StreamWriteChar(0x00);
    usb->StreamWriteChar(0x00);
    usb->StreamWriteChar(0x00);

    /*usb->StreamWriteChar(0x30);
    usb->StreamWriteChar(0x32);
    usb->StreamWriteChar(0x33);
    usb->StreamWriteChar(0x34);
    usb->StreamWriteChar(0x35);
    usb->StreamWriteChar(0x36);
    usb->StreamWriteChar(0x37);
    usb->StreamWriteChar(0x38);
    usb->StreamWriteChar(0x39);
    usb->StreamWriteChar(0x40);*/

    usb->SendBuffer();
}

void MainWindow::PollingChanged(int value)
{
    ui->lblPollingTime->setText("Polling Time: "+QString::number(value));
    if(usb && usb->IsOpen)
    {
        timer->stop();
        timer->start(value);
    }
}

void MainWindow::Connect()
{
    usb = new USBInterface(0x3995,0x0020);
    usb->EnumerateHIDs();
    usb->Open();
    if(usb->IsOpen)
    {
        timer->start(ui->dialPolling->value());
        ui->btnDisconnect->setEnabled(true);
        ui->btnConnect->setEnabled(false);
    }
}

void MainWindow::Disconnect()
{
    timer->stop();
    delete usb;

    ui->btnDisconnect->setEnabled(false);
    ui->btnConnect->setEnabled(true);
}


/*
void MainWindow::PopulateDevices()
{
    USBInterface *usb = new USBInterface(0x01,0x01);
    devs = usb->EnumerateHIDs();

    QStringList List;
    for (vector<USBDevice>::iterator i = devs.begin(); i != devs.end(); ++i)
        List << QString::fromUtf8(i->Name.c_str()) + " (" + QString::number(i->VendorID,16) + "," +QString::number(i->ProductID,16) + ")";

    model->setStringList(List);
    delete usb;
}

void MainWindow::ConnectToSelectedDevice()
{
    foreach(const QModelIndex &index, ui->lstDevices->selectionModel()->selectedIndexes())
        cout << index.row() << endl;
}*/
