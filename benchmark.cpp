#include "benchmark.h"
#include "settings.h"
#include "display.h"

#include <Arduino.h>

/*
 * ============================================================
 * 3x0c3t BO4RD - BENCHMARK
 * ============================================================
 */

static const char* benchmarkNames[5] =
{
    "COULEURS",
    "TEXTE",
    "LIGNES",
    "RECTANGLES",
    "CERCLES"
};

static BenchmarkStatus benchmarkStatuses[BENCHMARK_COUNT];

static bool benchmarkSelected[BENCHMARK_COUNT];

/*
 * ============================================================
 * INITIALISATION
 * ============================================================
 */

void benchmarkInit()
{
    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        benchmarkStatuses[i] = BENCHMARK_IDLE;
        benchmarkSelected[i] = false;
    }
}

/*
 * ============================================================
 * INFORMATIONS
 * ============================================================
 */

uint8_t benchmarkCount()
{
    return BENCHMARK_COUNT;
}

const char* benchmarkName(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
    {
        return "";
    }

    return benchmarkNames[index];
}

BenchmarkStatus benchmarkGetStatus(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
    {
        return BENCHMARK_ERROR;
    }

    return benchmarkStatuses[index];
}

bool benchmarkIsSelected(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
    {
        return false;
    }

    return benchmarkSelected[index];
}

/*
 * ============================================================
 * SÉLECTION
 * ============================================================
 */

void benchmarkToggle(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
    {
        return;
    }

    benchmarkSelected[index] = !benchmarkSelected[index];
}

void benchmarkClearAll()
{
    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        benchmarkSelected[i] = false;
        benchmarkStatuses[i] = BENCHMARK_IDLE;
    }
}

/*
 * ============================================================
 * EXÉCUTION
 * ============================================================
 */

void benchmarkRunSelected()
{
    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        if (!benchmarkSelected[i])
        {
            continue;
        }

        benchmarkStatuses[i] = BENCHMARK_RUNNING;

        displayDrawBenchmarkResult(
            i,
            BENCHMARK_RUNNING
        );

        switch (i)
        {
            case 0:
                benchmarkColors();
                break;

            case 1:
                benchmarkText();
                break;

            case 2:
                benchmarkLines();
                break;

            case 3:
                benchmarkRectangles();
                break;

            case 4:
                benchmarkCircles();
                break;

            default:
                benchmarkStatuses[i] = BENCHMARK_ERROR;
                continue;
        }

        benchmarkStatuses[i] = BENCHMARK_OK;

        displayDrawBenchmarkResult(
            i,
            BENCHMARK_OK
        );

        delay(100);
    }
}

/*
 * ============================================================
 * BENCHMARK COULEURS
 * ============================================================
 */

void benchmarkColors()
{
    displayGetTFT()->fillScreen(TFT_RED);
    delay(150);

    displayGetTFT()->fillScreen(TFT_GREEN);
    delay(150);

    displayGetTFT()->fillScreen(TFT_BLUE);
    delay(150);

    displayGetTFT()->fillScreen(TFT_BLACK);
}

/*
 * ============================================================
 * BENCHMARK TEXTE
 * ============================================================
 */

void benchmarkText()
{
    TFT_eSPI* tft = displayGetTFT();

    tft->fillScreen(TFT_BLACK);

    tft->setTextColor(TFT_WHITE, TFT_BLACK);
    tft->setTextSize(2);

    tft->setCursor(10, 100);
    tft->print("3x0c3t BO4RD");

    tft->setCursor(10, 130);
    tft->print("BENCHMARK TEXTE");

    tft->setCursor(10, 160);
    tft->print("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    delay(500);
}

/*
 * ============================================================
 * BENCHMARK LIGNES
 * ============================================================
 */

void benchmarkLines()
{
    TFT_eSPI* tft = displayGetTFT();

    tft->fillScreen(TFT_BLACK);

    for (int y = 0; y < SCREEN_HEIGHT; y += 10)
    {
        tft->drawLine(
            0,
            0,
            SCREEN_WIDTH - 1,
            y,
            TFT_GREEN
        );
    }

    delay(500);
}

/*
 * ============================================================
 * BENCHMARK RECTANGLES
 * ============================================================
 */

void benchmarkRectangles()
{
    TFT_eSPI* tft = displayGetTFT();

    tft->fillScreen(TFT_BLACK);

    for (int i = 0; i < 100; i += 10)
    {
        tft->drawRect(
            i,
            i,
            SCREEN_WIDTH - (i * 2),
            SCREEN_HEIGHT - (i * 2),
            TFT_WHITE
        );
    }

    delay(500);
}

/*
 * ============================================================
 * BENCHMARK CERCLES
 * ============================================================
 */

void benchmarkCircles()
{
    TFT_eSPI* tft = displayGetTFT();

    tft->fillScreen(TFT_BLACK);

    int16_t cx = SCREEN_WIDTH / 2;
    int16_t cy = SCREEN_HEIGHT / 2;

    for (int r = 10; r < 100; r += 10)
    {
        tft->drawCircle(
            cx,
            cy,
            r,
            TFT_CYAN
        );
    }

    delay(500);
}