#include <QCoreApplication>
#include "USBInterface/USBInterfaceClass.h"
#include <iostream>
using namespace std;

USBInterface Usb;
int main(int argc, char *argv[])
{
    cout << "Oppeng"<<endl;
    QCoreApplication a(argc, argv);
    cout << "Oppeng"<<endl;
    Usb.HIDOpen(0xfeab,0x04d8);
    cout << "Oppeng"<<endl;
    Usb.ReciveBuffer();
    cout << "Oppeng"<<endl;
    Usb.PrintBufferIN();
    while(0)
    {
        Usb.ReciveBuffer();
        Usb.PrintBufferIN();
    }

    //return a.exec();
}
