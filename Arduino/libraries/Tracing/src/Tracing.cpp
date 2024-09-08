/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  --------------------------------------------------------------------------- */
#include "Arduino.h"
#ifdef CODEBLOCKS
  #include <stdarg.h>
  #include <cstring>
#endif
#include "Tracing.h"
// -----------------------------------------------------------------------------
const char * sPosInFunction[] = {" ", " starts", " ends"};
const char * sTraceLevel[] = {"NONE", "DEBUG", "INFO", "NOTICE", "WARNING", "ERROR", "CRITICAL", "ALERT", "EMERGENCY"};
// -----------------------------------------------------------------------------
TTraceLevel GlobalTraceLevel;
// -----------------------------------------------------------------------------
void TraceStart(TTraceLevel traceLevel, uint32_t baud) {
#ifdef CODEBLOCKS
  UNUSED(traceLevel);
  UNUSED(baud);
  GlobalTraceLevel = tlDEBUG;
#else
  GlobalTraceLevel = traceLevel;
  Serial.begin(baud);
#endif // ARDUINO
}
// -----------------------------------------------------------------------------
//https://en.wikipedia.org/wiki/Variadic_function
// http://www.swig.org/Doc1.3/Varargs.html
void TraceFunction(TTraceLevel Level,
                   TPosInFunction PosInFunction,
                   const char * PrettyFunction,
                   const char * fmt,
                   ...) {
  if (Level >= GlobalTraceLevel) {
    uint32_t Millis = millis();
    uint32_t Seconds = Millis / 1000;
    Millis = Millis - (Seconds * 1000);
    PRINTF("%u.", Seconds);
    PRINTF("%03us ", Millis);
    PRINTF("%s", PrettyFunction);
    if (strlen(sPosInFunction[PosInFunction]) > 1) {
      PRINTF("%s", sPosInFunction[PosInFunction]);
    }
    if (Level >= tlWARNING) {
      PRINTF(" %s:", sTraceLevel[Level]);
    }
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsprintf(buffer, fmt, args);
    PRINTF(" %s", buffer);
    va_end(args);
    PRINTF("%s\n", "");
  }
}
// -----------------------------------------------------------------------------
#ifndef CODEBLOCKS
void serialprintf(const char * format, ...) {
#define BUFLENGTH 255
  char buf[BUFLENGTH]; // resulting string limited to BUFLENGTH chars
  va_list args;
  va_start(args, format);
  vsnprintf(buf, BUFLENGTH, format, args);
  va_end(args);
  Serial.print(buf);
}
#endif
// -----------------------------------------------------------------------------
TTraceLevel GetGlobalTraceLevel() {
  return GlobalTraceLevel;
}
// -----------------------------------------------------------------------------
