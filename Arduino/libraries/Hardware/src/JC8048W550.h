/* -----------------------------------------------------------------------------
  Copyright (c) Martin Emch, CH - 6010 Kriens
  ------------------------------------------------------------------------------
  https://www.esp32.com/viewtopic.php?t=39747
  https://espressif.github.io/arduino-esp32/package_esp32_index.json
  https://espressif.github.io/arduino-esp32/package_esp32_dev_index.json
  https://forum.arduino.cc/t/esp32s3-jc8048w550-pinout-question/1257416
  https://www.espressif.com/sites/default/files/documentation/esp32-s3-wroom-1_wroom-1u_datasheet_en.pdf
  https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf#cd-pins
  ------------------------------------------------------------------------------
  Choose board: ESP32S3 Dev Module
  ------------------------------------------------------------------------------
  Tools-Settings:
  USB CDC On Boot -> Disabled
  CPU frequency -> 240 MHz (WiFi)
  Core Debug Level -> None
  USB DFU On Boot -> Disabled
  Erase All Flash Before Sketch Upload -> Disabled
  Events Run On -> Core 1
  Flash Mode -> QIO 80 MHz
  Flash Size -> 16 MMB (128 Mb) !!!
  JTAG Adapter -> Disabled
  Arduino Runs On -> Core 1
  USB Firmware MSC On Boot -> Disabled
  Partition Scheme -> Default 4 MB with spiff (1.2 App / 1.5 MB SPIFFS)
  PSRAM -> OPI PSRAM !!!
  Upload Mode -> UART 0 / Hardware CDC
  Upload Speed -> 921000
  USB Mode -> Hardware CDC and JTAG
  Programmer -> ESPTool (x) !!!
  --------------------------------------------------------------------------- */
#pragma once
/* -----------------------------------------------------------------------------
  -DF_CPU=240000000L -DARDUINO=10607 -DARDUINO_ESP32S3_DEV -DARDUINO_ARCH_ESP32
  -DARDUINO_BOARD="ESP32S3_DEV" -DARDUINO_VARIANT="esp32s3" -DARDUINO_PARTITION_default
  -DESP32 -DCORE_DEBUG_LEVEL=0 -DARDUINO_RUNNING_CORE=1 -DARDUINO_EVENT_RUNNING_CORE=1
  -DBOARD_HAS_PSRAM -DARDUINO_USB_MODE=1 -DARDUINO_USB_CDC_ON_BOOT=0
  -DARDUINO_USB_MSC_ON_BOOT=0 -DARDUINO_USB_DFU_ON_BOOT=0
  ------------------------------------------------------------------------------
  Not checked yet:
  Erase All Flash Before Sketch Upload
  Flash Mode
  Flash Size
  JTAG Adapter
  Upload Mode
  Upload Speed
  Programmer
  --------------------------------------------------------------------------- */
#define ESP32_8048S070
// -----------------------------------------------------------------------------
#include <Arduino_GFX_Library.h> // use GFX Library for Arduino by Moon On Our Nation 1.3.1 for now
#include <lvgl.h> // use lvgl by kisvegabor 8.3.11 for now
// -----------------------------------------------------------------------------
#if ESP_ARDUINO_VERSION_MAJOR != 2
  #error use esp32 by Espressiv Systems 2.0.17 for now
#endif
#if ESP_ARDUINO_VERSION_MINOR != 0
  #error use esp32 by Espressiv Systems 2.0.17 for now
#endif
#if ESP_ARDUINO_VERSION_PATCH != 17
  #error use esp32 by Espressiv Systems 2.0.17 for now
#endif
// -----------------------------------------------------------------------------
#if LVGL_VERSION_MAJOR != 8
  #error use lvgl 8.3.11 for now
#endif
#if LVGL_VERSION_MINOR != 3
  #error use lvgl 8.3.11 for now
#endif
#if LVGL_VERSION_PATCH !=11
  #error use lvgl 8.3.11 for now
#endif
// -----------------------------------------------------------------------------
#ifndef ARDUINO_ARCH_ESP32
  #error "Only for ARDUINO_ARCH_ESP32"
#endif
// -----------------------------------------------------------------------------
#if ARDUINO_USB_CDC_ON_BOOT != 0
  #error Set ARDUINO_USB_CDC_ON_BOOT according to header of this file
#endif
// -----------------------------------------------------------------------------
#if ARDUINO != 10607
  #error Set ARDUINO according to header of this file
#endif
// -----------------------------------------------------------------------------
#ifndef ARDUINO_ESP32S3_DEV
  #error Set ARDUINO_ESP32S3_DEV according to header of this file
#endif
// -----------------------------------------------------------------------------
#if F_CPU != 240000000L
  #error Set F_CPU according to header of this file
#endif
// -----------------------------------------------------------------------------
#ifndef ESP32
  #error Set ESP32 according to header of this file
#endif
// -----------------------------------------------------------------------------
#if CORE_DEBUG_LEVEL != 0
  #error Set CORE_DEBUG_LEVEL according to header of this file
#endif
// -----------------------------------------------------------------------------
#if ARDUINO_USB_DFU_ON_BOOT != 0
  #error Set ARDUINO_USB_DFU_ON_BOOT according to header of this file
#endif
// -----------------------------------------------------------------------------
#if ARDUINO_EVENT_RUNNING_CORE != 1
  #error Set ARDUINO_EVENT_RUNNING_CORE according to header of this file
#endif
// -----------------------------------------------------------------------------
#if ARDUINO_RUNNING_CORE != 1
  #error Set ARDUINO_RUNNING_CORE according to header of this file
#endif
// -----------------------------------------------------------------------------
#if ARDUINO_USB_MSC_ON_BOOT != 0
  #error Set ARDUINO_USB_MSC_ON_BOOT according to header of this file
#endif
// -----------------------------------------------------------------------------
#ifndef ARDUINO_PARTITION_default
  #error Set ARDUINO_PARTITION_default according to header of this file
#endif
// -----------------------------------------------------------------------------
#ifndef BOARD_HAS_PSRAM
  #error Set BOARD_HAS_PSRAM according to header of this file
#endif
// -----------------------------------------------------------------------------
#if ARDUINO_USB_MODE != 1
  #error Set ARDUINO_USB_MODE according to header of this file
#endif
// -----------------------------------------------------------------------------
#if defined(DISPLAY_DEV_KIT)
  #error There is already a DISPLAY_DEV_KIT defined
#endif
// -----------------------------------------------------------------------------
#include "Board.h"
// -----------------------------------------------------------------------------
// Name GPIO-Nr
#define TFT_BL 2
#define U0TXD 43
#define U0RXD 44
#define U0RTS 15
#define U0CTS 16
#define U1TXD 17
#define U1RXD 18
#define U1RTS 19
#define U1CTS 20
// -----------------------------------------------------------------------------
Arduino_ESP32RGBPanel * bus = new Arduino_ESP32RGBPanel(
  //  GFX_NOT_DEFINED /* CS */, GFX_NOT_DEFINED /* SCK */, GFX_NOT_DEFINED /* SDA */,
  //  40 /* DE */, 41 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
  //  45 /* R0 */, 48 /* R1 */, 47 /* R2 */, 21 /* R3 */, 14 /* R4 */,
  //  5 /* G0 */, 6 /* G1 */, 7 /* G2 */, 15 /* G3 */, 16 /* G4 */, 4 /* G5 */,
  //  8 /* B0 */, 3 /* B1 */, 46 /* B2 */, 9 /* B3 */, 1 /* B4 */
  GFX_NOT_DEFINED, // CS
  GFX_NOT_DEFINED, // SCK
  GFX_NOT_DEFINED, // SDA
  40, // DE
  41, // VSYNC
  39, // HSYNC
  42, // PCLK
  45, // R0
  48, // R1
  47, // R2
  21, // R3
  14, // R4
  5, // G0
  6, // G1
  7, // G2
  15, // G3
  16, // G4
  4, // G5
  8, // B0
  3, // B1
  46, // B2
  9, // B3
  1 // B4
);
// -----------------------------------------------------------------------------
Arduino_RPi_DPI_RGBPanel * gfx = new Arduino_RPi_DPI_RGBPanel(
  //  bus,
  //  800 /* width */, 0 /* hsync_polarity */, 8 /* hsync_front_porch */, 4 /* hsync_pulse_width */, 8 /* hsync_back_porch */,
  //  480 /* height */, 0 /* vsync_polarity */, 8 /* vsync_front_porch */, 4 /* vsync_pulse_width */, 8 /* vsync_back_porch */,
  //  1 /* pclk_active_neg */, 16000000 /* prefer_speed */, true /* auto_flush */
  bus, //
  800, // width
  0, // hsync_polarity
  8, // hsync_front_porch
  4, // hsync_pulse_width
  8, // hsync_back_porch
  480, // height
  0, // vsync_polarity
  8, // vsync_front_porch
  4, // vsync_pulse_width
  8, // vsync_back_porch
  1, // pclk_active_neg
  16000000, // prefer_speed
  true // auto_flush
);
// -----------------------------------------------------------------------------
bool InitLvgl(lv_disp_drv_t * disp_drv, uint32_t screenWidth, uint32_t screenHeight) {
  return true;
}
// -----------------------------------------------------------------------------
// Display flushing
void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);
  gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
  lv_disp_flush_ready(disp);
}
// -----------------------------------------------------------------------------

