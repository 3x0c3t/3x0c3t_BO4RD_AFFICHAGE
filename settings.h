#ifndef SETTINGS_H
#define SETTINGS_H

// ============================================================
// 3x0c3t BO4RD - AFFICHAGE
// ESP8266 NodeMCU
// TFT ILI9341 240x320
// XPT2046
// ============================================================

// ------------------------------------------------------------
// ECRAN
// ------------------------------------------------------------

#define SCREEN_WIDTH   320
#define SCREEN_HEIGHT  240

#define TFT_ROTATION   2

// ------------------------------------------------------------
// TFT
// ------------------------------------------------------------

#define TFT_CS   15
#define TFT_DC    2
#define TFT_RST  16

// ------------------------------------------------------------
// TOUCH XPT2046
// ------------------------------------------------------------

#define TOUCH_CS   0
#define TOUCH_IRQ  5

// ------------------------------------------------------------
// INTERFACE
// ------------------------------------------------------------

#define HEADER1_H       28
#define HEADER2_H       24

#define FOOTER_H        28

#define SCREEN_MARGIN    5

// ------------------------------------------------------------
// BENCHMARKS
// ------------------------------------------------------------

#define BENCHMARK_COUNT  5

#define BENCHMARK_H      28
#define BENCHMARK_GAP     4

#define BUTTON_RUN_H     30

// ------------------------------------------------------------
// COULEURS
// ------------------------------------------------------------

#define COLOR_BACKGROUND TFT_BLACK
#define COLOR_HEADER1    TFT_NAVY
#define COLOR_HEADER2    TFT_DARKGREY

#define COLOR_TEXT       TFT_WHITE
#define COLOR_SELECTED   TFT_BLUE
#define COLOR_BORDER     TFT_LIGHTGREY

#define COLOR_IDLE       TFT_DARKGREY
#define COLOR_RUNNING    TFT_YELLOW
#define COLOR_OK         TFT_GREEN
#define COLOR_ERROR      TFT_RED

#endif