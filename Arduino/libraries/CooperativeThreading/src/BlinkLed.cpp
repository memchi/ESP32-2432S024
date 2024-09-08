/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  http://playground.arduino.cc/Learning/BlinkWithoutDelayDe
  --------------------------------------------------------------------------- */
#include "Arduino.h"
#include "Tracing.h"
#include "BlinkLed.h"
// -----------------------------------------------------------------------------
using namespace std;
// -----------------------------------------------------------------------------
TBlinkLed::TBlinkLed(uint8_t PortNr_, uint32_t DarkIntervalMs_, uint32_t BrightIntervalMs_, bool Enabled_) :
  FPortNr(PortNr_),
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
void TBlinkLed::Enabled(bool Value) {
  TRACE(tlDEBUG, pfSTART, "Value: %s", BOOL2STR(Value));
  if (Value) {
    pinMode(this->FPortNr, OUTPUT);
  } else {
    pinMode(this->FPortNr, INPUT);
  };
  this->FEnabled = Value;
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void TBlinkLed::PortNr(uint8_t Value) {
  TRACE(tlINFO, pfEND, "Value: %d", Value);
  if (!this->FEnabled) {
    this->FPortNr = Value;
  }
}
// -----------------------------------------------------------------------------
uint8_t TBlinkLed::PortNr() {
  uint8_t Result = this->FPortNr;
  TRACE(tlINFO, pfNONE, "Result: %d", Result);
  return Result;
}
// -----------------------------------------------------------------------------
void TBlinkLed::DarkIntervalMs(uint32_t Value) {
  TRACE(tlDEBUG, pfNONE, "Value: %lu", Value);
  this->FDarkIntervalMs = Value;
}
// -----------------------------------------------------------------------------
void TBlinkLed::BrightIntervalMs(uint32_t Value) {
  TRACE(tlDEBUG, pfNONE, "Value: %lu", Value);
  this->FBrightIntervalMs = Value;
}
// -----------------------------------------------------------------------------
void TBlinkLed::FExecute() {
  TRACE(tlDEBUG, pfSTART, "(TBlinkLed)");
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
    digitalWrite(this->FPortNr, this->FBright);
  };
  TRACE(tlDEBUG, pfEND, "(TBlinkLed)");
}
// -----------------------------------------------------------------------------
