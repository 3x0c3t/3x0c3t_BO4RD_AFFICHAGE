#include "settings.h"
#include "menu.h"

#include "display.h"
#include "benchmark.h"
#include "touch.h"

// ============================================================
// ÉTAT MENU
// ============================================================

static bool menuInitialized = false;

// ============================================================
// COULEUR STATUS
// ============================================================

static uint16_t statusColor(BenchmarkStatus status)
{
    switch (status)
    {
        case BENCHMARK_RUNNING:
            return COLOR_RUNNING;

        case BENCHMARK_OK:
            return COLOR_OK;

        case BENCHMARK_ERROR:
            return COLOR_ERROR;

        case BENCHMARK_IDLE:
        default:
            return COLOR_TEXT;
    }
}

// ============================================================
// POSITION BENCHMARK
// ============================================================

static int8_t getBenchmarkAt(
    uint16_t x,
    uint16_t y
)
{
    if (x < BENCHMARK_X ||
        x > BENCHMARK_X + BENCHMARK_W)
    {
        return -1;
    }

    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        uint16_t buttonY =
            BENCHMARK_FIRST_Y +
            i * (BENCHMARK_H + BENCHMARK_GAP);

        if (y >= buttonY &&
            y <= buttonY + BENCHMARK_H)
        {
            return i;
        }
    }

    return -1;
}

// ============================================================
// DRAW BUTTON
// ============================================================

static void drawBenchmarkButton(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
    {
        return;
    }

    TFT_eSPI& tft = displayGetTFT();

    uint16_t y =
        BENCHMARK_FIRST_Y +
        index * (BENCHMARK_H + BENCHMARK_GAP);

    uint16_t color =
        statusColor(
            benchmarkGetStatus(index)
        );

    if (benchmarkIsSelected(index))
    {
        tft.fillRect(
            BENCHMARK_X,
            y,
            BENCHMARK_W,
            BENCHMARK_H,
            COLOR_SELECTED
        );
    }
    else
    {
        tft.fillRect(
            BENCHMARK_X,
            y,
            BENCHMARK_W,
            BENCHMARK_H,
            COLOR_BACKGROUND
        );
    }

    tft.drawRect(
        BENCHMARK_X,
        y,
        BENCHMARK_W,
        BENCHMARK_H,
        color
    );

    tft.setTextColor(
        color,
        benchmarkIsSelected(index)
            ? COLOR_SELECTED
            : COLOR_BACKGROUND
    );

    tft.setTextSize(1);

    tft.setCursor(
        BENCHMARK_X + 8,
        y + 10
    );

    tft.print(
        benchmarkName(index)
    );
}

// ============================================================
// RUN BUTTON
// ============================================================

static void drawRunButton()
{
    TFT_eSPI& tft = displayGetTFT();

    tft.fillRect(
        BUTTON_RUN_X,
        BUTTON_RUN_Y,
        BUTTON_RUN_W,
        BUTTON_RUN_H,
        COLOR_SELECTED
    );

    tft.drawRect(
        BUTTON_RUN_X,
        BUTTON_RUN_Y,
        BUTTON_RUN_W,
        BUTTON_RUN_H,
        COLOR_BORDER
    );

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_SELECTED
    );

    tft.setTextSize(2);

    tft.setCursor(
        BUTTON_RUN_X + 72,
        BUTTON_RUN_Y + 9
    );

    tft.print("RUN");
}

// ============================================================
// INIT
// ============================================================

void menuInit()
{
    TFT_eSPI& tft = displayGetTFT();

    displayClear();

    displayDrawHeader();

    displayDrawLoading(100);

    displayDrawTitle("BENCHMARK");

    benchmarkInit();

    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        drawBenchmarkButton(i);
    }

    drawRunButton();

    menuInitialized = true;
}

// ============================================================
// LOOP
// ============================================================

void menuLoop()
{
    if (!menuInitialized)
    {
        return;
    }

    uint16_t x;
    uint16_t y;

    if (!touchRead(&x, &y))
    {
        return;
    }

    int8_t benchmark =
        getBenchmarkAt(x, y);

    if (benchmark >= 0)
    {
        benchmarkToggle(
            benchmark
        );

        drawBenchmarkButton(
            benchmark
        );

        delay(150);

        return;
    }

    if (
        x >= BUTTON_RUN_X &&
        x <= BUTTON_RUN_X + BUTTON_RUN_W &&
        y >= BUTTON_RUN_Y &&
        y <= BUTTON_RUN_Y + BUTTON_RUN_H
    )
    {
        benchmarkRunSelected();

        for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
        {
            drawBenchmarkButton(i);
        }

        drawRunButton();

        delay(150);
    }
}