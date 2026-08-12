#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
#include <TFT_eSPI.h>

// ============================================================
// 3x0c3t BO4RD - AFFICHAGE
// ESP8266 + ILI9341 + XPT2046
// Rotation 2
// Resolution graphique : 240 x 320
// ============================================================


// ============================================================
// INFORMATIONS GENERALES
// ============================================================

#define BOARD_NAME        "3x0c3t BO4RD"
#define DEBUG_SERIAL_BAUD 115200


// ============================================================
// ECRAN
// ============================================================

#define SCREEN_WIDTH      240
#define SCREEN_HEIGHT     320

#define TFT_ROTATION      2


// ============================================================
// TFT ILI9341
// ============================================================

#define TFT_CS            15
#define TFT_DC             2
#define TFT_RST           16


// ============================================================
// TOUCH XPT2046
// ============================================================

#define TOUCH_CS           0
#define TOUCH_IRQ          5


// ============================================================
// MARGES
// ============================================================

#define SCREEN_MARGIN      8

#define CONTENT_X          8
#define CONTENT_W        224


// ============================================================
// HEADER
// ============================================================

#define HEADER_Y           0
#define HEADER_H          30

#define HEADER_TEXT_X      8
#define HEADER_TEXT_Y      9

#define LINE1_Y           30


// ============================================================
// BARRE DE CHARGEMENT
// ============================================================

#define LOADING_X          8
#define LOADING_Y         34
#define LOADING_W        224
#define LOADING_H           7


// ============================================================
// TITRE
// ============================================================

#define TITLE_Y           47
#define TITLE_H           28

#define TITLE_TEXT_X       8
#define TITLE_TEXT_Y       6

#define LINE2_Y           75


// ============================================================
// BENCHMARKS
// ============================================================

#define BENCHMARK_COUNT    5

#define BENCHMARK_X        8
#define BENCHMARK_W      224

#define BENCHMARK_H       34
#define BENCHMARK_GAP      5

#define BENCHMARK_FIRST_Y  82


// ============================================================
// BOUTON RUN
// ============================================================

#define BUTTON_RUN_X       8
#define BUTTON_RUN_Y     271
#define BUTTON_RUN_W     224
#define BUTTON_RUN_H       38


// ============================================================
// COULEURS
// ============================================================

#define COLOR_BACKGROUND   TFT_BLACK

#define COLOR_HEADER       TFT_NAVY
#define COLOR_TITLE        TFT_WHITE
#define COLOR_TEXT         TFT_WHITE

#define COLOR_BORDER       TFT_LIGHTGREY
#define COLOR_SELECTED     TFT_BLUE

#define COLOR_IDLE         TFT_DARKGREY
#define COLOR_RUNNING      TFT_YELLOW
#define COLOR_OK           TFT_GREEN
#define COLOR_ERROR        TFT_RED


// ============================================================
// COMPATIBILITE
// ============================================================

#define HEADER1_H          HEADER_H
#define HEADER2_H          LOADING_H
#define FOOTER_H           BUTTON_RUN_H

#define LINE3_Y            BUTTON_RUN_Y

#endif