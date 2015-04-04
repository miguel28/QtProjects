#ifndef DEVICEFILE_H
#define DEVICEFILE_H

#include<iostream>
using namespace std;

typedef struct
{
       int VersionMajor;
       int VersionMinor;
       int VersionDot;
       string VersionNotes;
       int NumberFamilies;
       int NumberParts;
       int NumberScripts;
       char Compatibility;
       char UNUSED1A;
       unsigned short UNUSED1B;
       unsigned int UNUSED2;
}DeviceFileParams;

typedef struct
{
       unsigned short FamilyID;
       unsigned short FamilyType;
       unsigned short SearchPriority;
       string FamilyName;
       unsigned short ProgEntryScript;
       unsigned short ProgExitScript;
       unsigned short ReadDevIDScript;
       unsigned int DeviceIDMask;
       unsigned int BlankValue;
       char BytesPerLocation;
       char AddressIncrement;
       bool PartDetect;
       unsigned short ProgEntryVPPScript;
       unsigned short UNUSED1;
       char EEMemBytesPerWord;
       char EEMemAddressIncrement;
       char UserIDHexBytes;
       char UserIDBytes;
       char ProgMemHexBytes;
       char EEMemHexBytes;
       char ProgMemShift;
       unsigned int TestMemoryStart;
       unsigned short TestMemoryLength;
       float Vpp;
}DeviceFamilyParams;

typedef struct
{
       string PartName;
       unsigned short Family;
       unsigned int DeviceID;
       unsigned int ProgramMem;
       unsigned short EEMem;
       unsigned int EEAddr;
       char ConfigWords;
       unsigned int ConfigAddr;
       char UserIDWords;
       unsigned int UserIDAddr;
       unsigned int BandGapMask;
       unsigned short *ConfigMasks;//
       unsigned short *ConfigBlank;//
       unsigned short CPMask;
       char CPConfig;
       bool OSSCALSave;
       unsigned int IgnoreAddress;
       float VddMin;
       float VddMax;
       float VddErase;
       char CalibrationWords;
       unsigned short ChipEraseScript;
       unsigned short ProgMemAddrSetScript;
       char ProgMemAddrBytes;
       unsigned short ProgMemRdScript;
       unsigned short ProgMemRdWords;
       unsigned short EERdPrepScript;
       unsigned short EERdScript;
       unsigned short EERdLocations;
       unsigned short UserIDRdPrepScript;
       unsigned short UserIDRdScript;
       unsigned short ConfigRdPrepScript;
       unsigned short ConfigRdScript;
       unsigned short ProgMemWrPrepScript;
       unsigned short ProgMemWrScript;
       unsigned short ProgMemWrWords;
       char ProgMemPanelBufs;
       unsigned int ProgMemPanelOffset;
       unsigned short EEWrPrepScript;
       unsigned short EEWrScript;
       unsigned short EEWrLocations;
       unsigned short UserIDWrPrepScript;
       unsigned short UserIDWrScript;
       unsigned short ConfigWrPrepScript;
       unsigned short ConfigWrScript;
       unsigned short OSCCALRdScript;
       unsigned short OSCCALWrScript;
       unsigned short DPMask;
       bool WriteCfgOnErase;
       bool BlankCheckSkipUsrIDs;
       unsigned short IgnoreBytes;
       unsigned short ChipErasePrepScript;
       unsigned int BootFlash;
       unsigned int UNUSED4;
       unsigned short ProgMemEraseScript;
       unsigned short EEMemEraseScript;
       unsigned short ConfigMemEraseScript;
       unsigned short reserved1EraseScript;
       unsigned short reserved2EraseScript;
       unsigned short TestMemoryRdScript;
       unsigned short TestMemoryRdWords;
       unsigned short EERowEraseScript;
       unsigned short EERowEraseWords;
       bool ExportToMPLAB;
       unsigned short DebugHaltScript;
       unsigned short DebugRunScript;
       unsigned short DebugStatusScript;
       unsigned short DebugReadExecVerScript;
       unsigned short DebugSingleStepScript;
       unsigned short DebugBulkWrDataScript;
       unsigned short DebugBulkRdDataScript;
       unsigned short DebugWriteVectorScript;
       unsigned short DebugReadVectorScript;
       unsigned short DebugRowEraseScript;
       unsigned short DebugRowEraseSize;
       unsigned short DebugReserved5Script;
       unsigned short DebugReserved6Script;
       unsigned short DebugReserved7Script;
       unsigned short DebugReserved8Script;
       unsigned short DebugReserved9Script;
}DevicePartParams;

typedef struct
{
       unsigned short ScriptNumber;
       string ScriptName;
       unsigned short ScriptVersion;
       unsigned int UNUSED1;
       unsigned short ScriptLength;
       unsigned short *Script;////
       string Comment;
}DeviceScripts;


class DeviceFile
{
public:
    DeviceFileParams Info;
    DeviceFamilyParams *Families;
    DevicePartParams *PartsList;
    DeviceScripts *Scripts;

    DeviceFile();
};

#endif // DEVICEFILE_H
