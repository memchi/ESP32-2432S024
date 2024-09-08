/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  http://playground.arduino.cc/Code/TimingRollover
  https://www.baldengineer.com/arduino-how-do-you-reset-millis.html
  --------------------------------------------------------------------------- */
#pragma once
// -----------------------------------------------------------------------------
#include "Types.h"
#include <stdint.h>
// -----------------------------------------------------------------------------
#define MAXSECFORUSINGMICROS 60
// -----------------------------------------------------------------------------
// rollover safe
bool SafeCompare(uint32_t NewValue, uint32_t OldValue, uint32_t MaxDiff);
uint32_t MillisMicros(bool UseMicros);
uint32_t SecToMillisMicros(double Seconds, bool UseMicros);
// -----------------------------------------------------------------------------
// Father class of all components to be added to an instance of TCoThreadSchedule
class TCoThreadBase {
public:
  TCoThreadBase();
  virtual ~TCoThreadBase();
  virtual void Enabled(bool Value);
  virtual bool Enabled();
  void SetOnBeforeExecute(TNotifyEvent * Value);
  void SetOnAfterExecute(TNotifyEvent * Value);
  void Execute();
protected:
  bool FEnabled;
  virtual void FExecute() = 0; // could make the class abstract
private:
  TNotifyEvent * FOnBeforeExecute;
  TNotifyEvent * FOnAfterExecute;
};
// -----------------------------------------------------------------------------