/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  --------------------------------------------------------------------------- */
#pragma once
// -----------------------------------------------------------------------------
#include "EvokeDisplayProtocol.h"
// -----------------------------------------------------------------------------
#define INPUTSIMSIZE 455
char InputSim[INPUTSIMSIZE] = {
  0x00, 0x00, 0x00,
  // taSpeed
  0x01, 0x00, 0x09, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xB9, 0x08,
  0x00, 0x00,
  //
  0x01, 0x00, 0x09, 0x82, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
  0x00, 0x00,
  //
  0x01, 0x00, 0x09, 0x82, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06,
  0x00, 0x00,
  //
  0x01, 0x00, 0x09, 0x82, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
  0x00, 0x00,
  //
  0x01, 0x00, 0x09, 0x82, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A,
  0x00, 0x00,
  //
  0x01, 0x00, 0x09, 0x82, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C,
  0x00, 0x00,
  //
  0x01, 0x00, 0x09, 0x82, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0xD0, 0xC9,
  0x00, 0x00,
  //
  0x01, 0x00, 0x09, 0x82, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
  0x00, 0x00,
  // Kickstand Down
  0x01, 0x00, 0x09, 0x82, 0x00, 0x12, 0x00, 0x00, 0x00, 0x01, 0xC0, 0xCB, // Down (On)
  0x01, 0x00, 0x09, 0x82, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0B, // Up (Off)
  0x00, 0x00,
  // Indicator Left
  0x01, 0x00, 0x09, 0x82, 0x00, 0x16, 0x00, 0x00, 0x00, 0x01, 0x31, 0x0B, // On
  0x01, 0x00, 0x09, 0x82, 0x00, 0x16, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xCB, // Off
  0x00, 0x00,
  // Indicator Right
  0x01, 0x00, 0x09, 0x82, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x99, 0x0A, // On
  0x01, 0x00, 0x09, 0x82, 0x00, 0x18, 0x00, 0x00, 0x00, 0x01, 0x58, 0xCA, // Off
  0x00, 0x00,
  // High beam
  0x01, 0x00, 0x09, 0x82, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x01, 0x21, 0x0A, // On
  0x01, 0x00, 0x09, 0x82, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xCA, // Off
  0x00, 0x00,
  //
  0x01, 0x00, 0x09, 0x82, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C,
  0x00, 0x00,
  //
  0x01, 0x00, 0x09, 0x82, 0x00, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25,
  0x00, 0x00,
  //
  0x01, 0x00, 0x0B, 0x82, 0x00, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27,
  0x00, 0x00,
  // HighPower
  0x01, 0x00, 0x09, 0x82, 0x00, 0x70, 0x00, 0x00, 0x00, 0x01, 0x39, 0x03, // High
  0x01, 0x00, 0x09, 0x82, 0x00, 0x70, 0x00, 0x00, 0x00, 0x02, 0x79, 0x02, // Low
  0x00, 0x00,
  // KillSwitch
  0x01, 0x00, 0x09, 0x82, 0x00, 0x72, 0x00, 0x00, 0x00, 0x00, 0x81, 0x03, // On
  0x01, 0x00, 0x09, 0x82, 0x00, 0x72, 0x00, 0x00, 0x00, 0x01, 0x40, 0xC3, // Off
  0x00, 0x00,
  //
  // 0x01, 0x00, 0x09, 0x82, 0x00, 0x9A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9A,
  0x01, 0x00, 0x61, 0x82, 0x00, 0xFE,
  0x00, 0x00, 0x20, 0x20, 0x45, 0x33, 0x30, 0x35, 0x20, 0x4B, 0x49, 0x4C, 0x4C, 0x53, 0x57, 0x49,
  0x54, 0x43, 0x48, 0x20, 0x4F, 0x4E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xFF, 0xFF, 0xD9, 0xC1,
  0x00, 0x00,
  //
  0x01, 0x00, 0x09, 0x82, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8,
  0x00, 0x00,
  //
  // 0x01, 0x00, 0x09, 0x82, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE,
  0x00, 0x00,
  0x01, 0x00, 0x06, 0x80, 0x03, 0x00, 0x00, 0x03, 0x00,
  0x00, 0x00,
  0x01, 0x00, 0x06, 0x80, 0x0B, 0x00, 0x00, 0x0B, 0x00,
  0x00, 0x00,
};
static uint32_t InputSimCount = 0;
// -----------------------------------------------------------------------------
void SimulateInput() {
  TRACE(tlDEBUG, pfSTART, "InBuffer: %02X %02X %02X %02X %02X %02X .. (%d)", InBuffer[0], InBuffer[1], InBuffer[2], InBuffer[3], InBuffer[4], InBuffer[5], InBufferUse);
  if (InBufferUse < BUFFERSIZE && InputSimCount < INPUTSIMSIZE) {
    char c = InputSim[InputSimCount];
    InputSimCount++;
    InBuffer[InBufferUse] = c;
    InBufferUse++;
  }
  TRACE(tlDEBUG, pfEND, "InBuffer: %02X %02X %02X %02X %02X %02X .. (%d)", InBuffer[0], InBuffer[1], InBuffer[2], InBuffer[3], InBuffer[4], InBuffer[5], InBufferUse);
}
// -----------------------------------------------------------------------------