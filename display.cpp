#include "display.h"

/*
 * ============================================================
 * 3x0c3t BO4RD - DISPLAY
 * ============================================================
 */

static TFT_eSPI tft = TFT_eSPI();

/*
 * ============================================================
 * ACCÈS TFT
 * ============================================================
 */

TFT_eSPI* displayGetTFT()
{
    return &tft;
}

/*
 * ============================================================
 * INITIALISATION
 * ============================================================
 */

void displayInit()
{
    tft.init();

    tft.setRotation(TFT_ROTATION);

    tft.fillScreen(
        COLOR_BACKGROUND
    );

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );
}

/*
 * ============================================================
 * EFFACEMENT
 * ============================================================
 */

void displayClear()
{
    tft.fillScreen(
        COLOR_BACKGROUND
    );
}

/*
 * ============================================================
 * HEADER
 * ============================================================
 */

void displayDrawHeader()
{
    tft.fillRect(
        0,
        HEADER1_Y,
        SCREEN_WIDTH,
        HEADER1_H,
        COLOR_HEADER1
    );

    tft.fillRect(
        0,
        HEADER2_Y,
        SCREEN_WIDTH,
        HEADER2_H,
        COLOR_HEADER2
    );

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_HEADER1
    );

    tft.setTextSize(1);

    tft.setCursor(
        8,
        8
    );

    tft.print(
        "3x0c3t BO4RD"
    );

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_HEADER2
    );

    tft.setCursor(
        8,
        HEADER2_Y + 8
    );

    tft.print(
        "AFFICHAGE"
    );
}

/*
 * ============================================================
 * RÉSULTAT BENCHMARK
 * ============================================================
 */

void displayDrawBenchmarkResult(
    uint8_t index,
    BenchmarkStatus status
)
{
    if (index >= BENCHMARK_COUNT)
    {
        return;
    }

    uint16_t y =
        BENCHMARK_FIRST_Y +
        index *
        (BENCHMARK_H + BENCHMARK_GAP);

    uint16_t color;

    switch (status)
    {
        case BENCHMARK_RUNNING:
            color = COLOR_RUNNING;
            break;

        case BENCHMARK_OK:
            color = COLOR_OK;
            break;

        case BENCHMARK_ERROR:
            color = COLOR_ERROR;
            break;

        default:
            color = COLOR_BORDER;
            break;
    }

    tft.drawRect(
        BENCHMARK_BUTTON_X,
        y,
        BENCHMARK_BUTTON_W,
        BENCHMARK_H,
        color
    );

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );

    tft.setTextSize(1);

    tft.setCursor(
        BENCHMARK_BUTTON_X + 6,
        y + 10
    );

    tft.print(
        benchmarkName(index)
    );

    tft.fillCircle(
        BENCHMARK_BUTTON_X +
        BENCHMARK_BUTTON_W -
        10,

        y + BENCHMARK_H / 2,

        5,

        color
    );
}