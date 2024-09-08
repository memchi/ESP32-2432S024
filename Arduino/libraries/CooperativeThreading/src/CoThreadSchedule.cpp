/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  --------------------------------------------------------------------------- */
#ifdef __GXX_RTTI
  // Use RTTI when possible
  #include <typeinfo>
#endif
#include "Tracing.h"
#include <Arduino.h>
#include "CoThreadSchedule.h"
// -----------------------------------------------------------------------------
uint32_t MaxMicrosForDebug = 1000000; // 1 sec tolerance for debugging
// -----------------------------------------------------------------------------
// TODO: describe here
TCoThreadSchedule::TCoThreadSchedule () {
}
// -----------------------------------------------------------------------------
// TODO: describe here
TCoThreadSchedule::~TCoThreadSchedule () {
}
// -----------------------------------------------------------------------------
// TODO: describe here
TCoThreadBase * TCoThreadSchedule::Add(TCoThreadBase * CoThreadBase) {
  TRACE(tlDEBUG, pfSTART, "(TCoThreadSchedule)"); // TODO: some info about CoThreadBase?
  Add(CoThreadBase, tpNormal);
  TRACE(tlDEBUG, pfEND, "(TCoThreadSchedule)");
  return CoThreadBase;
}
// -----------------------------------------------------------------------------
// TODO: describe here
TCoThreadBase * TCoThreadSchedule::Add(TCoThreadBase * CoThreadBase, const TThreadPriority ThreadPriority) {
  TRACE(tlDEBUG, pfSTART, "(TCoThreadSchedule)"); // TODO: some info about CoThreadBase?
  UNUSED(ThreadPriority);
  CoThreads.add(CoThreadBase);
  TRACE(tlDEBUG, pfEND, "(TCoThreadSchedule)");
  return CoThreadBase;
}
// -----------------------------------------------------------------------------
// TODO: describe here
bool TCoThreadSchedule::Execute(uint32_t MaxMicros) {
  // Enlarge MaxMicros when GlobalTraceLevel
  if (GetGlobalTraceLevel() < tlNOTICE) {
    MaxMicros = MaxMicrosForDebug;
  }
  bool Result;
  TRACE(tlDEBUG, pfSTART, "MaxMicros: %lu ----------------------------------------", MaxMicros);
  uint32_t LoopStartTime = micros();
  for (int16_t CoThreadsNr = 0; CoThreadsNr < CoThreads.size(); ++CoThreadsNr) {
#ifdef __GXX_RTTI
    // Use RTTI when possible
    TRACE(tlDEBUG, pfNONE, "CoThread: %d execute, typeid().name(): %s", CoThreadsNr, typeid(*CoThreads.get(CoThreadsNr)).name());
#else
    TRACE(tlDEBUG, pfNONE, "CoThread: %d execute", CoThreadsNr);
#endif
    (*CoThreads.get(CoThreadsNr)).Execute();
    TRACE(tlDEBUG, pfNONE, "CoThread: %d executed", CoThreadsNr);
  }
  uint32_t LoopTime = micros() - LoopStartTime;
  if (LoopTime <= MaxMicros) {
    Result = true;
    TRACE(tlDEBUG, pfEND, "");
  } else {
    Result = false;
    TRACE(tlWARNING, pfEND, "LoopTime: %luus, MaxMicros: %luus", LoopTime, MaxMicros);
  }
  TRACE(tlDEBUG, pfEND, "(TCoThreadSchedule)");
  return Result;
}
// -----------------------------------------------------------------------------
