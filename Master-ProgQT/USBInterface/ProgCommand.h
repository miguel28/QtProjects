#ifndef PROGCOMMAND_H
#define PROGCOMMAND_H

#include "USBInterface/USBInterfaceClass.h"
#include "USBInterface/DeviceFile.h"



class ProgCommand : public USBInterface
{
public:
    ProgCommand();
    bool writeUSB(char* commandList, int commandSize);
    void ReadDeviceFile();
private:
    float vddLastSet;
    bool SetVDDVoltage(float voltage, float threshold);
    unsigned short CalculateVddCPP(float voltage);


    int *familySearchTable;
    DeviceFile DevFile;


};

#endif // PROGCOMMAND_H
