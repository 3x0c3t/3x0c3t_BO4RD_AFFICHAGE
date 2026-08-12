#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>

/*
 * ============================================================
 * 3x0c3t BO4RD - AFFICHAGE
 * Configuration générale
 * ============================================================
 */

/*
 * ------------------------------------------------------------
 * ÉCRAN
 * ------------------------------------------------------------
 */

#define SCREEN_WIDTH   240
#define SCREEN_HEIGHT  320

#define TFT_ROTATION   0

/*
 * ------------------------------------------------------------
 * COULEURS
 * ------------------------------------------------------------
 */

#define COLOR_BACKGROUND   0x0000
#define COLOR_TEXT         0xFFFF

#define COLOR_HEADER1      0x001F
#define COLOR_HEADER2      0x07E0

#define COLOR_BORDER       0xFFFF
#define COLOR_SELECTED     0x07FF

#define COLOR_OK           0x07E0
#define COLOR_ERROR        0xF800
#define COLOR_WARNING      0xFFE0
#define COLOR_RUNNING      0x001F

/*
 * ------------------------------------------------------------
 * HEADER
 * ------------------------------------------------------------
 */

#define HEADER1_Y          0
#define HEADER1_H          28

#define HEADER2_Y          28
#define HEADER2_H          28

#define HEADER_TITLE_Y     35

/*
 * ------------------------------------------------------------
 * ZONE CONTENU
 * ------------------------------------------------------------
 */

#define CONTENT_Y          60
#define CONTENT_H          200

/*
 * ------------------------------------------------------------
 * BENCHMARKS
 * ------------------------------------------------------------
 */

#define BENCHMARK_BUTTON_X       10
#define BENCHMARK_BUTTON_Y       70
#define BENCHMARK_BUTTON_W       220
#define BENCHMARK_BUTTON_H       30

#define BENCHMARK_H              30
#define BENCHMARK_GAP            5

#define BENCHMARK_FIRST_Y        70

#define BENCHMARK_COUNT          5

/*
 * ------------------------------------------------------------
 * BOUTON RUN
 * ------------------------------------------------------------
 */

#define RUN_BUTTON_X             10
#define RUN_BUTTON_Y             260
#define RUN_BUTTON_W             220
#define RUN_BUTTON_H             40

#define BUTTON_RUN_X             RUN_BUTTON_X
#define BUTTON_RUN_Y             RUN_BUTTON_Y
#define BUTTON_RUN_W             RUN_BUTTON_W
#define BUTTON_RUN_H             RUN_BUTTON_H

/*
 * ------------------------------------------------------------
 * TOUCH
 *
 * IMPORTANT :
 * Ne pas définir TFT_CS / TFT_DC / TFT_RST ici.
 *
 * TFT_eSPI possède déjà sa propre configuration dans
 * User_Setup.h.
 * ------------------------------------------------------------
 */

#define TOUCH_CS_PIN             0
#define TOUCH_IRQ_PIN            5

/*
 * ------------------------------------------------------------
 * DEBUG
 * ------------------------------------------------------------
 */

#define DEBUG_SERIAL_BAUD        115200

#endif