/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  --------------------------------------------------------------------------- */
#include "CoThreadSchedule.h"
#include "BlinkLed.h"
#include "Tracing.h"
// -----------------------------------------------------------------------------
// add pointer to an instance of the scheduler
TCoThreadSchedule Schedule;
// add pointers to the instances
TBlinkLed * pHeartBeatLed;
// -----------------------------------------------------------------------------
void setup() {
  TRACESTART(tlWARNING, 115200);
  //TRACESTART(tlINFO, 115200);
  //TRACESTART(tlDEBUG, 115200);
  // instance and parameterize the objects
  pHeartBeatLed = new TBlinkLed(LED_BUILTIN, 999, 1, true);
  // add the instances to scheduler
  Schedule.Add(pHeartBeatLed);
  // Link the eventhandler
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
