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
#include <stdio.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    QPushButton* buttons[64];
    QPushButton *btnCreate, *btnClear;
    QTextEdit* txtBox;
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handleButton();
    void clearButton();
};



#endif // MAINWINDOW_H
