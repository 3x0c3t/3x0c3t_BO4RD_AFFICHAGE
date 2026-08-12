#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
#include <TFT_eSPI.h>

// ============================================================
// 3x0c3t BO4RD - AFFICHAGE
// ESP8266 NodeMCU
// TFT ILI9341 240x320
// XPT2046
// ============================================================

// ============================================================
// SERIAL
// ============================================================

#define DEBUG_SERIAL_BAUD 115200

// ============================================================
// ECRAN
// ============================================================

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240

#define TFT_ROTATION 2

// ============================================================
// TFT
// ============================================================

#define TFT_CS  15
#define TFT_DC  2
#define TFT_RST 16

// ============================================================
// TOUCH XPT2046
// ============================================================

#define TOUCH_CS  0
#define TOUCH_IRQ 5

// ============================================================
// INTERFACE
// ============================================================

#define SCREEN_MARGIN 5

// Header
#define HEADER_Y 0
#define HEADER_H 28

// Premiere ligne horizontale
#define LINE1_Y 28

// Barre de chargement
#define LOADING_Y 32
#define LOADING_H 6

// Titre
#define TITLE_Y 42
#define TITLE_H 28

// Troisieme ligne horizontale
#define LINE3_Y 70

// ============================================================
// BENCHMARKS
// ============================================================

#define BENCHMARK_COUNT 5

#define BENCHMARK_X 10
#define BENCHMARK_W 300

#define BENCHMARK_FIRST_Y 74
#define BENCHMARK_H 23
#define BENCHMARK_GAP 2

// Bouton RUN
#define BUTTON_RUN_X 10
#define BUTTON_RUN_Y 201
#define BUTTON_RUN_W 300
#define BUTTON_RUN_H 30

// ============================================================
// COULEURS
// ============================================================

#define COLOR_BACKGROUND TFT_BLACK

#define COLOR_HEADER1 TFT_NAVY
#define COLOR_HEADER2 TFT_DARKGREY

#define COLOR_TEXT TFT_WHITE
#define COLOR_TITLE TFT_CYAN
#define COLOR_BORDER TFT_LIGHTGREY
#define COLOR_SELECTED TFT_BLUE

#define COLOR_IDLE TFT_DARKGREY
#define COLOR_RUNNING TFT_YELLOW
#define COLOR_OK TFT_GREEN
#define COLOR_ERROR TFT_RED

// ============================================================
// FIN
// ============================================================

#endif