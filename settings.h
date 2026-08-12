#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
#include <TFT_eSPI.h>

// ============================================================
// ECRAN
// ============================================================

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 320

#define SCREEN_ROTATION 2

// ============================================================
// SERIAL
// ============================================================

#define SERIAL_BAUDRATE 115200

// ============================================================
// COULEURS
// ============================================================

#define COLOR_BACKGROUND TFT_BLACK

#define COLOR_HEADER1 TFT_NAVY
#define COLOR_HEADER2 TFT_DARKGREY

#define COLOR_TEXT TFT_WHITE
#define COLOR_TEXT_DIM TFT_LIGHTGREY

#define COLOR_BUTTON TFT_DARKGREY
#define COLOR_BUTTON_SELECTED TFT_BLUE

#define COLOR_BUTTON_BORDER TFT_WHITE

#define COLOR_STATUS_NONE TFT_DARKGREY
#define COLOR_STATUS_OK TFT_GREEN
#define COLOR_STATUS_ERROR TFT_RED
#define COLOR_STATUS_RUNNING TFT_YELLOW

#define COLOR_RUN_BUTTON TFT_DARKGREEN

// ============================================================
// HEADER
// ============================================================

#define HEADER1_HEIGHT 30
#define HEADER2_HEIGHT 28

// ============================================================
// BENCHMARKS
// ============================================================

#define BENCHMARK_COUNT 6

#define BENCHMARK_X 8
#define BENCHMARK_WIDTH 224
#define BENCHMARK_HEIGHT 30

#define BENCHMARK_START_Y 66
#define BENCHMARK_SPACING 4

// ============================================================
// BOUTON LANCER
// ============================================================

#define RUN_BUTTON_X 8
#define RUN_BUTTON_Y 278
#define RUN_BUTTON_W 224
#define RUN_BUTTON_H 34

// ============================================================
// ZONE STATUS
// ============================================================

#define STATUS_X 8
#define STATUS_Y 252
#define STATUS_W 224
#define STATUS_H 20

// ============================================================
// TOUCH
// ============================================================

#define TOUCH_MIN_Z 200

#endif