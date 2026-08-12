#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
#include <TFT_eSPI.h>

#define SCREEN_WIDTH    320
#define SCREEN_HEIGHT   240
#define TFT_ROTATION    2

#define TFT_CS          15
#define TFT_DC          2
#define TFT_RST         16

#define TOUCH_CS        0
#define TOUCH_IRQ       5

#define BOARD_NAME      "3x0c3t BO4RD"

#define SCREEN_MARGIN   10

#define HEADER_Y        0
#define HEADER_H        28

#define LINE1_Y         28

#define LOADING_X       10
#define LOADING_Y       32
#define LOADING_W       300
#define LOADING_H       8

#define TITLE_Y         43
#define TITLE_H         25

#define LINE3_Y         68

#define BENCHMARK_COUNT     5

#define BENCHMARK_X         10
#define BENCHMARK_W         300
#define BENCHMARK_H         23
#define BENCHMARK_GAP       3
#define BENCHMARK_FIRST_Y   73

#define BUTTON_RUN_X        100
#define BUTTON_RUN_Y        205
#define BUTTON_RUN_W        120
#define BUTTON_RUN_H        30

#define COLOR_BACKGROUND    TFT_BLACK
#define COLOR_HEADER1       TFT_NAVY
#define COLOR_HEADER2       TFT_DARKGREY
#define COLOR_TITLE         TFT_WHITE
#define COLOR_TEXT          TFT_WHITE
#define COLOR_SELECTED      TFT_BLUE
#define COLOR_BORDER        TFT_LIGHTGREY
#define COLOR_IDLE          TFT_DARKGREY
#define COLOR_RUNNING       TFT_YELLOW
#define COLOR_OK            TFT_GREEN
#define COLOR_ERROR         TFT_RED

#endif
