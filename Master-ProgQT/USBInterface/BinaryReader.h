#ifndef BINARYREADER_H
#define BINARYREADER_H

#include <iostream>
#include <fstream>
using namespace std;

class BinaryReader
{
private:
    ifstream streamFile;
    int FileLenght;
    char *FileBuffer;
    int FilePos;
public:
    BinaryReader();
    bool OpenFile(string strFileName);
    void Reset();
    void SetPos(int nPos);
    int GetPos();

    int ReadInt32();
    string ReadString();
    char ReadByte();
    unsigned short ReadUInt16();
    unsigned int ReadUInt32();
    bool ReadBoolean();
    double ReadSingle();
};

#endif // BINARYREADER_H
