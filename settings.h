#ifndef BO4RD_SETTINGS_H
#define BO4RD_SETTINGS_H

// ============================================================
// 3x0c3t BO4RD - AFFICHAGE
// ESP8266 NodeMCU
// TFT ILI9341 240x320
// XPT2046
// ============================================================


// ============================================================
// DEBUG
// ============================================================

#define DEBUG_SERIAL_BAUD 115200


// ============================================================
// ECRAN
// ============================================================

#define SCREEN_WIDTH   320
#define SCREEN_HEIGHT  240
#define TFT_ROTATION   2


// ============================================================
// BROCHES TFT
// ============================================================
//
// Ne PAS utiliser TFT_CS / TFT_DC / TFT_RST ici.
// TFT_eSPI possède déjà ces macros.
//
// Notre application utilise les noms BO4RD_*.
//

#define BO4RD_TFT_CS    15
#define BO4RD_TFT_DC     2
#define BO4RD_TFT_RST   16


// ============================================================
// TOUCH XPT2046
// ============================================================

#define BO4RD_TOUCH_CS   0
#define BO4RD_TOUCH_IRQ  5


// ============================================================
// INTERFACE
// ============================================================

#define BO4RD_HEADER1_H   28
#define BO4RD_HEADER2_H   24

#define BO4RD_FOOTER_H    28

#define BO4RD_SCREEN_MARGIN 5


// ============================================================
// ZONES D'AFFICHAGE
// ============================================================

#define BO4RD_HEADER_Y    0

#define BO4RD_HEADER_H \
    (BO4RD_HEADER1_H + BO4RD_HEADER2_H)

#define BO4RD_LINE1_Y \
    (BO4RD_HEADER_Y + BO4RD_HEADER_H)

#define BO4RD_LOADING_Y \
    (BO4RD_LINE1_Y + 4)

#define BO4RD_LOADING_H  8

#define BO4RD_TITLE_Y \
    (BO4RD_LOADING_Y + BO4RD_LOADING_H + 4)

#define BO4RD_TITLE_H  28

#define BO4RD_LINE3_Y \
    (BO4RD_TITLE_Y + BO4RD_TITLE_H)


// ============================================================
// BENCHMARKS
// ============================================================

#define BENCHMARK_COUNT  5

#define BO4RD_BENCHMARK_ITEM_H   28
#define BO4RD_BENCHMARK_GAP       4

#define BO4RD_BUTTON_RUN_H       30


// ============================================================
// IDENTITE
// ============================================================

#define BOARD_NAME "3x0c3t BO4RD"


// ============================================================
// COULEURS
// ============================================================
//
// Ces noms viennent de TFT_eSPI.
// settings.h ne doit donc PAS être inclus avant TFT_eSPI
// lorsqu'on utilise ces macros.
//

#define COLOR_BACKGROUND TFT_BLACK
#define COLOR_HEADER1    TFT_NAVY
#define COLOR_HEADER2    TFT_DARKGREY

#define COLOR_TEXT       TFT_WHITE
#define COLOR_TITLE      TFT_CYAN

#define COLOR_SELECTED   TFT_BLUE
#define COLOR_BORDER     TFT_LIGHTGREY

#define COLOR_IDLE       TFT_DARKGREY
#define COLOR_RUNNING    TFT_YELLOW
#define COLOR_OK         TFT_GREEN
#define COLOR_ERROR      TFT_RED


#endif