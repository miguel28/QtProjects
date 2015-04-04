#include "BinaryReader.h"
#include <stdio.h>

BinaryReader::BinaryReader()
{
}

bool BinaryReader::OpenFile(string strFileName)
{
    ///"Dispositivos.bin
    streamFile.open (strFileName.c_str(), ios::in | ios::out | ios::binary);
    if(streamFile.is_open())
    {
        streamFile.seekg(0,streamFile.end);
        FileLenght = streamFile.tellg();
        streamFile.seekg(0,streamFile.beg);
        FileBuffer = new char[FileLenght];

        streamFile.read (FileBuffer, FileLenght);

        streamFile.close();
        FilePos = 0;
        cout << "BinaryReader.Open >> Opened" << endl;
        return true;
    }
    else
    {
        cout << "BinaryReader.Open >> Error" << endl;
        return false;
    }
}

void BinaryReader::Reset()
{
    FilePos = 0;
}

void BinaryReader::SetPos(int nPos)
{
    FilePos = nPos;
}
int BinaryReader::GetPos()
{
    return FilePos;
}

int BinaryReader::ReadInt32()
{
    static int retInt = 0;
    retInt = (int)( (FileBuffer[FilePos + 3]<<24 & 0xFF000000) | (FileBuffer[FilePos + 2]<<16 & 0x00FF0000)
                  | (FileBuffer[FilePos + 1]<<8 & 0x0000FF00) | (FileBuffer[FilePos] & 0x000000FF) );

    /*cout << (int)FileBuffer[FilePos] << hex << endl;
    cout << (int)FileBuffer[FilePos+1] << hex << endl;
    cout << (int)FileBuffer[FilePos+2] << hex << endl;
    cout << (int)FileBuffer[FilePos+3] << hex << endl;
*/
    FilePos += 4;

    cout << "ReadInt32() >> " << retInt << " at -> " << FilePos - 4 << endl;

    return retInt;
}

string BinaryReader::ReadString()
{
    static int strLength = 0;
    static int i;
    string retString = "";

    strLength = (int)(FileBuffer[FilePos] & 0x000000FF);
    FilePos++;
    if((FileBuffer[FilePos] & 0x000000FF) == 0x01)
    {
        FilePos++;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    }
    cout << "strLength: "<< strLength << endl;

    char *Tempstring=  new char[strLength+1];
    for(i = 0; i<= strLength; i++)
    {
         Tempstring[i] = FileBuffer[FilePos + i];
    }
    Tempstring[strLength+1] = 0x0A;
    cout << endl;


    FilePos += strLength;
    //retString.append(Tempstring);
    retString = Tempstring;
    cout << "ReadString() >> " << retString  << "_at ->" << FilePos - (strLength) << endl;
    delete Tempstring;
    return retString;
}
char BinaryReader::ReadByte()
{
    char retChar = FileBuffer[FilePos];
    FilePos++;

    cout << "ReadByte() >> " << (int)retChar << " at -> " << FilePos - 1 <<endl;

    return retChar;
}
unsigned short BinaryReader::ReadUInt16()
{
    unsigned short retInt;
    retInt = (unsigned short) ( (FileBuffer[FilePos + 1]<<8 & 0x0000FF00) | (FileBuffer[FilePos] & 0x000000FF) );
    FilePos += 2;

    cout << "ReadUInt16() >> " << retInt << " at -> " << FilePos -2 <<endl;

    return retInt;
}
unsigned int BinaryReader::ReadUInt32()
{
    unsigned int retInt;
    retInt = (unsigned int)( (FileBuffer[FilePos + 3]<<24 & 0xFF000000) | (FileBuffer[FilePos + 2]<<16 & 0x00FF0000)
            | (FileBuffer[FilePos + 1]<<8 & 0x0000FF00) | (FileBuffer[FilePos] & 0x000000FF) );
    FilePos += 4;

    cout << "ReadUInt32() >> " << retInt << " at -> " << FilePos -4 <<endl;

    return retInt;
}
bool BinaryReader::ReadBoolean()
{
    bool retBool = (bool)FileBuffer[FilePos];
    FilePos++;

    cout << "ReadByte() >> " << retBool << " at -> " << FilePos -1 <<endl;

    return retBool;
}

union u_double
{
    double  dbl;
    char    data[sizeof(double)];
};

static void dump_double(union u_double d)
{
    int exp;
    long long mant;

    printf("64-bit float: sign: %d, ", (d.data[0] & 0x80) >> 7);
    exp = ((d.data[0] & 0x7F) << 4) | ((d.data[1] & 0xF0) >> 4);
    printf("expt: %4d (unbiassed %5d), ", exp, exp - 1023);
    mant = ((((d.data[1] & 0x0F) << 8) | (d.data[2] & 0xFF)) << 8) | (d.data[3] & 0xFF);
    mant = (mant << 32) | ((((((d.data[4] & 0xFF) << 8) | (d.data[5] & 0xFF)) << 8) | (d.data[6] & 0xFF)) << 8) | (d.data[7] & 0xFF);
    printf("mant: %16lld (0x%013llX)\n", mant, mant);
}

double BinaryReader::ReadSingle()
{
    union u_double d;
    int i;
    for(i = 0; i<sizeof(double); i++)
        d.data[i] = FileBuffer[FilePos + i];
    dump_double(d);
    FilePos += sizeof(double);
    //cout << "double test: " <<(int)(Test) << " size " << sizeof(double) << endl;
    cout << "ReadDouble() >> " << d.dbl << " at -> " << FilePos -8 <<endl;

    return d.dbl;
}

