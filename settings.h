#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>

// ============================================================
// 3x0c3t BO4RD - AFFICHAGE
// ESP8266 NodeMCU
// TFT ILI9341 240x320
// XPT2046
// ============================================================

// ============================================================
// ECRAN
// ============================================================

#define SCREEN_WIDTH    320
#define SCREEN_HEIGHT   240

#define TFT_ROTATION    2

// ============================================================
// TOUCH
// ============================================================

#define TOUCH_IRQ_PIN   5

// IMPORTANT
// TOUCH_CS est défini par TFT_eSPI/User_Setup.h
// Ne pas le redéfinir ici.

// ============================================================
// INTERFACE
// ============================================================

#define HEADER1_H       28
#define HEADER2_H       24

#define FOOTER_H        28

#define SCREEN_MARGIN   5

// ============================================================
// BENCHMARKS
// ============================================================

#define BENCHMARK_COUNT         5

#define BENCHMARK_BUTTON_X      5
#define BENCHMARK_BUTTON_W      (SCREEN_WIDTH - 10)
#define BENCHMARK_BUTTON_H      28
#define BENCHMARK_BUTTON_GAP    4

#define BENCHMARK_H             BENCHMARK_BUTTON_H
#define BENCHMARK_GAP           BENCHMARK_BUTTON_GAP

// ============================================================
// BOUTON RUN
// ============================================================

#define BUTTON_RUN_X            5
#define BUTTON_RUN_W            (SCREEN_WIDTH - 10)
#define BUTTON_RUN_H            30

#define RUN_BUTTON_X            BUTTON_RUN_X
#define RUN_BUTTON_W            BUTTON_RUN_W
#define RUN_BUTTON_H            BUTTON_RUN_H

#define RUN_BUTTON_Y 
(HEADER1_H + HEADER2_H + 8 + 
BENCHMARK_COUNT * 
(BENCHMARK_BUTTON_H + BENCHMARK_BUTTON_GAP) + 5)

// ============================================================
// COULEURS
// ============================================================

#define COLOR_BACKGROUND    0x0000
#define COLOR_HEADER1       0x001F
#define COLOR_HEADER2       0x7BEF

#define COLOR_TEXT          0xFFFF

#define COLOR_SELECTED      0x001F
#define COLOR_BORDER        0xC618

#define COLOR_IDLE          0x7BEF
#define COLOR_RUNNING       0xFFE0
#define COLOR_OK            0x07E0
#define COLOR_ERROR         0xF800
#define COLOR_WARNING       0xFD20

#endif
