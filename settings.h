#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
#include <TFT_eSPI.h>

// ============================================================
// 3x0c3t BO4RD - AFFICHAGE
// Configuration générale
// ============================================================

// ============================================================
// VERSION
// ============================================================

#define BOARD_NAME      "3x0c3t BO4RD"
#define SOFTWARE_NAME   "AFFICHAGE"
#define SOFTWARE_VERSION "3.1"

// ============================================================
// DEBUG
// ============================================================

#define DEBUG_SERIAL_BAUD 115200

// ============================================================
// TFT
// ============================================================

#define TFT_WIDTH   240
#define TFT_HEIGHT  320

// Rotation demandée
#define TFT_ROTATION 2

// ============================================================
// TOUCH
// ============================================================

#define TOUCH_MIN_PRESSURE 200
#define TOUCH_MAX_PRESSURE 4000

// ============================================================
// COULEURS
// ============================================================

#define COLOR_BACKGROUND TFT_BLACK
#define COLOR_TEXT       TFT_WHITE
#define COLOR_TITLE      TFT_CYAN
#define COLOR_BORDER     TFT_DARKGREY

#define COLOR_SELECTED  TFT_BLUE
#define COLOR_RUNNING   TFT_YELLOW
#define COLOR_OK        TFT_GREEN
#define COLOR_WARNING   TFT_ORANGE
#define COLOR_ERROR     TFT_RED

// ============================================================
// STRUCTURE ÉCRAN
// ============================================================

#define HEADER_Y        0
#define HEADER_H        28

#define LINE1_Y         29

#define LOADING_Y       32
#define LOADING_H       8

#define LINE2_Y         42

#define TITLE_Y         45
#define TITLE_H         28

#define LINE3_Y         74

// ============================================================
// BENCHMARK
// ============================================================

#define BENCHMARK_COUNT 5

#define BENCHMARK_X     10
#define BENCHMARK_W     220

#define BENCHMARK_FIRST_Y 85

#define BENCHMARK_H     32
#define BENCHMARK_GAP   6

#define BUTTON_RUN_X    10
#define BUTTON_RUN_Y    270
#define BUTTON_RUN_W    220
#define BUTTON_RUN_H    36

// ============================================================
// ENUM BENCHMARK
// ============================================================

enum BenchmarkStatus
{
    BENCHMARK_IDLE = 0,
    BENCHMARK_RUNNING,
    BENCHMARK_OK,
    BENCHMARK_ERROR
};

// ============================================================
// PROTOTYPES GÉNÉRAUX
// ============================================================

#endif