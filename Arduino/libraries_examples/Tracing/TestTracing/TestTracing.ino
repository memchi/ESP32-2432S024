/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  https://www.mikrocontroller.net/articles/Plattformunabh%C3%A4ngige_Programmierung_in_C
  http://www.cplusplus.com/reference/cstdio/printf/
  http://www.nongnu.org/avr-libc/user-manual/group__avr__stdint.html
  https://de.wikibooks.org/wiki/C-Programmierung_mit_AVR-GCC/_Datentypen#Ganzzahlige_Datentypen
  --------------------------------------------------------------------------- */
#include "Tracing.h"
// -----------------------------------------------------------------------------
// one byte types
bool bFalse = false;
bool bTrue = true;
// -----------------------------------------------------------------------------
const char * CharValue = "x";
// -----------------------------------------------------------------------------
// unsigned char
uint8_t uint8_t_MinValue = 0;
uint8_t uint8_t_MaxValue = UINT8_MAX;
// signed char
int8_t int8_t_MinValue = INT8_MIN;
int8_t int8_t_MaxValue = INT8_MAX;
// -----------------------------------------------------------------------------
// two byte types
// unsigned, unsigned int, unsigned short, unsigned shortint
uint16_t uint16_t_MinValue = 0;
uint16_t uint16_t_MaxValue = UINT16_MAX;
// int, short, short int, signed, signed int, signed short, signed short int
int16_t int16_t_MinValue = INT16_MIN;
int16_t int16_t_MaxValue = INT16_MAX;
// -----------------------------------------------------------------------------
// four byte types
// unsigned long, unsigned long int
uint32_t uint32_t_MinValue = 0;
uint32_t uint32_t_MaxValue = UINT32_MAX;
// long, long int, signed long, signed long int
int32_t int32_t_MinValue = INT32_MIN;
int32_t int32_t_MaxValue = INT32_MAX;
// -----------------------------------------------------------------------------
// eight byte types
// unsigned long long, unsigned long long int
uint64_t uint64_t_MinValue = 0;
uint64_t uint64_t_MaxValue = UINT64_MAX;
// long long, long  long int, signed long long, signed long long int
int64_t int64_t_MinValue = INT64_MIN;
int64_t int64_t_MaxValue = INT64_MAX;
// -----------------------------------------------------------------------------
// float type
float FloatValue = 12345.67890;
double DoubleValue = 12345.67890;
// char * StringValue = "mystring";
// -----------------------------------------------------------------------------
void setup() {
  //TRACESTART(tlINFO, 115200);
  //TRACESTART(tlWARNING, 115200);
  TRACESTART(tlDEBUG, 115200);
  TRACE(tlDEBUG, pfNONE, "bool ----------------------------------------");
  TRACE(tlDEBUG, pfNONE, "bFalse: %s, bTrue: %s", BOOL2STR(bFalse), BOOL2STR(bTrue));
  TRACE(tlDEBUG, pfNONE, "SizeOf: %u", sizeof(bFalse));
  TRACE(tlDEBUG, pfNONE, "1 byte ----------------------------------------");
  TRACE(tlDEBUG, pfNONE, "%c", *CharValue);
  TRACE(tlDEBUG, pfNONE, "SizeOf: %u", sizeof(CharValue));
  TRACE(tlDEBUG, pfNONE, "SizeOf: %u", sizeof(*CharValue));
  TRACE(tlDEBUG, pfNONE, "uint8_t, Min: %u, Max: %u", uint8_t_MinValue, uint8_t_MaxValue);
  TRACE(tlDEBUG, pfNONE, "int8_t, Min: %d, Max: %d", int8_t_MinValue, int8_t_MaxValue);
  TRACE(tlDEBUG, pfNONE, "SizeOf (uint8_t_MinValue): %u", sizeof(uint8_t_MinValue));
  TRACE(tlDEBUG, pfNONE, "SizeOf (int8_t_MinValue): %u", sizeof(int8_t_MinValue));
  TRACE(tlDEBUG, pfNONE, "2 byte ----------------------------------------");
  TRACE(tlDEBUG, pfNONE, "uint16_t, Min: %u, Max: %u", uint16_t_MinValue, uint16_t_MaxValue);
  TRACE(tlDEBUG, pfNONE, "int16_t, Min: %d, Max: %d", int16_t_MinValue, int16_t_MaxValue);
  TRACE(tlDEBUG, pfNONE, "SizeOf (uint16_t_MinValue): %u", sizeof(int16_t_MinValue));
  TRACE(tlDEBUG, pfNONE, "SizeOf (int16_t_MinValue): %u", sizeof(int16_t_MinValue));
  TRACE(tlDEBUG, pfNONE, "4 byte ----------------------------------------");
  TRACE(tlDEBUG, pfNONE, "uint32_t, Min: %lu, Max: %lu", uint32_t_MinValue, uint32_t_MaxValue);
  TRACE(tlDEBUG, pfNONE, "int32_t, Min: %ld, Max: %ld", int32_t_MinValue, int32_t_MaxValue);
  TRACE(tlDEBUG, pfNONE, "SizeOf (uint32_t_MinValue): %u", sizeof(uint32_t_MinValue));
  TRACE(tlDEBUG, pfNONE, "SizeOf (int32_t_MinValue): %u", sizeof(int32_t_MinValue));
  TRACE(tlDEBUG, pfNONE, "8 byte ----------------------------------------");
  // not implemented in Arduino
  TRACE(tlDEBUG, pfNONE, "uint64_t, Min: %llu, Max: %llu", uint64_t_MinValue, uint64_t_MaxValue);
  TRACE(tlDEBUG, pfNONE, "int64_t, Min: %lld, Max: %lld", int64_t_MinValue, int64_t_MaxValue);
  TRACE(tlDEBUG, pfNONE, "SizeOf (uint64_t_MinValue): %u", sizeof(uint64_t_MinValue));
  TRACE(tlDEBUG, pfNONE, "SizeOf (int64_t_MinValue): %u", sizeof(int64_t_MinValue));
  TRACE(tlDEBUG, pfNONE, "float ----------------------------------------");
  // not implemented in Arduino
  TRACE(tlDEBUG, pfNONE, "Float: %f, Double: %f", FloatValue, DoubleValue);
  TRACE(tlDEBUG, pfNONE, "Float: %F, Double: %F", FloatValue, DoubleValue);
  TRACE(tlDEBUG, pfNONE, "Float: %e, Double: %e", FloatValue, DoubleValue);
  TRACE(tlDEBUG, pfNONE, "Float: %E, Double: %E", FloatValue, DoubleValue);
  TRACE(tlDEBUG, pfNONE, "Float: %g, Double: %g", FloatValue, DoubleValue);
  TRACE(tlDEBUG, pfNONE, "Float: %G, Double: %G", FloatValue, DoubleValue);
  //static float f_val = 123.6794;
  static char outstr[15];
  //dtostrf(f_val,7, 3, outstr);
  TRACE(tlDEBUG, pfNONE, "Float: %s, Double: %s", outstr, outstr);
  TRACE(tlDEBUG, pfNONE, "SizeOf (Float): %u", sizeof(FloatValue));
  TRACE(tlDEBUG, pfNONE, "SizeOf (Double): %u", sizeof(DoubleValue)); // Double is same size than float in Arduino
  // string
  TRACE(tlDEBUG, pfNONE, "--------------------------------------------------");
  TRACE(tlNONE, pfNONE, "This is a tlNONE");
  TRACE(tlDEBUG, pfNONE, "This is a tlDEBUG");
  TRACE(tlINFO, pfNONE, "This is a tlINFO");
  TRACE(tlNOTICE, pfNONE, "This is a tlNOTICE");
  TRACE(tlWARNING, pfNONE, "This is a tlWARNING");
  TRACE(tlERROR, pfNONE, "This is a tlERROR");
  TRACE(tlCRITICAL, pfNONE, "This is a tlCRITICAL");
  TRACE(tlALERT, pfNONE, "This is a tlALERT");
  TRACE(tlEMERGENCY, pfNONE, "This is a tlEMERGENCY");
  TRACE(tlDEBUG, pfNONE, "--------------------------------------------------");
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
void loop() {
  TRACE(tlDEBUG, pfSTART, "");
  delay(60000);
  TRACE(tlDEBUG, pfEND, "");
}
// -----------------------------------------------------------------------------
