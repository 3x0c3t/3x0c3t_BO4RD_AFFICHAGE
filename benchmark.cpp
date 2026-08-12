#include "benchmark.h"
#include "settings.h"
#include "display.h"

#include <TFT_eSPI.h>

// ============================================================
// DONNEES
// ============================================================

static const char* benchmarkNames[BENCHMARK_COUNT] =
{
    "COULEURS",
    "TEXTE",
    "LIGNES",
    "RECTANGLES",
    "CERCLES"
};

static bool benchmarkSelections[BENCHMARK_COUNT];

static BenchmarkStatus benchmarkStatuses[BENCHMARK_COUNT];

// ============================================================
// INITIALISATION
// ============================================================

void benchmarkInit()
{
    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        benchmarkSelections[i] = false;
        benchmarkStatuses[i] = BENCHMARK_IDLE;
    }
}

// ============================================================
// INFORMATIONS
// ============================================================

uint8_t benchmarkCount()
{
    return BENCHMARK_COUNT;
}

const char* benchmarkName(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
        return "";

    return benchmarkNames[index];
}

bool benchmarkIsSelected(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
        return false;

    return benchmarkSelections[index];
}

BenchmarkStatus benchmarkGetStatus(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
        return BENCHMARK_IDLE;

    return benchmarkStatuses[index];
}

// ============================================================
// SELECTION
// ============================================================

void benchmarkToggle(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
        return;

    benchmarkSelections[index] = !benchmarkSelections[index];

    if (!benchmarkSelections[index])
    {
        benchmarkStatuses[index] = BENCHMARK_IDLE;
    }
}

void benchmarkSelectAll()
{
    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        benchmarkSelections[i] = true;
    }
}

void benchmarkClearAll()
{
    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        benchmarkSelections[i] = false;
        benchmarkStatuses[i] = BENCHMARK_IDLE;
    }
}

// ============================================================
// EXECUTION
// ============================================================

void benchmarkRunSelected()
{
    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        if (!benchmarkSelections[i])
            continue;

        benchmarkStatuses[i] = BENCHMARK_RUNNING;

        displayDrawBenchmarkRunning(i);

        delay(200);

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
        }

        benchmarkStatuses[i] = BENCHMARK_OK;

        displayDrawBenchmarkResult(i, BENCHMARK_OK);

        delay(500);
    }

    displayDrawBenchmarkFinished();
}

// ============================================================
// COULEURS
// ============================================================

void benchmarkColors()
{
    TFT_eSPI& tft = displayGetTFT();

    uint16_t colors[] =
    {
        TFT_BLACK,
        TFT_RED,
        TFT_GREEN,
        TFT_BLUE,
        TFT_CYAN,
        TFT_MAGENTA,
        TFT_YELLOW,
        TFT_WHITE
    };

    const uint8_t count = sizeof(colors) / sizeof(colors[0]);

    uint16_t h = SCREEN_HEIGHT / count;

    for (uint8_t i = 0; i < count; i++)
    {
        tft.fillRect(
            0,
            i * h,
            SCREEN_WIDTH,
            h,
            colors[i]
        );

        delay(120);
    }

    delay(300);

    displayClear();
}

// ============================================================
// TEXTE
// ============================================================

void benchmarkText()
{
    TFT_eSPI& tft = displayGetTFT();

    displayClear();

    tft.setTextColor(TFT_WHITE, TFT_BLACK);

    for (uint8_t size = 1; size <= 4; size++)
    {
        tft.setTextSize(size);

        tft.setCursor(
            10,
            20 + ((size - 1) * 45)
        );

        tft.print("TEST TEXTE ");
        tft.print(size);

        delay(300);
    }

    delay(500);

    displayClear();
}

// ============================================================
// LIGNES
// ============================================================

void benchmarkLines()
{
    TFT_eSPI& tft = displayGetTFT();

    displayClear();

    for (int x = 0; x < SCREEN_WIDTH; x += 10)
    {
        tft.drawLine(
            0,
            0,
            x,
            SCREEN_HEIGHT - 1,
            TFT_CYAN
        );

        delay(10);
    }

    for (int x = 0; x < SCREEN_WIDTH; x += 10)
    {
        tft.drawLine(
            SCREEN_WIDTH - 1,
            0,
            x,
            SCREEN_HEIGHT - 1,
            TFT_YELLOW
        );

        delay(10);
    }

    delay(500);

    displayClear();
}

// ============================================================
// RECTANGLES
// ============================================================

void benchmarkRectangles()
{
    TFT_eSPI& tft = displayGetTFT();

    displayClear();

    for (int i = 0; i < 110; i += 10)
    {
        tft.drawRect(
            i,
            i / 2,
            SCREEN_WIDTH - (2 * i),
            SCREEN_HEIGHT - i,
            TFT_GREEN
        );

        delay(50);
    }

    delay(500);

    displayClear();
}

// ============================================================
// CERCLES
// ============================================================

void benchmarkCircles()
{
    TFT_eSPI& tft = displayGetTFT();

    displayClear();

    int cx = SCREEN_WIDTH / 2;
    int cy = SCREEN_HEIGHT / 2;

    for (int r = 10; r < 110; r += 10)
    {
        tft.drawCircle(
            cx,
            cy,
            r,
            TFT_MAGENTA
        );

        delay(50);
    }

    delay(500);

    displayClear();
}