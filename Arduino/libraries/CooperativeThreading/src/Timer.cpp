/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  http://playground.arduino.cc/Learning/BlinkWithoutDelayDe
  --------------------------------------------------------------------------- */
#include "Timer.h"
#include "Tracing.h"
// -----------------------------------------------------------------------------
using namespace std;
// -----------------------------------------------------------------------------
TTimer::TTimer(double Interval_, bool Enabled_) :
  FUseMicros(Interval_ <= MAXSECFORUSINGMICROS),
  FIntervalTime(0),
  FPreviousTime(MillisMicros(this->FUseMicros)),
  FOnTimer(nullptr) {
  TRACE(tlINFO, pfSTART, "");
  this->SetInterval(Interval_);
  this->Enabled(Enabled_);
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void TTimer::Enabled(bool Value) {
  TRACE(tlDEBUG, pfSTART, "Value: %s", BOOL2STR(Value));
  FPreviousTime = MillisMicros(this->FUseMicros);
  this->FEnabled = Value;
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void TTimer::SetInterval(double Value) {
  this->FIntervalTime = SecToMillisMicros(Value, this->FUseMicros);
  TRACE(tlDEBUG, pfNONE, "FIntervalTime (ms/us): %lu", this->FIntervalTime);
}
// -----------------------------------------------------------------------------
void TTimer::SetOnTimer(TNotifyEvent * Value) {
  this->FOnTimer = Value;
}
// -----------------------------------------------------------------------------
void TTimer::FExecute() {
  TRACE(tlDEBUG, pfSTART, "(TTimer)");
  uint32_t ActualTime = MillisMicros(this->FUseMicros);
  if (SafeCompare(ActualTime, this->FPreviousTime, this->FIntervalTime)) {
    this->FPreviousTime = this->FPreviousTime + this->FIntervalTime;
    if (this->FOnTimer != nullptr) {
      this->FOnTimer();
    }
  }
  TRACE(tlDEBUG, pfEND, "(TTimer)");
}
// -----------------------------------------------------------------------------
