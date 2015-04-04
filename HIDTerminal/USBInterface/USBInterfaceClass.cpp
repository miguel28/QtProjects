#include "USBInterfaceClass.h"

vector<USBDevice> USBInterface::EnumerateHIDs() // List All HID Devices conected in the computer
{
    vector<USBDevice> devs;

    Devs = hid_enumerate(0x0, 0x0);
    CurDev = Devs;
    while (CurDev)
    {
        printf("Device Found\n  type: %04hx %04hx\n  path: %s\n  serial_number: %ls",
            CurDev->vendor_id, CurDev->product_id, CurDev->path, CurDev->serial_number);
        printf("\n");
        printf("  Manufacturer: %ls\n", CurDev->manufacturer_string);
        printf("  Product:      %ls\n", CurDev->product_string);
        printf("\n");

        USBDevice dev;

        dev.VendorID = CurDev->vendor_id;
        dev.ProductID = CurDev->product_id;

        char temp[255];
        sprintf(temp,"%ls", CurDev->manufacturer_string);
        dev.Manufacturer = temp;

        sprintf(temp,"%ls", CurDev->product_string);
        dev.Name = temp;

        devs.push_back(dev);

        CurDev = CurDev->next;
    }

    hid_free_enumeration(Devs);
    return devs;
}

USBInterface::USBInterface(unsigned short vendor,unsigned short product,unsigned short repLength)
        : reportLength(repLength), vendorID(vendor), productID(product)
{
    BufferOUT = new unsigned char[reportLength + 1];
    BufferIN = new unsigned char[reportLength + 1];

    IsOpen = false;
	Error = false;
	DeviceHandle = NULL;
    //Devs = NULL;
    //CurDev = NULL;

	CleanBufferOUT();
	CleanBufferIN();
}
USBInterface::~USBInterface()
{
    Close();
    delete BufferOUT;
    delete BufferIN;
}



void USBInterface::Open()
{
    if(!IsOpen)
    {
        DeviceHandle = hid_open(vendorID, productID, NULL);
        if(DeviceHandle)IsOpen= true;
    }
}

void USBInterface::ReOpen()
{
    if(IsOpen)
        Close();
	DeviceHandle = hid_open(vendorID, productID, NULL);
	if(DeviceHandle)
	{
        IsOpen=true;
		Error = false;
	}
}


void USBInterface::Description()
{
    if(IsOpen)
    {
        hid_get_manufacturer_string(DeviceHandle, wstr, MAX_STR);
        printf("Manufacturer String: %ls\n", wstr);
        hid_get_product_string(DeviceHandle, wstr, MAX_STR);
        printf("Product String: %ls\n", wstr);
        hid_get_serial_number_string(DeviceHandle, wstr, MAX_STR);
        printf("Serial String: %ls\n", wstr);
    }
}

void USBInterface::Close()
{
     if(IsOpen)
     {
        hid_close(DeviceHandle);
        hid_set_nonblocking(DeviceHandle,1);
        IsOpen= false;
     }
}

void USBInterface::CleanBufferOUT()
{
    int i;
    for(i=0; i<reportLength; i++)BufferOUT[i]=0x00;
}

void USBInterface::CleanBufferIN()
{
    int i;
    for(i=0; i<reportLength; i++)BufferIN[i]=0x00;
}

int USBInterface::SendBuffer()
{
    int Result;
    if(IsOpen)
	{
        BufferOUT[0]=0x00;
        Result = hid_write(DeviceHandle, BufferOUT, reportLength + 1);
	}
    else Result = -1;
	
	if(Result <0) Error = true;
	else Error = false;
	
	return Result;
}

int USBInterface::ReciveBuffer()
{
    int Result;
	
	CleanBufferIN();
    if(IsOpen && !Error)
    {
        //Result = hid_read_timeout(DeviceHandle, BufferIN, 65,1);
        Result = hid_read(DeviceHandle, BufferIN, reportLength + 1);
    }
    else Result = -1;
	
	if(Result < 0) Error = true;
	else Error = false;
	
	return Result;
}

void USBInterface::SetByte(unsigned short Position, unsigned char Data)
{
    if(IsOpen && Position <= reportLength + 1)
    {
        BufferOUT[Position+1]=Data;
    }
    else return;
}

unsigned char USBInterface::GetByte(unsigned short Position)
{
    if(IsOpen && Position <= reportLength + 1)
    {
        return BufferIN[Position];
    }
    else return 0x00;
}

void USBInterface::WriteString(string str)
{
    if (str.length() > reportLength)
        return;

    CleanBufferOUT();
    int i;
    for(i=0; i< (int)str.length(); i++)
        BufferOUT[i] = str.c_str()[i];

    SendBuffer();
}
string USBInterface::ReadString()
{
    ReciveBuffer();
    string ret = "";

    int i;
    for(i=0; i< this->reportLength; i++)
        ret += BufferIN[i];

    return ret;
}


/*
 *  Stream Write Methods
 */

void USBInterface::StreamWriteBegin()
{
    CleanBufferOUT();
    WStreamPointer = 1;
}
void USBInterface::StreamWriteChar(char c)
{
    if (WStreamPointer < reportLength + 1)
    {
        BufferOUT[WStreamPointer] = c;
        WStreamPointer++;
    }
}
void USBInterface::StreamWriteInt16(short num)
{
    if (WStreamPointer + 1 < reportLength+1)
    {
        BufferOUT[WStreamPointer] = ((num >> 8) & 0xff);
        WStreamPointer++;
        BufferOUT[WStreamPointer] = (num & 0xff);
        WStreamPointer++;
    }
}
void USBInterface::StreamWriteInt32(int num)
{
    if (WStreamPointer + 3 < reportLength + 1)
    {
        BufferOUT[WStreamPointer] = ((num >> 24) & 0xff);
        WStreamPointer++;
        BufferOUT[WStreamPointer] = ((num >> 16) & 0xff);
        WStreamPointer++;
        BufferOUT[WStreamPointer] = ((num >> 8) & 0xff);
        WStreamPointer++;
        BufferOUT[WStreamPointer] = (num&0xff);
        WStreamPointer++;
    }
}

/*
 *  Stream Read Methods
 */
void USBInterface::StreamReadBegin()
{
    RStreamPointer = 0;
}
char USBInterface::StreamReadChar()
{
    char ret = ' ';
    if (RStreamPointer < reportLength + 1)
    {
        ret = (char)BufferIN[RStreamPointer];
        RStreamPointer++;
    }
    return ret;
}
short USBInterface::StreamReadInt16()
{
    short ret = 0;
    if (RStreamPointer + 3 < reportLength + 1)
    {
        ret |= (short)(BufferIN[RStreamPointer] << 8);
        RStreamPointer++;
        ret |= (short)(BufferIN[RStreamPointer]);
        RStreamPointer++;
    }
    return ret;
}
int USBInterface::StreamReadInt32()
{
    int ret = 0;
    if (RStreamPointer + 3 < reportLength + 1)
    {
        ret |= (int)(BufferIN[RStreamPointer] << 24);
        RStreamPointer++;
        ret |= (int)(BufferIN[RStreamPointer] << 16);
        RStreamPointer++;
        ret |= (int)(BufferIN[RStreamPointer] << 8);
        RStreamPointer++;
        ret |= (int)(BufferIN[RStreamPointer]);
        RStreamPointer++;
    }
    return ret;
}
