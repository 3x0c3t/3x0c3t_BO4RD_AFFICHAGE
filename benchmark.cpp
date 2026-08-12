#include "benchmark.h"

#include <TFT_eSPI.h>

#include "display.h"


// ============================================================
// SELECTION
// ============================================================

static bool benchmarkSelected[BENCHMARK_COUNT];


// ============================================================
// ETATS
// ============================================================

static BenchmarkStatus benchmarkStatuses[BENCHMARK_COUNT];


// ============================================================
// NOMS
// ============================================================

static const char* benchmarkNames[BENCHMARK_COUNT] =
{
    "Couleurs",
    "Texte",
    "Lignes",
    "Rectangles",
    "Cercles",
    "Tactile"
};


// ============================================================
// INIT
// ============================================================

void benchmarkInit()
{
    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        benchmarkSelected[i] = false;

        benchmarkStatuses[i] =
            BENCHMARK_IDLE;
    }
}


// ============================================================
// COUNT
// ============================================================

uint8_t benchmarkCount()
{
    return BENCHMARK_COUNT;
}


// ============================================================
// NAME
// ============================================================

const char* benchmarkName(
    uint8_t index
)
{
    if (index >= BENCHMARK_COUNT)
    {
        return "";
    }

    return benchmarkNames[index];
}


// ============================================================
// STATUS
// ============================================================

BenchmarkStatus benchmarkGetStatus(
    uint8_t index
)
{
    if (index >= BENCHMARK_COUNT)
    {
        return BENCHMARK_ERROR;
    }

    return benchmarkStatuses[index];
}


// ============================================================
// SELECTED
// ============================================================

bool benchmarkIsSelected(
    uint8_t index
)
{
    if (index >= BENCHMARK_COUNT)
    {
        return false;
    }

    return benchmarkSelected[index];
}


// ============================================================
// TOGGLE
// ============================================================

void benchmarkToggle(
    uint8_t index
)
{
    if (index >= BENCHMARK_COUNT)
    {
        return;
    }

    benchmarkSelected[index] =
        !benchmarkSelected[index];

    benchmarkStatuses[index] =
        BENCHMARK_IDLE;
}


// ============================================================
// CLEAR
// ============================================================

void benchmarkClearAll()
{
    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        benchmarkSelected[i] = false;

        benchmarkStatuses[i] =
            BENCHMARK_IDLE;
    }
}


// ============================================================
// BENCHMARK COULEURS
// ============================================================

bool benchmarkColors()
{
    uint32_t start = millis();

    tft.fillScreen(TFT_RED);
    delay(100);

    tft.fillScreen(TFT_GREEN);
    delay(100);

    tft.fillScreen(TFT_BLUE);
    delay(100);

    tft.fillScreen(TFT_BLACK);
    delay(100);

    tft.fillScreen(COLOR_BACKGROUND);

    return (millis() - start) >= 0;
}


// ============================================================
// BENCHMARK TEXTE
// ============================================================

bool benchmarkText()
{
    tft.fillScreen(
        COLOR_BACKGROUND
    );

    tft.setTextColor(
        COLOR_TEXT
    );

    tft.setTextSize(1);

    for (uint8_t i = 0; i < 20; i++)
    {
        tft.setCursor(
            5,
            5 + i * 14
        );

        tft.print(
            "3x0c3t BO4RD TEXT TEST"
        );
    }

    return true;
}


// ============================================================
// BENCHMARK LIGNES
// ============================================================

bool benchmarkLines()
{
    tft.fillScreen(
        COLOR_BACKGROUND
    );

    for (uint16_t y = 0; y < SCREEN_HEIGHT; y += 5)
    {
        tft.drawFastHLine(
            0,
            y,
            SCREEN_WIDTH,
            COLOR_TEXT
        );
    }

    return true;
}


// ============================================================
// BENCHMARK RECTANGLES
// ============================================================

bool benchmarkRectangles()
{
    tft.fillScreen(
        COLOR_BACKGROUND
    );

    for (uint16_t i = 0; i < 100; i += 10)
    {
        tft.drawRect(
            i,
            i,
            SCREEN_WIDTH - 2 * i,
            SCREEN_HEIGHT - 2 * i,
            COLOR_TEXT
        );
    }

    return true;
}


// ============================================================
// BENCHMARK CERCLES
// ============================================================

bool benchmarkCircles()
{
    tft.fillScreen(
        COLOR_BACKGROUND
    );

    uint16_t cx =
        SCREEN_WIDTH / 2;

    uint16_t cy =
        SCREEN_HEIGHT / 2;

    for (uint16_t r = 10; r < 110; r += 10)
    {
        tft.drawCircle(
            cx,
            cy,
            r,
            COLOR_TEXT
        );
    }

    return true;
}


// ============================================================
// BENCHMARK TOUCH
// ============================================================

bool benchmarkTouch()
{
    return true;
}


// ============================================================
// EXECUTION
// ============================================================

void benchmarkRunSelected()
{
    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        if (!benchmarkSelected[i])
        {
            continue;
        }

        benchmarkStatuses[i] =
            BENCHMARK_RUNNING;

        displayDrawBenchmarkResult(
            i,
            BENCHMARK_RUNNING
        );

        bool result = false;

        switch (i)
        {
            case 0:
                result = benchmarkColors();
                break;

            case 1:
                result = benchmarkText();
                break;

            case 2:
                result = benchmarkLines();
                break;

            case 3:
                result = benchmarkRectangles();
                break;

            case 4:
                result = benchmarkCircles();
                break;

            case 5:
                result = benchmarkTouch();
                break;

            default:
                result = false;
                break;
        }

        if (result)
        {
            benchmarkStatuses[i] =
                BENCHMARK_OK;
        }
        else
        {
            benchmarkStatuses[i] =
                BENCHMARK_ERROR;
        }

        displayDrawBenchmarkResult(
            i,
            benchmarkStatuses[i]
        );

        delay(250);
    }
}