/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  // https://en.wikipedia.org/wiki/Variadic_macro
  // https://en.wikipedia.org/wiki/Variadic_function
  --------------------------------------------------------------------------- */
#pragma once
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdint.h>
#include "Board.h"
// -----------------------------------------------------------------------------
#pragma GCC diagnostic ignored "-Wformat-extra-args"
// -----------------------------------------------------------------------------
enum TTraceLevel {
  tlNONE, // no traces should be on this level
  tlDEBUG, // every method can log here
  tlINFO, // major methods can log here
  tlNOTICE, // special infos log on this level
  tlWARNING,
  tlERROR,
  tlCRITICAL,
  tlALERT,
  tlEMERGENCY
};
enum TPosInFunction {pfNONE, pfSTART, pfEND};
// -----------------------------------------------------------------------------
#define UNUSED(x) (void)(x)
// -----------------------------------------------------------------------------
void TraceStart(TTraceLevel traceLevel, uint32_t baud);
void TraceFunction(TTraceLevel Level,
                   TPosInFunction PosInFunction,
                   const char * PrettyFunction,
                   const char * fmt, ...);
void serialprintf(const char * format, ...);
TTraceLevel GetGlobalTraceLevel();
// -----------------------------------------------------------------------------
#define BOOL2STR(Value)  Value ? "True" : "False"
// -----------------------------------------------------------------------------
#ifdef _WIN32 // + win64
  #define PATH_SEPARATOR "\\"
#else
  #define PATH_SEPARATOR "/"
#endif
// -----------------------------------------------------------------------------
#ifdef CODEBLOCKS
  #define __BASENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#else
  #define __BASENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#endif
// -----------------------------------------------------------------------------
#ifdef CODEBLOCKS
  #define PRINTF(f_, ...) printf((f_), __VA_ARGS__);
#else
  #define PRINTF(f_, ...) serialprintf((f_), __VA_ARGS__)
#endif
// -----------------------------------------------------------------------------
#define TRACESTART(Level, baud) {\
    TraceStart(Level, baud);\
    TraceFunction(tlNOTICE, pfSTART, __FUNCTION__, "%s (%s %s) %s V%s", __BASENAME__, __DATE__, __TIME__, BOARD, __VERSION__);\
  }
// -----------------------------------------------------------------------------
#define TRACE(Level, PosInFunction, ...) {\
    TraceFunction(Level, PosInFunction, __FUNCTION__, __VA_ARGS__);\
  }
// -----------------------------------------------------------------------------
