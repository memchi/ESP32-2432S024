/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  https://github.com/moononournation/Arduino_GFX
  https://docs.lvgl.io/master/intro/index.html
  https://mfreiholz.de/posts/network-protocol-parser/
  https://forum.arduino.cc/t/serial-input-basics-updated/382007/3
  https://forum.arduino.cc/t/uart-parsing/651603
  https://forum.arduino.cc/t/parsing-serial-data-and-separating-it-into-variables
  https://forum.arduino.cc/t/reading-and-parsing-serial-data
  https://en.wikipedia.org/wiki/Circular_buffer
  https://stackoverflow.com/questions/2974061/protocol-parsing-in-c
  https://www.best-microcontroller-projects.com/how-rs232-works.html
  https://www.dwin-global.com/5-inch-800480-hmi-capacitiveresistive-touch-screen-with-shell-model-dmt80480t050_39w-industrial-grade-product/
  https://docs.lvgl.io/8.3/widgets/extra/index.html
  https://github.com/search?q=guition&type=repositories
  https://github.com/memchi/JC8048W550
  https://drive.google.com/drive/folders/1FuEiwhcZruFBRC5mb5fepqiw0Z9yaoAN
  https://www.arduino.cc/reference/en/language/functions/communication/serial/
  ------------------------------------------------------------------------------
  Reverse seems to be only on popup
  Charging seems to be only on popup
  Trip KM?
  Whole KM?
  Battery?
  Battery temp?
  Light switch?
  Voltage?
  Motor (Problem)?
  --------------------------------------------------------------------------- */
#pragma once
// -----------------------------------------------------------------------------
// provide common datatype not available in ESP32 < 3
typedef  unsigned char      uint8_t;
typedef  unsigned short     uint16_t;
// -----------------------------------------------------------------------------
// settings for the serial port
#define EVOKEDISPLAY_SERIAL_SPEED 115200
#define EVOKEDISPLAY_SERIALBUFFER_SIZE 1024
// -----------------------------------------------------------------------------
// settings for the parsing buffer
#define BUFFERSIZE 2048
char InBuffer[BUFFERSIZE];
static uint16_t InBufferUse = 0;
// -----------------------------------------------------------------------------
// settings for the dump (log) buffer
#define DUMPBUFFERSIZE 256
char DumpBuffer[DUMPBUFFERSIZE];
static uint16_t DumpBufferUse = 0;
// -----------------------------------------------------------------------------
// Command 80, 2 byte
bool Buffer80020B00Changed = false;
uint8_t Buffer80020B00[3] = { 0xFF, 0xFF };
// Command 80, 3 byte
bool Buffer800300Changed = false;
uint8_t Buffer800300[3] = { 0xFF, 0xFF, 0xFF };
bool Buffer80030B00Changed = false;
uint8_t Buffer80030B00[3] = { 0xFF, 0xFF, 0xFF };
// Command 82, 3 / 4 uint16_t
bool Buffer820000SpeedChanged = false; // Speed
uint16_t Buffer820000Speed[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer820002TripKmChanged = false;
uint16_t Buffer820002TripKm[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer820006Changed = false;
uint16_t Buffer820006[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer820008Changed = false;
uint16_t Buffer820008[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer82000ATemperatureChanged = false;
uint16_t Buffer82000ATemperature[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer82000CChanged = false;
uint16_t Buffer82000C[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer82000ECurrentChanged = false;
uint16_t Buffer82000ECurrent[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer820010Changed = false;
uint16_t Buffer820010[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer820012KickstandDownChanged = false;
uint16_t Buffer820012KickstandDown[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer820016IndicatorLeftChanged = false;
uint16_t Buffer820016IndicatorLeft[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer820018IndicatorRightChanged = false;
uint16_t Buffer820018IndicatorRight[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer82001AHighBeamChanged = false;
uint16_t Buffer82001AHighBeam[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer82001CChanged = false;
uint16_t Buffer82001C[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer820025Changed = false;
uint16_t Buffer820025[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer820027TotalKmChanged = false;
uint16_t Buffer820027TotalKm[4] = { 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer820070HighPowerChanged = false;
uint16_t Buffer820070HighPower[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
bool Buffer820072KillSwitchChanged = false;
uint16_t Buffer820072KillSwitch[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
// text field 009A unbuffered
bool Buffer8200F8ChargeChanged = false;
uint16_t Buffer8200F8Charge[3] = { 0xFFFF, 0xFFFF, 0xFFFF };
// text field 00FE unbuffered
// -----------------------------------------------------------------------------
// seems to be useless, just at startup
void (*OnEvokeDisplayProtocol80020B00Event)(uint8_t Data0, uint8_t Data1);
// -----------------------------------------------------------------------------
// seems to be useless, just at startup
void (*OnEvokeDisplayProtocol800300Event)(uint8_t Data0, uint8_t Data1, uint8_t Data2);
// -----------------------------------------------------------------------------
// seems to be useless, just at startup
void (*OnEvokeDisplayProtocol80030B00Event)(uint8_t Data0, uint8_t Data1, uint8_t Data2);
// -----------------------------------------------------------------------------
// often command, 6 byte payload, speed value
void (*OnEvokeDisplayProtocol0000SpeedEvent)(uint16_t Data0, uint16_t Data1, uint16_t Data2);  // 0000
// -----------------------------------------------------------------------------
// often command, 6 byte payload, [01][00][09][82][00][02][00][00][00][00][C0][C8] (12)
void (*OnEvokeDisplayProtocol0002TripKmEvent)(uint16_t Data0, uint16_t Data1, uint16_t Data2);  // 0002
// -----------------------------------------------------------------------------
// often command, 6 byte payload,  [01][00][09][82][00][06][00][00][00][05][F1][0B]
void (*OnEvokeDisplayProtocol0006Event)(uint16_t Data0, uint16_t Data1, uint16_t Data2);  // 0006
// -----------------------------------------------------------------------------
// often command, 6 byte payload, [01][00][09][82][00][08][00][00][00][00][58][C9] (12)
void (*OnEvokeDisplayProtocol0008Event)(uint16_t Data0, uint16_t Data1, uint16_t Data2);  // 0008
// -----------------------------------------------------------------------------
// often command, 6 byte payload, [01][00][09][82][00][0A][00][00][00][16][A0][C7] (12), [01][00][09][82][00][0A][00][00][00][15][E0][C6] (12), [01][00][09][82][00][0A][00][00][00][14][21][06] (12)
void (*OnEvokeDisplayProtocol000ATemperatureEvent)(uint16_t Data0, uint16_t Data1, uint16_t Data2);  // 000A
// -----------------------------------------------------------------------------
// often command, 6 byte payload, [01][00][09][82][00][0C][00][00][00][00][A9][09] (12)
void (*OnEvokeDisplayProtocol000CEvent)(uint16_t Data0, uint16_t Data1, uint16_t Data2);  // 000C
// -----------------------------------------------------------------------------
// often command, 6 byte payload, could be the current, [01][00][09][82][00][0E][00][00][00][00][D0][C9] (12), [01][00][09][82][00][0E][00][00][00][04][D1][0A] (12), [01][00][09][82][00][0E][00][00][00][07][91][0B] (12), [01][00][09][82][00][0E][00][00][00][0D][11][0C] (12)
void (*OnEvokeDisplayProtocol000ECurrentEvent)(uint16_t Data0, uint16_t Data1, uint16_t Data2);  // 000E
// -----------------------------------------------------------------------------
// once command, 6 byte payload, [01][00][09][82][00][10][00][00][00][00][78][CB] (12)
void (*OnEvokeDisplayProtocol0010Event)(uint16_t Data0, uint16_t Data1, uint16_t Data2);  // 0010
// -----------------------------------------------------------------------------
// KickstandDown:
// Down: ByteCount: 0x09, Command: 0x82, RamAddress: 0x0012, Data: [00000000][00000000][00000000][00000001][11000000][11001011] [00][00][00][01][C0][CB]
// UP: ByteCount: 0x09, Command: 0x82, RamAddress: 0x0012, Data: [00000000][00000000][00000000][00000000][00000001][00001011] [00][00][00][00][01][0B]
void (*OnEvokeDisplayProtocol0012KickstandDownEvent)(bool Value);  // 0012
// -----------------------------------------------------------------------------
// Indicator left
//ON: ByteCount: 0x09, Command: 0x82, RamAddress: 0x0016, Data: [00000000][00000000][00000000][00000001][00110001][00001011] [00][00][00][01]1[0B]
// OFF: ByteCount: 0x09, Command: 0x82, RamAddress: 0x0016, Data: [00000000][00000000][00000000][00000000][11110000][11001011] [00][00][00][00][F0][CB]
void (*OnEvokeDisplayProtocol0016IndicatorLeftEvent)(bool Value);  // 0016
// -----------------------------------------------------------------------------
// Indicator right
// ByteCount: 0x09, Command: 0x82, RamAddress: 0x0018, Data: [00000000][00000000][00000000][00000001][01011000][11001010] [00][00][00][01]X[CA]
// ByteCount: 0x09, Command: 0x82, RamAddress: 0x0018, Data: [00000000][00000000][00000000][00000000][10011001][00001010] [00][00][00][00][99][0A]
void (*OnEvokeDisplayProtocol0018IndicatorRightEvent)(bool Value);  // 0018
// -----------------------------------------------------------------------------
// once command, 6 byte payload, [01][00][09][82][00][1A][00][00][00][00][E0][CA] (12)
void (*OnEvokeDisplayProtocol001AHighBeamEvent)(bool Value);  // 001A
// -----------------------------------------------------------------------------
// often command, 6 byte payload
void (*OnEvokeDisplayProtocol001CEvent)(uint16_t Data0, uint16_t Data1, uint16_t Data2);  // 001C
// -----------------------------------------------------------------------------
// once command, 6 byte payload, [01][00][09][82][00][25][00][00][00][00][F4][CF] (12)
void (*OnEvokeDisplayProtocol0025Event)(uint16_t Data0, uint16_t Data1, uint16_t Data2);  // 0025
// -----------------------------------------------------------------------------
// often command, 8 byte payload, seems always: [01][00][0B][82][00][27][00][00][00][00][00][5E][A4][AC] (14)
void (*OnEvokeDisplayProtocol0027TotalKmEvent)(uint16_t Data0, uint16_t Data1, uint16_t Data2, uint16_t Data3);  // 0027
// -----------------------------------------------------------------------------
// often command, 6 byte payload
// ByteCount: 0x09, Command: 0x82, RamAddress: 0x0070, Data: [00000000][00000000][00000000][00000010][01111001][00000010] [00][00][00][02]y[02]
// ByteCount: 0x09, Command: 0x82, RamAddress: 0x0070, Data: [00000000][00000000][00000000][00000001][00111001][00000011] [00][00][00][01]9[03]
void (*OnEvokeDisplayProtocol0070HighPowerEvent)(bool Value);  // 0070
// -----------------------------------------------------------------------------
// seldom command, 6 byte payload
// ByteCount: 0x09, Command: 0x82, RamAddress: 0x0072, Data: [00000000][00000000][00000000][00000001][01000000][11000011] [00][00][00][01]@[C3]
// ByteCount: 0x09, Command: 0x82, RamAddress: 0x0072, Data: [00000000][00000000][00000000][00000000][10000001][00000011] [00][00][00][00][81][03]
void (*OnEvokeDisplayProtocol0072KillSwitchEvent)(bool Value);  // 0072
// -----------------------------------------------------------------------------
// once command, 100 byte length (94 byte payload), seems to undo errors, [01][00][61][82][00][9A][00][00][00][00][CA][D4][0D][80][40][43][FD][3F][78][7E][FC][3F][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][FF][FF][E5][BB] (100)
void (*OnEvokeDisplayProtocol009AEvent)(char * TextData); // 009A
// -----------------------------------------------------------------------------
// often command, 6 byte payload
void (*OnEvokeDisplayProtocol00F8ChargeEvent)(uint16_t Data0, uint16_t Data1, uint16_t Data2);  // 00F8
// -----------------------------------------------------------------------------
// once command, 100 byte length (94 byte payload)
// 13:52:50.778 sFrame: [01][00][61][82][00][FE][00][00][20][45][33][30][34][20][4B][49][43][4B][53][54][41][4E][44][20][44][4F][57][4E][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][FF][FF][FB][93] (100)
// 13:52:50.778 ByteCount: 0x61, Command: 0x82, RamAddress: 0x00FE, Data: [00][00] E304 KICKSTAND DOWN[00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][FF][FF][FB][93]
// -----
// 13:53:15.743 sFrame: [01][00][61][82][00][FE][00][00][20][20][45][33][30][35][20][4B][49][4C][4C][53][57][49][54][43][48][20][4F][4E][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][FF][FF][D9][C1] (100)
// 13:53:15.743 ByteCount: 0x61, Command: 0x82, RamAddress: 0x00FE, Data: [00][00]  E305 KILLSWITCH ON[00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][FF][FF][D9][C1]
// Reset:
// 13:53:21.872 sFrame: [01][00][61][82][00][FE][00][00][20][20][20][20][20][20][20][20][20][20][20][00][09][80][70][43][FD][3F][78][7E][FC][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][FF][FF][11][C0] (100)
// 13:53:21.878 ByteCount: 0x61, Command: 0x82, RamAddress: 0x00FE, Data: [00][00]           [00][09][80]pC[FD]?x[7E][FC][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][00][FF][FF][11][C0]
void (*OnEvokeDisplayProtocol00FESetTextEvent)(char * TextData); // 00FE
// -----------------------------------------------------------------------------
// trace event
void (*OnEvokeDisplayProtocolTrace)(char * TextData);
// -----------------------------------------------------------------------------
void EvokeDisplayProtocolTrace(const char * format, ...) {
  //https://en.wikipedia.org/wiki/Variadic_function
  // http://www.swig.org/Doc1.3/Varargs.html
#define DEBUGBUFFERLENGTH 255
#define ARGUMENTBUFFERLENGTH DEBUGBUFFERLENGTH - 20
  char ArgumentBuffer[ARGUMENTBUFFERLENGTH];
  va_list args;
  va_start(args, format);
  vsnprintf(ArgumentBuffer, ARGUMENTBUFFERLENGTH, format, args);
  va_end(args);
  uint32_t Millis = millis();
  uint32_t Seconds = Millis / 1000;
  Millis = Millis - (Seconds * 1000);
  char DebugBuffer[DEBUGBUFFERLENGTH];
  sprintf(DebugBuffer, "%u.%03us %s ", Seconds, Millis, ArgumentBuffer);
  OnEvokeDisplayProtocolTrace(DebugBuffer);
}
// -----------------------------------------------------------------------------
// write to a two byte buffer and set changed accordingly
void BufferTwoByte(uint8_t * DataBuffer, bool & Changed, uint8_t Data0, uint8_t Data1) {
  if ((DataBuffer[0] != Data0) || (DataBuffer[1] != Data1)) {
    Changed = true;
    DataBuffer[0] = Data0;
    DataBuffer[1] = Data1;
  }
}
// -----------------------------------------------------------------------------
// write to a three byte buffer and set changed accordingly
void BufferThreeByte(uint8_t * DataBuffer, bool & Changed, uint8_t Data0, uint8_t Data1, uint8_t Data2) {
  if ((DataBuffer[0] != Data0) || (DataBuffer[1] != Data1) || (DataBuffer[2] != Data2)) {
    Changed = true;
    DataBuffer[0] = Data0;
    DataBuffer[1] = Data1;
    DataBuffer[2] = Data2;
  }
}
// -----------------------------------------------------------------------------
// write to a three uint16 buffer and set changed accordingly
void BufferThreeUInt16(uint16_t * DataBuffer, bool & Changed, uint16_t Data0, uint16_t Data1, uint16_t Data2) {
  if ((DataBuffer[0] != Data0) || (DataBuffer[1] != Data1) || (DataBuffer[2] != Data2)) {
    Changed = true;
    DataBuffer[0] = Data0;
    DataBuffer[1] = Data1;
    DataBuffer[2] = Data2;
  }
}
// -----------------------------------------------------------------------------
// write to a four uint16 buffer and set changed accordingly
void BufferFourUInt16(uint16_t * DataBuffer, bool & Changed, uint16_t Data0, uint16_t Data1, uint16_t Data2, uint16_t Data3) {
  if ((DataBuffer[0] != Data0) || (DataBuffer[1] != Data1) || (DataBuffer[2] != Data2) || (DataBuffer[3] != Data3)) {
    Changed = true;
    DataBuffer[0] = Data0;
    DataBuffer[1] = Data1;
    DataBuffer[2] = Data2;
    DataBuffer[3] = Data3;
  }
}
// -----------------------------------------------------------------------------
void EDPFrameFound(uint8_t Command, uint16_t RamAddress, char * Framedata, uint8_t FrameDataUse) {
  //TRACE(tlDEBUG, pfSTART, "Command: %02X, RamAddress: %04X, FrameData: %02X %02X %02X %02X %02X %02X (%d)", Command, RamAddress, Framedata[0], Framedata[1], Framedata[2], Framedata[3], Framedata[4], Framedata[5], FrameDataUse);
  uint16_t UIntData0 = 0;
  uint16_t UIntData1 = 0;
  uint16_t UIntData2 = 0;
  uint16_t UIntData3 = 0;
  char TextData[101];
  switch (Command) {
  case 0x80:
    switch (FrameDataUse) {
    case 0x02:
      switch (RamAddress) {
      case 0x0B00:
        BufferTwoByte(Buffer80020B00, Buffer80020B00Changed, (uint8_t)Framedata[0], (uint8_t)Framedata[1]);
        break;
      default:
        TRACE(tlWARNING, pfNONE, "Unknown command %02X, use %02X, ramaddr %04X", Command, FrameDataUse, RamAddress);
        EvokeDisplayProtocolTrace("Unknown command %02X, use %02X, ramaddr %04X", Command, FrameDataUse, RamAddress);
      }
    case 0x03:
      switch (RamAddress) {
      case 0x0300:
        BufferThreeByte(Buffer800300, Buffer800300Changed, (uint8_t)Framedata[0], (uint8_t)Framedata[1], (uint8_t)Framedata[2]);
        break;
      case 0x0B00:
        BufferThreeByte(Buffer80030B00, Buffer80030B00Changed, (uint8_t)Framedata[0], (uint8_t)Framedata[1], (uint8_t)Framedata[2]);
        break;
      default:
        TRACE(tlWARNING, pfNONE, "Unknown command %02X, use %02X, ramaddr %04X", Command, FrameDataUse, RamAddress);
        EvokeDisplayProtocolTrace("Unknown command %02X, use %02X, ramaddr %04X", Command, FrameDataUse, RamAddress);
      }
      break;
    default:
      TRACE(tlWARNING, pfNONE, "Unknown command %02X, use %02X", Command, FrameDataUse);
      EvokeDisplayProtocolTrace("Unknown command %02X, use %02X", Command, FrameDataUse);
    }
    break;
  case 0x82:
    switch (FrameDataUse) {
    case 0x06:
      UIntData0 = ((uint16_t)Framedata[0] * 0x100) + (uint16_t)Framedata[1];
      UIntData1 = ((uint16_t)Framedata[2] * 0x100) + (uint16_t)Framedata[3];
      UIntData2 = ((uint16_t)Framedata[4] * 0x100) + (uint16_t)Framedata[5];
      //TRACE(tlDEBUG, pfNONE, "D0: %04X (%d), D1: %04X (%d), D2: %04X (%d)", UIntData0, UIntData0, UIntData1, UIntData1, UIntData2, UIntData2);
      switch (RamAddress) {
      case 0x0000:
        BufferThreeUInt16(Buffer820000Speed, Buffer820000SpeedChanged, UIntData0, UIntData1, UIntData2);
        break;
      case 0x0002:
        BufferThreeUInt16(Buffer820002TripKm, Buffer820002TripKmChanged, UIntData0, UIntData1, UIntData2);
        break;
      case 0x0006:
        BufferThreeUInt16(Buffer820006, Buffer820006Changed, UIntData0, UIntData1, UIntData2);
        break;
      case 0x0008:
        BufferThreeUInt16(Buffer820008, Buffer820008Changed, UIntData0, UIntData1, UIntData2);
        break;
      case 0x000A:
        BufferThreeUInt16(Buffer82000ATemperature, Buffer82000ATemperatureChanged, UIntData0, UIntData1, UIntData2);
        break;
      case 0x000C:
        BufferThreeUInt16(Buffer82000C, Buffer82000CChanged, UIntData0, UIntData1, UIntData2);
        break;
      case 0x000E:
        BufferThreeUInt16(Buffer82000ECurrent, Buffer82000ECurrentChanged, UIntData0, UIntData1, UIntData2);
        break;
      case 0x0010:
        BufferThreeUInt16(Buffer820010, Buffer820010Changed, UIntData0, UIntData1, UIntData2);
        break;
      case 0x0012:
        BufferThreeUInt16(Buffer820012KickstandDown, Buffer820012KickstandDownChanged, UIntData0, UIntData1, UIntData2);
        break;
      case 0x0016:
        BufferThreeUInt16(Buffer820016IndicatorLeft, Buffer820016IndicatorLeftChanged, UIntData0, UIntData1, UIntData2);
        break;
      case 0x0018:
        BufferThreeUInt16(Buffer820018IndicatorRight, Buffer820018IndicatorRightChanged, UIntData0, UIntData1, UIntData2);
        break;
      case 0x001A:
        BufferThreeUInt16(Buffer82001AHighBeam, Buffer82001AHighBeamChanged, UIntData0, UIntData1, UIntData2);
        break;
      case 0x001C:
        BufferThreeUInt16(Buffer82001C, Buffer82001CChanged, UIntData0, UIntData1, UIntData2);
        break;
      case 0x0025:
        BufferThreeUInt16(Buffer820025, Buffer820025Changed, UIntData0, UIntData1, UIntData2);
        break;
      case 0x0070:
        BufferThreeUInt16(Buffer820070HighPower, Buffer820070HighPowerChanged, UIntData0, UIntData1, UIntData2);
        break;
      case 0x0072:
        BufferThreeUInt16(Buffer820072KillSwitch, Buffer820072KillSwitchChanged, UIntData0, UIntData1, UIntData2);
        break;
      case 0x00F8:
        BufferThreeUInt16(Buffer8200F8Charge, Buffer8200F8ChargeChanged, UIntData0, UIntData1, UIntData2);
        break;
      default:
        TRACE(tlWARNING, pfNONE, "Unknown command %02X, use %02X, ramaddr %04X", Command, FrameDataUse, RamAddress);
        EvokeDisplayProtocolTrace("Unknown command %02X, use %02X, ramaddr %04X", Command, FrameDataUse, RamAddress);
      }
      break;
    case 0x08:
      UIntData0 = ((uint16_t)Framedata[0] * 0x100) + (uint16_t)Framedata[1];
      UIntData1 = ((uint16_t)Framedata[2] * 0x100) + (uint16_t)Framedata[3];
      UIntData2 = ((uint16_t)Framedata[4] * 0x100) + (uint16_t)Framedata[5];
      UIntData3 = ((uint16_t)Framedata[6] * 0x100) + (uint16_t)Framedata[7];
      //TRACE(tlDEBUG, pfNONE, "D0: %04X (%d), D1: %04X (%d), D2: %04X (%d), D3: %04X (%d)", UIntData0, UIntData0, UIntData1, UIntData1, UIntData2, UIntData2, UIntData3, UIntData3);
      switch (RamAddress) {
      case 0x0027:
        BufferFourUInt16(Buffer820027TotalKm, Buffer820027TotalKmChanged, UIntData0, UIntData1, UIntData2, UIntData3);
        break;
      default:
        TRACE(tlWARNING, pfNONE, "Unknown command %02X, use %02X, ramaddr %04X", Command, FrameDataUse, RamAddress);
        EvokeDisplayProtocolTrace("Unknown command %02X, use %02X, ramaddr %04X", Command, FrameDataUse, RamAddress);
      }
      break;
    case 0x5E:
      for (uint16_t i = 0; i <= FrameDataUse - 6; i++) {
        TextData[i] = Framedata[i + 2];
      }
      switch (RamAddress) {
      case 0x009A:
        // no buffering for text event
        OnEvokeDisplayProtocol009AEvent(TextData);
        break;
      case 0x00FE:
        // no buffering for text event
        OnEvokeDisplayProtocol00FESetTextEvent(TextData);
        break;
      default:
        TRACE(tlWARNING, pfNONE, "Unknown command %02X, use %02X, ramaddr %04X", Command, FrameDataUse, RamAddress);
        EvokeDisplayProtocolTrace("Unknown command %02X, use %02X, ramaddr %04X", Command, FrameDataUse, RamAddress);
      }
      break;
    default:
      TRACE(tlWARNING, pfNONE, "Unknown command %02X, use %02X", Command, FrameDataUse);
      EvokeDisplayProtocolTrace("Unknown command %02X, use %02X", Command, FrameDataUse);
    }
    break;
  default:
    TRACE(tlWARNING, pfNONE, "Unknown command %02X", Command);
    EvokeDisplayProtocolTrace("Unknown command %02X", Command);
  }
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void EDPShiftInBuffer(uint16_t Shift) {
  TRACE(tlDEBUG, pfSTART, "InBuffer: %02X %02X %02X %02X %02X %02X .. (%d)", InBuffer[0], InBuffer[1], InBuffer[2], InBuffer[3], InBuffer[4], InBuffer[5], InBufferUse);
  for (uint32_t i = 0; i <= InBufferUse + 1 - Shift; i++) {
    InBuffer[i] = InBuffer[i + Shift];
  }
  InBufferUse = InBufferUse - Shift;
  TRACE(tlDEBUG, pfEND, "InBuffer: %02X %02X %02X %02X %02X %02X .. (%d)", InBuffer[0], InBuffer[1], InBuffer[2], InBuffer[3], InBuffer[4], InBuffer[5], InBufferUse);
}
// -----------------------------------------------------------------------------
bool EDPParseBuffer() {
  TRACE(tlDEBUG, pfSTART, "InBuffer: %02X %02X %02X %02X %02X %02X .. (%d)", InBuffer[0], InBuffer[1], InBuffer[2], InBuffer[3], InBuffer[4], InBuffer[5], InBufferUse);
  bool Result = false;
  while (InBufferUse >= 2 && (InBuffer[0] != 0x01 || InBuffer[1] != 0x00)) {
    if (DumpBufferUse < DUMPBUFFERSIZE) {
      DumpBuffer[DumpBufferUse] = InBuffer[0];
      DumpBufferUse++;
    } else {
      TRACE(tlWARNING, pfNONE, "Dump buffer overflow: %02X", InBuffer[0]);
      EvokeDisplayProtocolTrace("Dump buffer overflow: %02X", InBuffer[0]);
    }
    EDPShiftInBuffer(1);
  }
  if (InBufferUse >= 2 && InBuffer[0] == 0x01 && InBuffer[1] == 0x00) {
    TRACE(tlDEBUG, pfNONE, "Header found: %02X %02X %02X %02X %02X %02X .. (%d)", InBuffer[0], InBuffer[1], InBuffer[2], InBuffer[3], InBuffer[4], InBuffer[5], InBufferUse);
    if (InBufferUse >= 3) {
      if (DumpBufferUse > 0) {
        TRACE(tlNOTICE, pfNONE, "Use: %04X", DumpBufferUse);
        EvokeDisplayProtocolTrace("Use: %04X", DumpBufferUse);
      }
      while (DumpBufferUse > 0) {
        TRACE(tlNOTICE, pfNONE, "Dump: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X",
              DumpBuffer[0x00], DumpBuffer[0x01], DumpBuffer[0x02], DumpBuffer[0x03], DumpBuffer[0x04], DumpBuffer[0x05], DumpBuffer[0x06], DumpBuffer[0x07],
              DumpBuffer[0x08], DumpBuffer[0x09], DumpBuffer[0x0A], DumpBuffer[0x0B], DumpBuffer[0x0C], DumpBuffer[0x0D], DumpBuffer[0x0E], DumpBuffer[0x0F]);
        EvokeDisplayProtocolTrace("Dump: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X",
                                  DumpBuffer[0x00], DumpBuffer[0x01], DumpBuffer[0x02], DumpBuffer[0x03], DumpBuffer[0x04], DumpBuffer[0x05], DumpBuffer[0x06], DumpBuffer[0x07],
                                  DumpBuffer[0x08], DumpBuffer[0x09], DumpBuffer[0x0A], DumpBuffer[0x0B], DumpBuffer[0x0C], DumpBuffer[0x0D], DumpBuffer[0x0E], DumpBuffer[0x0F]);
        uint32_t Shift = 0;
        if (DumpBufferUse < 16) {
          Shift = DumpBufferUse;
        } else {
          Shift =  16;
        }
        for (uint32_t i = 0; i < DumpBufferUse - Shift; i++) {
          DumpBuffer[i] = DumpBuffer[i + Shift];
        }
        DumpBufferUse = DumpBufferUse - Shift;
      }
      uint32_t FrameSize = InBuffer[2] + 3;
      if (InBufferUse >= FrameSize) {
        // https://stackoverflow.com/questions/24890237/pass-char-pointer-array-to-a-function
        uint8_t FrameDataUse = FrameSize - 6;
        char FrameData[94];
        for (uint32_t i = 0; i < FrameDataUse; i++) {  // todo: must loop less
          FrameData[i] = InBuffer[i + 6];
        }
        EDPFrameFound(InBuffer[3], InBuffer[4] * 0x100 + InBuffer[5], FrameData, FrameDataUse);
        EDPShiftInBuffer(FrameSize);
        Result = true;
      }
    }
  }
  TRACE(tlDEBUG, pfEND, "InBuffer: %02X %02X %02X %02X %02X %02X .. (%d)", InBuffer[0], InBuffer[1], InBuffer[2], InBuffer[3], InBuffer[4], InBuffer[5], InBufferUse);
  return Result;
}
// -----------------------------------------------------------------------------
bool CheckBufferThreeUInt16 (uint16_t * DataBuffer, uint16_t * DataBufferPrev) {
  TRACE(tlDEBUG, pfSTART, "");
  bool Result = (DataBuffer[0] != DataBufferPrev[0]) || (DataBuffer[1] != DataBufferPrev[1]) || (DataBuffer[2] != DataBufferPrev[2]);
  if (Result) {
    DataBufferPrev[0] = DataBuffer[0];
    DataBufferPrev[1] = DataBuffer[1];
    DataBufferPrev[2] = DataBuffer[2];
  }
  TRACE(tlDEBUG, pfEND, "Result: %s", BOOL2STR(Result));
  return Result;
}
// -----------------------------------------------------------------------------
bool CheckBufferFourUInt16 (uint16_t * DataBuffer, uint16_t * DataBufferPrev) {
  TRACE(tlDEBUG, pfSTART, "");
  bool Result = (DataBuffer[0] != DataBufferPrev[0]) || (DataBuffer[1] != DataBufferPrev[1]) || (DataBuffer[2] != DataBufferPrev[2]) || (DataBuffer[3] != DataBufferPrev[3]);
  if (Result) {
    DataBufferPrev[0] = DataBuffer[0];
    DataBufferPrev[1] = DataBuffer[1];
    DataBufferPrev[2] = DataBuffer[2];
    DataBufferPrev[3] = DataBuffer[3];
  }
  TRACE(tlDEBUG, pfEND, "Result: %s", BOOL2STR(Result));
  return Result;
}
// -----------------------------------------------------------------------------
void EvokeDisplayProtocolIndicatorLeft(uint16_t Data0, uint16_t Data1, uint16_t Data2) {
  TRACE(tlDEBUG, pfSTART, "");
  // todo
  if (Data1 == 0x0000 && Data2 == 0xF0CB) {
    OnEvokeDisplayProtocol0016IndicatorLeftEvent(false);
  } else if (Data1 == 0x0001 && Data2 == 0x310B) {
    OnEvokeDisplayProtocol0016IndicatorLeftEvent(true);
  } else {
    TRACE(tlWARNING, pfNONE, "IndicatorLeft, unknown data: %04X %04X %04X", Data0, Data1, Data2);
    EvokeDisplayProtocolTrace("IndicatorLeft, unknown data: %04X %04X %04X", Data0, Data1, Data2);
  };
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void EvokeDisplayProtocolIndicatorRight(uint16_t Data0, uint16_t Data1, uint16_t Data2) {
  TRACE(tlDEBUG, pfSTART, "");
  // todo
  if (Data1 == 0x0000 && Data2 == 0x990A) {
    OnEvokeDisplayProtocol0018IndicatorRightEvent(false);
  } else if (Data1 == 0x0001 && Data2 == 0x58CA) {
    OnEvokeDisplayProtocol0018IndicatorRightEvent(true);
  } else {
    TRACE(tlWARNING, pfNONE, "IndicatorRight, unknown data: %04X %04X %04X", Data0, Data1, Data2);
    EvokeDisplayProtocolTrace("IndicatorRight, unknown data: %04X %04X %04X", Data0, Data1, Data2);
  };
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void EvokeDisplayProtocolHighBeam(uint16_t Data0, uint16_t Data1, uint16_t Data2) {
  TRACE(tlDEBUG, pfSTART, "");
  // todo
  if (Data1 == 0x0000 && Data2 == 0xE0CA) {
    OnEvokeDisplayProtocol001AHighBeamEvent(false);
  } else if (Data1 == 0x0001 && Data2 == 0x210A) {
    OnEvokeDisplayProtocol001AHighBeamEvent(true);
  } else {
    TRACE(tlWARNING, pfNONE, "HighBeam, unknown data: %04X %04X %04X", Data0, Data1, Data2);
    EvokeDisplayProtocolTrace("HighBeam, unknown data: %04X %04X %04X", Data0, Data1, Data2);
  };
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void EvokeDisplayProtocolKickstandDown(uint16_t Data0, uint16_t Data1, uint16_t Data2) {
  TRACE(tlDEBUG, pfSTART, "");
  // todo
  if (Data1 == 0x0000 && Data2 == 0x010B) {
    OnEvokeDisplayProtocol0012KickstandDownEvent(false);
  } else if (Data1 == 0x0001 && Data2 == 0xC0CB) {
    OnEvokeDisplayProtocol0012KickstandDownEvent(true);
  } else {
    TRACE(tlWARNING, pfNONE, "KickstandDown, unknown data: %04X %04X %04X", Data0, Data1, Data2);
    EvokeDisplayProtocolTrace("KickstandDown, unknown data: %04X %04X %04X", Data0, Data1, Data2);
  };
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void EvokeDisplayProtocolKillSwitch(uint16_t Data0, uint16_t Data1, uint16_t Data2) {
  TRACE(tlDEBUG, pfSTART, "");
  // todo
  if (Data1 == 0x0000 && Data2 == 0x8103) {
    OnEvokeDisplayProtocol0072KillSwitchEvent(false);
  } else if (Data1 == 0x0001 && Data2 == 0x40C3) {
    OnEvokeDisplayProtocol0072KillSwitchEvent(true);
  } else {
    TRACE(tlWARNING, pfNONE, "KillSwitch, unknown data: %04X %04X %04X", Data0, Data1, Data2);
    EvokeDisplayProtocolTrace("KillSwitch, unknown data: %04X %04X %04X", Data0, Data1, Data2);
  };
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void EvokeDisplayProtocolHighPower(uint16_t Data0, uint16_t Data1, uint16_t Data2) {
  TRACE(tlDEBUG, pfSTART, "");
  if (Data1 == 0x0001 && Data2 == 0x3903) {
    OnEvokeDisplayProtocol0070HighPowerEvent(false);
  } else if (Data1 == 0x0002 && Data2 == 0x7902) {
    OnEvokeDisplayProtocol0070HighPowerEvent(true);
  } else {
    TRACE(tlWARNING, pfNONE, "HighPower, unknown data: %04X %04X %04X", Data0, Data1, Data2);
    EvokeDisplayProtocolTrace("HighPower, unknown data: %04X %04X %04X", Data0, Data1, Data2);
  };
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
// check repetitively for changed values and raise first event
void EDPCheckBuffer() {
  TRACE(tlDEBUG, pfSTART, "");
  if (Buffer820016IndicatorLeftChanged) {
    EvokeDisplayProtocolIndicatorLeft(Buffer820016IndicatorLeft[0], Buffer820016IndicatorLeft[1], Buffer820016IndicatorLeft[2]);
    Buffer820016IndicatorLeftChanged = false;
  } else if (Buffer820018IndicatorRightChanged) {
    EvokeDisplayProtocolIndicatorRight(Buffer820018IndicatorRight[0], Buffer820018IndicatorRight[1], Buffer820018IndicatorRight[2]);
    Buffer820018IndicatorRightChanged = false;
  } else if (Buffer82001AHighBeamChanged) {
    EvokeDisplayProtocolHighBeam(Buffer82001AHighBeam[0], Buffer82001AHighBeam[1], Buffer82001AHighBeam[2]);
    Buffer82001AHighBeamChanged = false;
  } else if (Buffer820070HighPowerChanged) {
    EvokeDisplayProtocolHighPower(Buffer820070HighPower[0], Buffer820070HighPower[1], Buffer820070HighPower[2]);
    Buffer820070HighPowerChanged = false;
  } else if (Buffer820012KickstandDownChanged) {
    EvokeDisplayProtocolKickstandDown(Buffer820012KickstandDown[0], Buffer820012KickstandDown[1], Buffer820012KickstandDown[2]);
    Buffer820012KickstandDownChanged = false;
  } else if (Buffer820072KillSwitchChanged) {
    EvokeDisplayProtocolKillSwitch(Buffer820072KillSwitch[0], Buffer820072KillSwitch[1], Buffer820072KillSwitch[2]);
    Buffer820072KillSwitchChanged = false;
  } else if (Buffer820000SpeedChanged) {
    OnEvokeDisplayProtocol0000SpeedEvent(Buffer820000Speed[0], Buffer820000Speed[1], Buffer820000Speed[2]);
    Buffer820000SpeedChanged = false;
  } else if (Buffer82000ECurrentChanged) {
    OnEvokeDisplayProtocol000ECurrentEvent(Buffer82000ECurrent[0], Buffer82000ECurrent[1], Buffer82000ECurrent[2]);
    Buffer82000ECurrentChanged = false;
  } else if (Buffer80020B00Changed) {
    OnEvokeDisplayProtocol80020B00Event(Buffer80020B00[0], Buffer80020B00[1]);
    Buffer80020B00Changed = false;
  } else if (Buffer800300Changed) {
    OnEvokeDisplayProtocol800300Event(Buffer800300[0], Buffer800300[1], Buffer800300[2]);
    Buffer800300Changed = false;
  } else if (Buffer80030B00Changed) {
    OnEvokeDisplayProtocol80030B00Event(Buffer80030B00[0], Buffer80030B00[1], Buffer80030B00[2]);
    Buffer80030B00Changed = false;
  } else if (Buffer820002TripKmChanged) {
    OnEvokeDisplayProtocol0002TripKmEvent(Buffer820002TripKm[0], Buffer820002TripKm[1], Buffer820002TripKm[2]);
    Buffer820002TripKmChanged = false;
  } else if (Buffer820006Changed) {
    OnEvokeDisplayProtocol0006Event(Buffer820006[0], Buffer820006[1], Buffer820006[2]);
    Buffer820006Changed = false;
  } else if (Buffer820008Changed) {
    OnEvokeDisplayProtocol0008Event(Buffer820008[0], Buffer820008[1], Buffer820008[2]);
    Buffer820008Changed = false;
  } else if (Buffer82000ATemperatureChanged) {
    OnEvokeDisplayProtocol000ATemperatureEvent(Buffer82000ATemperature[0], Buffer82000ATemperature[1], Buffer82000ATemperature[2]);
    Buffer82000ATemperatureChanged = false;
  } else if (Buffer82000CChanged) {
    OnEvokeDisplayProtocol000CEvent(Buffer82000C[0], Buffer82000C[1], Buffer82000C[2]);
    Buffer82000CChanged = false;
  } else if (Buffer820010Changed) {
    OnEvokeDisplayProtocol0010Event(Buffer820010[0], Buffer820010[1], Buffer820010[2]);
    Buffer820010Changed = false;
  } else if (Buffer82001CChanged) {
    OnEvokeDisplayProtocol001CEvent(Buffer82001C[0], Buffer82001C[1], Buffer82001C[2]);
    Buffer82001CChanged = false;
  } else if (Buffer820025Changed) {
    OnEvokeDisplayProtocol0025Event(Buffer820025[1], Buffer820025[1], Buffer820025[2]);
    Buffer820025Changed = false;
  } else if (Buffer820027TotalKmChanged) {
    OnEvokeDisplayProtocol0027TotalKmEvent(Buffer820027TotalKm[0], Buffer820027TotalKm[1], Buffer820027TotalKm[2], Buffer820027TotalKm[3]);
    Buffer820027TotalKmChanged = false;
  } else if (Buffer8200F8ChargeChanged) {
    OnEvokeDisplayProtocol00F8ChargeEvent(Buffer8200F8Charge[0], Buffer8200F8Charge[1], Buffer8200F8Charge[2]);
    Buffer8200F8ChargeChanged = false;
  } else {
    // no buffer changed
  }
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------