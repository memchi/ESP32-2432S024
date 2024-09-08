/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  This sketch will print some of interesting predefined constants to Serial.
  For more information, look at
  http://electronics4dogs.blogspot.com/2011/01/arduino-predefined-constants.html
  --------------------------------------------------------------------------- */
#include "Tracing.h"
#include "Timer.h"
#include "BlinkLed.h"
#include "CoThreadSchedule.h"
// -----------------------------------------------------------------------------
// add pointer to an instance of the scheduler
TCoThreadSchedule Schedule;
// add pointers to the instances
TTimer * pTimer;
TBlinkLed * pHeartBeatLed;
// -----------------------------------------------------------------------------
void TimerOnTimer() {
  TRACE(tlINFO, pfSTART, "--------------------------------------------------------------------------------");
  // Compile file path (internal file of compilation proccess)
  TRACE(tlINFO, pfNONE, "__FILE__: %s", __FILE__);
  // Current line (but in __FILE__)
  TRACE(tlINFO, pfNONE, "__LINE__: %d", __LINE__);
  // Name of current function
  TRACE(tlINFO, pfNONE, "__func__: %s", __func__);
  TRACE(tlINFO, pfNONE, "__PRETTY_FUNCTION__: %s", __PRETTY_FUNCTION__);
  // Date of compliation
  TRACE(tlINFO, pfNONE, "__DATE__: %s", __DATE__);
  // Time of compilation
  TRACE(tlINFO, pfNONE, "__TIME__: %s", __TIME__);
  // Timestamp of compilation
  TRACE(tlINFO, pfNONE, "__TIMESTAMP__: %s", __TIMESTAMP__);
  // Version of comilator (avr-gcc)
  TRACE(tlINFO, pfNONE, "__VERSION__: %s", __VERSION__);
  // Counter
  TRACE(tlINFO, pfNONE, "__COUNTER__: %d", (int16_t)__COUNTER__);
  TRACE(tlINFO, pfNONE, "__COUNTER__: %d", (int16_t)__COUNTER__);
  TRACE(tlINFO, pfNONE, "__COUNTER__: %d", (int16_t)__COUNTER__);
  TRACE(tlINFO, pfNONE, "CPU:");
#if defined(__AVR_ATmega168__)
  // Arduino Diecimila and older
  TRACE(tlINFO, pfNONE, "");
#elif defined(__AVR_ATmega328P__)
  // Arduino Duemilanove and Uno
  TRACE(tlINFO, pfNONE, "__AVR_ATmega328P__");
#elif defined(__AVR_ATmega2560__)
  // Arduino Mega 2560
  TRACE(tlINFO, pfNONE, "__AVR_ATmega2560__");
#elif defined(__AVR_ATmega1280__)
  // Arduino Mega
  TRACE(tlINFO, pfNONE, "__AVR_ATmega1280__");
#elif defined(__AVR_ATmega32U4__)
  // Arduino Leonardo
  TRACE(tlINFO, pfNONE, "__AVR_ATmega32U4__");
#elif defined(__SAM3X8E__)
  // Arduino Due
  TRACE(tlINFO, pfNONE, "__SAM3X8E__");
#elif defined()
  //
  TRACE(tlINFO, pfNONE, "");
#elif defined()
  //
  TRACE(tlINFO, pfNONE, "");
#elif defined()
  //
  TRACE(tlINFO, pfNONE, "");
#else
  TRACE(tlWARNING, pfNONE, "Unknown CPU");
#endif
  // Determine board type
#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__)
  TRACE(tlINFO, pfNONE, "Regular Arduino");
#elif defined(__AVR_ATmega2560__) || defined(__AVR_ATmega1280__)
  TRACE(tlINFO, pfNONE, "Arduino Mega");
#elif defined(__AVR_ATmega32U4__)
  TRACE(tlINFO, pfNONE, ": %s", );
#elif defined(Arduino Leonardo)
  TRACE(tlINFO, pfNONE, ": %s", );
#elif defined(__SAM3X8E__)
  TRACE(tlINFO, pfNONE, "Arduino Due");
#else
  TRACE(tlWARNING, pfNONE, "Unknown board");
#endif
  TRACE(tlINFO, pfNONE, "Arduino:");
  // Arduino SW version
  TRACE(tlINFO, pfNONE, "ARDUINO: %d", ARDUINO);
  // Oscillator frequency
  TRACE(tlINFO, pfNONE, "F_CPU: %d", F_CPU);
  // timer since startup
  TRACE(tlINFO, pfNONE, "micros(): %lu", micros());
  TRACE(tlINFO, pfNONE, "millis(): %lu", millis());
  TRACE(tlINFO, pfEND, "");
}
// -----------------------------------------------------------------------------
void setup() {
  TRACESTART(tlINFO, 115200);
  //TRACESTART(tlWARNING, 115200);
  //TRACESTART(tlDEBUG, 115200);
  // instance and parameterize the objects
  pHeartBeatLed = new TBlinkLed(LED_BUILTIN, 999, 1, true);
  pTimer = new TTimer(2, true);
  // add the instances to scheduler
  Schedule.Add(pHeartBeatLed);
  Schedule.Add(pTimer);
  // Link the eventhandler
  pTimer->SetOnTimer(TimerOnTimer);
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void loop() {
  TRACE(tlDEBUG, pfSTART, "");
  if (!Schedule.Execute(1000)) {
    pHeartBeatLed->DarkIntervalMs(249);
  };
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
