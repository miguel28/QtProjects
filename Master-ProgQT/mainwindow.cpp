#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "USBInterface/ProgCommand.h"

ProgCommand USB; //= new ProgCommand();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sigAutoConnect();

    /*QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.bin)"));
    */

    USB.ReadDeviceFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::sigAutoConnect()
{
    //USB->EnumerateHIDs();
    USB.HIDOpen(0x1234,0x0033);
    USB.HIDDescription();
    if(USB.HIDisOpen)ui->lblState->setText("Master-Prog connected");
    else ui->lblState->setText("Master-Prog not connected");
}
