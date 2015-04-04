#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "USBInterface/USBInterfaceClass.h"

#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QTimer>
#include <QDial>

#include <QMainWindow>

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
    Ui::MainWindow *ui;
    QTimer *timer;
    USBInterface *usb;

private slots:
    void TimerTimeout();
    void Connect();
    void Disconnect();
    void PollingChanged(int value);
};

#endif // MAINWINDOW_H
