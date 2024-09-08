/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  http://playground.arduino.cc/Learning/BlinkWithoutDelayDe
  --------------------------------------------------------------------------- */
#include "Arduino.h"
#include "Tracing.h"
#include "Blink.h"
// -----------------------------------------------------------------------------
using namespace std;
// -----------------------------------------------------------------------------
TBlink::TBlink(uint32_t DarkIntervalMs_, uint32_t BrightIntervalMs_, bool Enabled_) :
  FBright(false),
  //  FUseMicros(DarkInterval_ + BrightInterval_ <= MAXSECFORUSINGMICROS),
  FDarkIntervalMs(DarkIntervalMs_),
  FBrightIntervalMs(BrightIntervalMs_),
  FPreviousTimeMs(millis()) {
  //TRACE(tlINFO, pfSTART, "Port: %d, Dark: %lu, Bright: %lu", PortNr_, DarkIntervalMs_, BrightIntervalMs_);
  this->Enabled(Enabled_);
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void TBlink::Enabled(bool Value) {
  TRACE(tlDEBUG, pfSTART, "Value: %s", BOOL2STR(Value));
  this->FEnabled = Value;
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void TBlink::DarkIntervalMs(uint32_t Value) {
  TRACE(tlDEBUG, pfNONE, "Value: %lu", Value);
  this->FDarkIntervalMs = Value;
}
// -----------------------------------------------------------------------------
void TBlink::BrightIntervalMs(uint32_t Value) {
  TRACE(tlDEBUG, pfNONE, "Value: %lu", Value);
  this->FBrightIntervalMs = Value;
}
// -----------------------------------------------------------------------------
bool TBlink::Bright() {
  bool Result = this->FBright;
  TRACE(tlDEBUG, pfNONE, "Result: %s", BOOL2STR(Result));
  return Result;
}
// -----------------------------------------------------------------------------
void TBlink::SetOnStateChange(TNotifyEvent * Value) {
  this->FOnStateChange = Value;
}
// -----------------------------------------------------------------------------
void TBlink::FExecute() {
  TRACE(tlDEBUG, pfSTART, "(TBlink)");
  uint32_t ActualTimeMs = millis();
  uint32_t ActualIntervalMs;
  if (this->FBright) {
    ActualIntervalMs = this->FBrightIntervalMs;
  } else {
    ActualIntervalMs = this->FDarkIntervalMs;
  };
  TRACE(tlDEBUG, pfNONE, "ActualTimeMs: %d, PreviousTimeMs: %d, ActualInterval:  %d", ActualTimeMs, this->FPreviousTimeMs, ActualIntervalMs);
  if (SafeCompare(ActualTimeMs, this->FPreviousTimeMs, ActualIntervalMs)) {
    this->FPreviousTimeMs = this->FPreviousTimeMs + ActualIntervalMs;
    this->FBright = !this->FBright;
    if (this->FOnStateChange != nullptr) {
      this->FOnStateChange();
    }
  };
  TRACE(tlDEBUG, pfEND, "(TBlink)");
}
// -----------------------------------------------------------------------------
