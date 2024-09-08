/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  --------------------------------------------------------------------------- */
#pragma once
// -----------------------------------------------------------------------------
#include "CoThreadBase.h"
// -----------------------------------------------------------------------------
class TTimer: public TCoThreadBase {
public:
  // constructor
  TTimer(double Interval, bool Enabled_); // in s
  // Setter / Getter
  void Enabled(bool Value); // TODO: needed? is in parent ..
  void SetInterval(double Value); // // TODO: no need for "set" in s
  void SetOnTimer(TNotifyEvent * Value);
  // public functions
protected:
  virtual void FExecute();
private:
  // private members
  bool FUseMicros;
  uint32_t FIntervalTime; // in ms or us (see UseMicros)
  uint32_t FPreviousTime;
  // event handlers
  TNotifyEvent * FOnTimer;
};
// -----------------------------------------------------------------------------