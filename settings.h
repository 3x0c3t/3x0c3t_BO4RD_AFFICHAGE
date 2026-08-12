#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
#include <TFT_eSPI.h>

/*

* ============================================================
* 3x0c3t BO4RD
* AFFICHAGE
* settings.h
* ============================================================
*
* ESP8266 NodeMCU
* TFT ILI9341 240x320
* Touch XPT2046
*
* ============================================================
  */

/*

* ============================================================
* ECRAN
* ============================================================
  */

#define SCREEN_WIDTH   240
#define SCREEN_HEIGHT  320

#define TFT_ROTATION   0

#define TFT_WIDTH      SCREEN_WIDTH
#define TFT_HEIGHT     SCREEN_HEIGHT

/*

* ============================================================
* TOUCH
* ============================================================
  */

#define TOUCH_IRQ 5

#define TOUCH_MIN_X  200
#define TOUCH_MAX_X  3900

#define TOUCH_MIN_Y  200
#define TOUCH_MAX_Y  3900

/*

* ============================================================
* HEADER
* ============================================================
  */

#define HEADER1_Y  0
#define HEADER1_H  20

#define HEADER2_Y  20
#define HEADER2_H  22

#define HEADER_H   (HEADER1_H + HEADER2_H)

#define UI_HEADER_HEIGHT  HEADER_H
#define UI_HEADER1_Y      HEADER1_Y
#define UI_HEADER2_Y      HEADER2_Y

/*

* ============================================================
* LIGNES
* ============================================================
  */

#define LINE1_Y  42
#define LINE2_Y  45

#define UI_LINE1_Y LINE1_Y
#define UI_LINE2_Y LINE2_Y

/*

* ============================================================
* TITRE
* ============================================================
  */

#define TITLE_Y  49
#define TITLE_H  24

#define UI_TITLE_Y       TITLE_Y
#define UI_TITLE_HEIGHT  TITLE_H

/*

* ============================================================
* BARRE DE PROGRESSION
* ============================================================
  */

#define PROGRESS_X  5
#define PROGRESS_Y  78
#define PROGRESS_W  230
#define PROGRESS_H  8

#define UI_PROGRESS_X       PROGRESS_X
#define UI_PROGRESS_Y       PROGRESS_Y
#define UI_PROGRESS_WIDTH   PROGRESS_W
#define UI_PROGRESS_HEIGHT  PROGRESS_H

/*

* ============================================================
* COULEURS
* ============================================================
  */

#define COLOR_BACKGROUND  TFT_BLACK
#define COLOR_TEXT        TFT_WHITE

#define COLOR_HEADER1     TFT_DARKCYAN
#define COLOR_HEADER2     TFT_NAVY

#define COLOR_LINE        TFT_DARKGREY
#define COLOR_TITLE       TFT_CYAN

#define COLOR_PROGRESS_BG TFT_DARKGREY
#define COLOR_PROGRESS    TFT_GREEN

#define COLOR_BUTTON      TFT_BLUE
#define COLOR_BUTTON_SEL  TFT_CYAN
#define COLOR_BUTTON_TEXT TFT_WHITE

#define COLOR_IDLE        TFT_DARKGREY
#define COLOR_RUNNING     TFT_YELLOW
#define COLOR_OK          TFT_GREEN
#define COLOR_ERROR       TFT_RED

/*

* ============================================================
* BENCHMARK
* ============================================================
  */

#define BENCHMARK_COUNT 5

#define BENCHMARK_BUTTON_X  5
#define BENCHMARK_BUTTON_Y  95

#define BENCHMARK_BUTTON_W  230
#define BENCHMARK_BUTTON_H  32

#define BENCHMARK_GAP       5

#define BENCHMARK_FIRST_X   BENCHMARK_BUTTON_X
#define BENCHMARK_FIRST_Y   BENCHMARK_BUTTON_Y

#define BENCHMARK_SPACING   BENCHMARK_GAP

/*

* ============================================================
* BOUTON RUN
* ============================================================
  */

#define RUN_BUTTON_X  5
#define RUN_BUTTON_Y  275

#define RUN_BUTTON_W  230
#define RUN_BUTTON_H  35

/*

* ============================================================
* ETAT DES BENCHMARKS
* ============================================================
  */

enum BenchmarkStatus
{
BENCHMARK_IDLE = 0,
BENCHMARK_RUNNING,
BENCHMARK_OK,
BENCHMARK_ERROR
};

/*

* ============================================================
* TEXTE
* ============================================================
  */

#define TEXT_SIZE_HEADER  1
#define TEXT_SIZE_TITLE   2
#define TEXT_SIZE_NORMAL  1
#define TEXT_SIZE_BUTTON  1

/*

* ============================================================
* SERIAL
* ============================================================
  */

#define SERIAL_BAUDRATE 115200

/*

* ============================================================
* FIN
* ============================================================
  */

#endif
