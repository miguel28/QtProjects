#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>
#include <QString>
#include <QLabel>
#include <QTextEdit>
#include <QMessageBox>
#include <QLineEdit>
#include <QSlider>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QPushButton *btnConnect, *btnDisconnect, *btnSend;
    QLineEdit *txtMsg;
    QSlider *slider;
    QLabel* lblHid, *lblSpeed, *lblSend;

    QTimer *myTimer;

    void Pwm();
    void SendBuffer(std::string Text);
    char OutBuffer[16];
    char out, Tout, Latch;
    bool MessageSending, ReadyToSend;
    short StateCounter, MsgCounter;

private slots:
    void sigConnectButton();
    void sigDisonnectButton();
    void sigSendBuffer();
    void timerTimeout();
};

#endif // MAINWINDOW_H
