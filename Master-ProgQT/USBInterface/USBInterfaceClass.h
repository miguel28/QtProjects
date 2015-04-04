/*
USB Class Interface
Version 1.1
Miguel Inc.
*/
#ifndef USBINTERFACE_H
#define USBINTERFACE_H

#include <iostream>
#include <stdio.h>
#include "hidapi.h"

#define MAX_STR 255

enum PLC_MODES
{
   SIMPLE_PLC_MODE,
   ANALOG_PLC_MODE,
   SIMPLE_ASME_DRIVER,
   ANALOG_ASME_DRIVER
};

class USBInterface
{
	public:
    int i;
	int res;
	unsigned char BufferOUT[65];
	unsigned char BufferIN[65];
	wchar_t wstr[MAX_STR];
	hid_device *DeviceHandle;
	struct hid_device_info *Devs, *CurDev;
	bool HIDisOpen;
	USBInterface();
	~USBInterface();
	void EnumerateHIDs(); // List All HID Devices conected in the computer
	void HIDOpen(const unsigned short VendorID, const unsigned short ProductID); // Open Specific HID device to work
	void HIDDescription();
	void HIDClose(); // Close the device of work
      
	int SendBuffer(); // Send BufferOUT to the HID
	int SendOutputPort(const unsigned char Value);
	void CleanBufferOUT();
	void CleanBufferIN();
      
	int ReciveBuffer();
	void PrintBufferIN();
	unsigned char GetInputBuffer();
};
#endif
