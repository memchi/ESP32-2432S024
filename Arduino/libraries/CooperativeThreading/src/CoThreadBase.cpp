/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  --------------------------------------------------------------------------- */
#include "Tracing.h"
#include "Arduino.h"
#include "CoThreadBase.h"
// -----------------------------------------------------------------------------
using namespace std;
// -----------------------------------------------------------------------------
// rollover safe (ex. millis() has 49,71 day rollover)
bool SafeCompare(uint32_t NewValue, uint32_t OldValue, uint32_t MaxDiff) {
  return (NewValue - OldValue) >= MaxDiff;
}
// -----------------------------------------------------------------------------
// TODO: describe here
uint32_t MillisMicros(bool UseMicros) {
  if (UseMicros) {
    return micros();
  } else {
    return millis();
  };
}
// -----------------------------------------------------------------------------
// TODO: describe here
uint32_t SecToMillisMicros(double Seconds, bool UseMicros) {
  if (UseMicros) {
    return (uint32_t)(Seconds * 1000000);
  } else {
    return (uint32_t)(Seconds * 1000);
  };
}
// -----------------------------------------------------------------------------
// TODO: describe here
TCoThreadBase::TCoThreadBase() :
  FEnabled(false),
  FOnBeforeExecute(nullptr),
  FOnAfterExecute(nullptr) {
  TRACE(tlDEBUG, pfSTART, "(TCoThreadBase)");
  TRACE(tlDEBUG, pfEND, "(TCoThreadBase)");
}
// -----------------------------------------------------------------------------
// TODO: describe here
TCoThreadBase::~TCoThreadBase() {
  // dtor
}
// -----------------------------------------------------------------------------
// TODO: describe here
void TCoThreadBase::SetOnBeforeExecute(TNotifyEvent * Value) {
  this->FOnBeforeExecute = Value;
}
// -----------------------------------------------------------------------------
// TODO: describe here
void TCoThreadBase::SetOnAfterExecute(TNotifyEvent * Value) {
  this->FOnAfterExecute = Value;
}
// -----------------------------------------------------------------------------
// TODO: describe here
void TCoThreadBase::Enabled(bool Value) {
  TRACE(tlINFO, pfSTART, "Value: %s", BOOL2STR(Value));
  this->FEnabled = Value;
  TRACE(tlINFO, pfEND, "");
}
// -----------------------------------------------------------------------------
// TODO: describe here
bool TCoThreadBase::Enabled() {
  bool Result = this->FEnabled;
  TRACE(tlINFO, pfNONE, "Result: %s", BOOL2STR(Result));
  return Result;
}
// -----------------------------------------------------------------------------
// TODO: describe here
void TCoThreadBase::Execute() {
  TRACE(tlDEBUG, pfSTART, "(TCoThreadBase)");
  if (this->FEnabled) {
    if (this->FOnBeforeExecute != nullptr) {
      this->FOnBeforeExecute();
    }
    this->FExecute();
    if (this->FOnAfterExecute != nullptr) {
      this->FOnAfterExecute();
    }
  }
  TRACE(tlDEBUG, pfEND, "(TCoThreadBase)");
}
// -----------------------------------------------------------------------------
