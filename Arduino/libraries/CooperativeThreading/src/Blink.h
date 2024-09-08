/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  --------------------------------------------------------------------------- */
#pragma once
// -----------------------------------------------------------------------------
#include "CoThreadBase.h"
// -----------------------------------------------------------------------------
class TBlink: public TCoThreadBase {
public:
  // constructor
  TBlink(uint32_t DarkIntervalMs_, uint32_t BrightIntervalMs_, bool Enabled);
  // Setter / Getter
  void Enabled(bool Value);
  void DarkIntervalMs(uint32_t Value);
  void BrightIntervalMs(uint32_t Value);
  bool Bright();
  void SetOnStateChange(TNotifyEvent * Value);
  // public functions
protected:
  virtual void FExecute();
private:
  // private members
  bool FBright;
  //  bool FUseMicros;
  uint32_t FDarkIntervalMs;
  uint32_t FBrightIntervalMs;
  uint32_t FPreviousTimeMs;
  // event handlers
  TNotifyEvent * FOnStateChange;
};
// -----------------------------------------------------------------------------
