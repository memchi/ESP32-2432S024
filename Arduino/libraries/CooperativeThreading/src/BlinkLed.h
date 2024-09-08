/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  --------------------------------------------------------------------------- */
#pragma once
// -----------------------------------------------------------------------------
#include "CoThreadBase.h"
// -----------------------------------------------------------------------------
class TBlinkLed: public TCoThreadBase {
public:
  // constructor
  TBlinkLed(uint8_t PortNr_, uint32_t DarkIntervalMs_, uint32_t BrightIntervalMs_, bool Enabled);
  // Setter / Getter
  void Enabled(bool Value);
  void PortNr(uint8_t Value);
  uint8_t PortNr();
  void DarkIntervalMs(uint32_t Value);
  void BrightIntervalMs(uint32_t Value);
  // public functions
protected:
  virtual void FExecute();
private:
  // private members
  uint8_t FPortNr;
  bool FBright;
  //  bool FUseMicros;
  uint32_t FDarkIntervalMs;
  uint32_t FBrightIntervalMs;
  uint32_t FPreviousTimeMs;
  // event handlers
};
// -----------------------------------------------------------------------------
