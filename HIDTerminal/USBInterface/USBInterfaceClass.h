/*
USB Class Interface
Version 1.1
Miguel Inc.
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include "hidapi.h"

#define MAX_STR 255
using namespace std;

typedef struct
{
    unsigned short ProductID, VendorID;
    string Name, Manufacturer;
}USBDevice;

USBDevice* EnumerateHIDs();

class USBInterface
{
public:
    bool IsOpen;
	bool Error;
	
    USBInterface(unsigned short vendor, unsigned short product, unsigned short repLength = 64);
    USBInterface(USBDevice device, short repLength = 64);
	~USBInterface();

    hid_device_info *Devs, *CurDev;

    vector<USBDevice> EnumerateHIDs();

    void Open(); // Open Specific HID device to work
    void ReOpen();
    void Description();
    void Close(); // Close the device of work
      
	int SendBuffer(); // Send BufferOUT to the HID
	int ReciveBuffer();
	
	void CleanBufferOUT();
	void CleanBufferIN();

	void SetByte(unsigned short Position, unsigned char Data);
	unsigned char GetByte(unsigned short Position);

    void WriteString(string str);
    string ReadString();

    void StreamWriteBegin();
    void StreamWriteChar(char c);
    void StreamWriteInt16(short num);
    void StreamWriteInt32(int num);

    void StreamReadBegin();
    char StreamReadChar();
    short StreamReadInt16();
    int StreamReadInt32();

private:

    unsigned char* BufferOUT;
    unsigned char* BufferIN;

    unsigned short reportLength;
	hid_device *DeviceHandle;
	wchar_t wstr[MAX_STR];

	unsigned short vendorID;
	unsigned short productID;

    int WStreamPointer;
    int RStreamPointer;
};
