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
    QPushButton *btnConnect, *btnDisconnect;
    QPushButton *inputButtons[8];
    QLabel* lblHid;
    QTimer *myTimer;
private slots:
    void sigConnectButton();
    void sigDisonnectButton();
    void timerTimeout();
};

#endif // MAINWINDOW_H
