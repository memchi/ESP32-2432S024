/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  P.D. If you want to know additionally to the board also the CPU model, search for the file avr_cpunames.h
  --------------------------------------------------------------------------- */
#pragma once
// -----------------------------------------------------------------------------
#if defined(TEENSYDUINO)
  //  --------------- Teensy -----------------
  #if defined(__AVR_ATmega32U4__)
    #define BOARD "Teensy 2.0"
  #elif defined(__AVR_AT90USB1286__)
    #define BOARD "Teensy++ 2.0"
  #elif defined(__MK20DX128__)
    #define BOARD "Teensy 3.0"
  #elif defined(__MK20DX256__)
    #define BOARD "Teensy 3.1" // and Teensy 3.2
  #elif defined(__MKL26Z64__)
    #define BOARD "Teensy LC"
  #elif defined(__MK66FX1M0__)
    #define BOARD "Teensy++ 3.0"
  #else
    #error "Unknown Teensy board" // coming soon
  #endif
#else // --------------- Arduino ------------------
  #if   defined(ARDUINO_AVR_ADK)
    #define BOARD "Mega Adk"
  #elif defined(ARDUINO_AVR_BT)    // Bluetooth
    #define BOARD "Bt"
  #elif defined(ARDUINO_AVR_DUEMILANOVE)
    #define BOARD "Duemilanove"
  #elif defined(ARDUINO_AVR_ESPLORA)
    #define BOARD "Esplora"
  #elif defined(ARDUINO_AVR_ETHERNET)
    #define BOARD "Ethernet"
  #elif defined(ARDUINO_AVR_FIO)
    #define BOARD "Fio"
  #elif defined(ARDUINO_AVR_GEMMA)
    #define BOARD "Gemma"
  #elif defined(ARDUINO_AVR_LEONARDO)
    #define BOARD "Leonardo"
  #elif defined(ARDUINO_AVR_LILYPAD)
    #define BOARD "Lilypad"
  #elif defined(ARDUINO_AVR_LILYPAD_USB)
    #define BOARD "Lilypad Usb"
  #elif defined(ARDUINO_AVR_MEGA)
    #define BOARD "Mega"
  #elif defined(ARDUINO_AVR_MEGA2560)
    #define BOARD "Mega 2560"
  #elif defined(ARDUINO_AVR_MICRO)
    #define BOARD "Micro"
  #elif defined(ARDUINO_AVR_MINI)
    #define BOARD "Mini"
  #elif defined(ARDUINO_AVR_NANO)
    #define BOARD "Nano"
  #elif defined(ARDUINO_AVR_NG)
    #define BOARD "NG"
  #elif defined(ARDUINO_AVR_PRO)
    #define BOARD "Pro"
  #elif defined(ARDUINO_AVR_ROBOT_CONTROL)
    #define BOARD "Robot Ctrl"
  #elif defined(ARDUINO_AVR_ROBOT_MOTOR)
    #define BOARD "Robot Motor"
  #elif defined(ARDUINO_AVR_UNO)
    #define BOARD "Uno"
  #elif defined(ARDUINO_AVR_YUN)
    #define BOARD "Yun"
    // These boards must be installed separately:
  #elif defined(ARDUINO_SAM_DUE)
    #define BOARD "Due"
  #elif defined(ARDUINO_SAMD_ZERO)
    #define BOARD "Zero"
  #elif defined(ARDUINO_ARC32_TOOLS)
    #define BOARD "101"
  #elif defined(ARDUINO_ARCH_ESP32)
    #define BOARD "ESP32"
  #else
    #error "Unknown ARDUINO_AVR_ADK board"
  #endif
#endif
// -----------------------------------------------------------------------------
