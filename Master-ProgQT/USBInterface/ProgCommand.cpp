#include "ProgCommand.h"
#include "USBInterface/BinaryReader.h"

BinaryReader binaryReader;

ProgCommand::ProgCommand()
{
    vddLastSet = 3.3f;
}

bool ProgCommand::writeUSB(char* commandList, int commandSize)
{
    BufferOUT[0]=0x00;
    int i;

    for (i = 1; i< 65; ++i)
        BufferOUT[i]=(unsigned char) 173;
    for (i = 1; i< commandSize+1; ++i)
        BufferOUT[i]=(unsigned char) commandList[i];

    if(SendBuffer() < 0)
        return false;
    else
        return true;
}

bool ProgCommand::SetVDDVoltage(float voltage, float threshold)
{
    if ((double) voltage < 2.5) voltage = 2.5f;
    vddLastSet = voltage;

    unsigned short CalculatedVDD = CalculateVddCPP(voltage);

    char num2 = (char) ((double) threshold * (double) voltage / 5.0 * (double) 255);

    if ((int) num2 > 210) num2 = (char) 210;

    char *TempCommand = new char[4];

    TempCommand[0] = (char) 160;
    TempCommand[1] = (char) ((unsigned int) CalculatedVDD & (unsigned) 255);
    TempCommand[2] = (char) (char) ((unsigned int) CalculatedVDD / 256U);
    TempCommand[4] = (char) num2;

    return writeUSB(TempCommand,4);
}

unsigned short ProgCommand::CalculateVddCPP(float voltage)
{
      return (unsigned short) ((unsigned int) (unsigned short) ((double) voltage * 32.0 + 10.5) << 6);
}

void ProgCommand::ReadDeviceFile()
{
    binaryReader.OpenFile("../../../Dispositivos.bin2");

    DevFile.Info.VersionMajor = binaryReader.ReadInt32();
    DevFile.Info.VersionMinor = binaryReader.ReadInt32();
    DevFile.Info.VersionDot = binaryReader.ReadInt32();
    DevFile.Info.VersionNotes = binaryReader.ReadString();
    DevFile.Info.NumberFamilies = binaryReader.ReadInt32();
    DevFile.Info.NumberParts = binaryReader.ReadInt32();
    DevFile.Info.NumberScripts = binaryReader.ReadInt32();
    DevFile.Info.Compatibility = binaryReader.ReadByte();
    DevFile.Info.UNUSED1A = binaryReader.ReadByte();
    DevFile.Info.UNUSED1B = binaryReader.ReadUInt16();
    DevFile.Info.UNUSED2 = binaryReader.ReadUInt32();

    //DeviceFileVersion = string.Format("{0:D1}.{1:D2}.{2:D2}", (object) ProgCommand.DevFile.Info.VersionMajor, (object) ProgCommand.DevFile.Info.VersionMinor, (object) ProgCommand.DevFile.Info.VersionDot);
    DevFile.Families = new DeviceFamilyParams[DevFile.Info.NumberFamilies];
    DevFile.PartsList = new DevicePartParams[DevFile.Info.NumberParts];
    DevFile.Scripts = new DeviceScripts[DevFile.Info.NumberScripts];

    int index=0; //DevFile.Info.NumberFamilies
    for (index = 0; index < DevFile.Info.NumberFamilies; ++index)
    {
        DevFile.Families[index].FamilyID = binaryReader.ReadUInt16(); // 267
        DevFile.Families[index].FamilyType = binaryReader.ReadUInt16(); //269
        DevFile.Families[index].SearchPriority = binaryReader.ReadUInt16(); //271
        DevFile.Families[index].FamilyName = binaryReader.ReadString();//273 -
        DevFile.Families[index].ProgEntryScript = binaryReader.ReadUInt16();
        DevFile.Families[index].ProgExitScript = binaryReader.ReadUInt16();
        DevFile.Families[index].ReadDevIDScript = binaryReader.ReadUInt16();
        DevFile.Families[index].DeviceIDMask = binaryReader.ReadUInt32();
        DevFile.Families[index].BlankValue = binaryReader.ReadUInt32();
        DevFile.Families[index].BytesPerLocation = binaryReader.ReadByte();
        DevFile.Families[index].AddressIncrement = binaryReader.ReadByte();
        DevFile.Families[index].PartDetect = binaryReader.ReadBoolean();
        DevFile.Families[index].ProgEntryVPPScript = binaryReader.ReadUInt16();
        DevFile.Families[index].UNUSED1 = binaryReader.ReadUInt16();
        DevFile.Families[index].EEMemBytesPerWord = binaryReader.ReadByte();
        DevFile.Families[index].EEMemAddressIncrement = binaryReader.ReadByte();
        DevFile.Families[index].UserIDHexBytes = binaryReader.ReadByte();
        DevFile.Families[index].UserIDBytes = binaryReader.ReadByte();
        DevFile.Families[index].ProgMemHexBytes = binaryReader.ReadByte();
        DevFile.Families[index].EEMemHexBytes = binaryReader.ReadByte();
        DevFile.Families[index].ProgMemShift = binaryReader.ReadByte();
        DevFile.Families[index].TestMemoryStart = binaryReader.ReadUInt32();
        DevFile.Families[index].TestMemoryLength = binaryReader.ReadUInt16();
        DevFile.Families[index].Vpp = binaryReader.ReadSingle();
    }

    familySearchTable = new int[DevFile.Info.NumberFamilies];

    for(index = 0; index < DevFile.Info.NumberFamilies; ++index)
        familySearchTable[(int) DevFile.Families[index].SearchPriority] = index;
    int index1;
    for (index1 = 0; index1 < DevFile.Info.NumberParts; ++index1)
    {
        DevFile.PartsList[index1].PartName = binaryReader.ReadString();
        DevFile.PartsList[index1].Family = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DeviceID = binaryReader.ReadUInt32();
        DevFile.PartsList[index1].ProgramMem = binaryReader.ReadUInt32();
        DevFile.PartsList[index1].EEMem = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].EEAddr = binaryReader.ReadUInt32();
        DevFile.PartsList[index1].ConfigWords = binaryReader.ReadByte();
        DevFile.PartsList[index1].ConfigAddr = binaryReader.ReadUInt32();
        DevFile.PartsList[index1].UserIDWords = binaryReader.ReadByte();
        DevFile.PartsList[index1].UserIDAddr = binaryReader.ReadUInt32();
        DevFile.PartsList[index1].BandGapMask = binaryReader.ReadUInt32();
        DevFile.PartsList[index1].ConfigMasks = new unsigned short[8];
        DevFile.PartsList[index1].ConfigBlank = new unsigned short[8];

        for (int index2 = 0; index2 < 8; ++index2)
            DevFile.PartsList[index1].ConfigMasks[index2] = binaryReader.ReadUInt16();

        for (int index2 = 0; index2 < 8; ++index2)
            DevFile.PartsList[index1].ConfigBlank[index2] = binaryReader.ReadUInt16();

        DevFile.PartsList[index1].CPMask = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].CPConfig = binaryReader.ReadByte();
        DevFile.PartsList[index1].OSSCALSave = binaryReader.ReadBoolean();
        DevFile.PartsList[index1].IgnoreAddress = binaryReader.ReadUInt32();
        DevFile.PartsList[index1].VddMin = binaryReader.ReadSingle();
        DevFile.PartsList[index1].VddMax = binaryReader.ReadSingle();
        DevFile.PartsList[index1].VddErase = binaryReader.ReadSingle();
        DevFile.PartsList[index1].CalibrationWords = binaryReader.ReadByte();
        DevFile.PartsList[index1].ChipEraseScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ProgMemAddrSetScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ProgMemAddrBytes = binaryReader.ReadByte();
        DevFile.PartsList[index1].ProgMemRdScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ProgMemRdWords = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].EERdPrepScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].EERdScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].EERdLocations = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].UserIDRdPrepScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].UserIDRdScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ConfigRdPrepScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ConfigRdScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ProgMemWrPrepScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ProgMemWrScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ProgMemWrWords = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ProgMemPanelBufs = binaryReader.ReadByte();
        DevFile.PartsList[index1].ProgMemPanelOffset = binaryReader.ReadUInt32();
        DevFile.PartsList[index1].EEWrPrepScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].EEWrScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].EEWrLocations = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].UserIDWrPrepScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].UserIDWrScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ConfigWrPrepScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ConfigWrScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].OSCCALRdScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].OSCCALWrScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DPMask = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].WriteCfgOnErase = binaryReader.ReadBoolean();
        DevFile.PartsList[index1].BlankCheckSkipUsrIDs = binaryReader.ReadBoolean();
        DevFile.PartsList[index1].IgnoreBytes = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ChipErasePrepScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].BootFlash = binaryReader.ReadUInt32();
        DevFile.PartsList[index1].UNUSED4 = binaryReader.ReadUInt32();
        DevFile.PartsList[index1].ProgMemEraseScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].EEMemEraseScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ConfigMemEraseScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].reserved1EraseScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].reserved2EraseScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].TestMemoryRdScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].TestMemoryRdWords = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].EERowEraseScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].EERowEraseWords = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].ExportToMPLAB = binaryReader.ReadBoolean();
        DevFile.PartsList[index1].DebugHaltScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugRunScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugStatusScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugReadExecVerScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugSingleStepScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugBulkWrDataScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugBulkRdDataScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugWriteVectorScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugReadVectorScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugRowEraseScript = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugRowEraseSize = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugReserved5Script = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugReserved6Script = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugReserved7Script = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugReserved8Script = binaryReader.ReadUInt16();
        DevFile.PartsList[index1].DebugReserved9Script = binaryReader.ReadUInt16();
    }
    for (index1 = 0; index1 < DevFile.Info.NumberScripts; ++index1)
    {
        DevFile.Scripts[index1].ScriptNumber = binaryReader.ReadUInt16();
        DevFile.Scripts[index1].ScriptName = binaryReader.ReadString();
        DevFile.Scripts[index1].ScriptVersion = binaryReader.ReadUInt16();
        DevFile.Scripts[index1].UNUSED1 = binaryReader.ReadUInt32();
        DevFile.Scripts[index1].ScriptLength = binaryReader.ReadUInt16();
        DevFile.Scripts[index1].Script = new unsigned short[(int) DevFile.Scripts[index1].ScriptLength];
        for (int index2 = 0; index2 < (int) DevFile.Scripts[index1].ScriptLength; ++index2)
            DevFile.Scripts[index1].Script[index2] = binaryReader.ReadUInt16();
        DevFile.Scripts[index1].Comment = binaryReader.ReadString();
     }

//*/
}
