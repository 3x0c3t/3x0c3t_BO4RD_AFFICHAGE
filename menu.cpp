#include "settings.h"
#include "menu.h"
#include "display.h"
#include "benchmark.h"
#include "touch.h"

static bool menuInitialized = false;

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

static int8_t getBenchmarkAt(uint16_t x, uint16_t y)
{
    if (x < BENCHMARK_X ||
        x >= BENCHMARK_X + BENCHMARK_W)
    {
        return -1;
    }

    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        uint16_t buttonY =
            BENCHMARK_FIRST_Y +
            i * (BENCHMARK_H + BENCHMARK_GAP);

        if (y >= buttonY &&
            y < buttonY + BENCHMARK_H)
        {
            return i;
        }
    }

    return -1;
}

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

    bool selected =
        benchmarkIsSelected(index);

    uint16_t color =
        statusColor(
            benchmarkGetStatus(index)
        );

    uint16_t background =
        selected
            ? COLOR_SELECTED
            : COLOR_BACKGROUND;

    tft.fillRect(
        BENCHMARK_X,
        y,
        BENCHMARK_W,
        BENCHMARK_H,
        background
    );

    tft.drawRect(
        BENCHMARK_X,
        y,
        BENCHMARK_W,
        BENCHMARK_H,
        color
    );

    tft.setTextColor(
        color,
        background
    );

    tft.setTextSize(1);

    tft.setCursor(
        BENCHMARK_X + 8,
        y + 7
    );

    tft.print(
        benchmarkName(index)
    );

    tft.setCursor(
        BENCHMARK_X + 220,
        y + 7
    );

    switch (benchmarkGetStatus(index))
    {
        case BENCHMARK_IDLE:
            tft.print("READY");
            break;

        case BENCHMARK_RUNNING:
            tft.print("RUN...");
            break;

        case BENCHMARK_OK:
            tft.print("OK");
            break;

        case BENCHMARK_ERROR:
            tft.print("ERROR");
            break;

        default:
            tft.print("?");
            break;
    }
}

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
        BUTTON_RUN_X + 40,
        BUTTON_RUN_Y + 7
    );

    tft.print("RUN");
}

void menuInit()
{
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
            (uint8_t)benchmark
        );

        drawBenchmarkButton(
            (uint8_t)benchmark
        );

        delay(150);

        return;
    }

    if (
        x >= BUTTON_RUN_X &&
        x < BUTTON_RUN_X + BUTTON_RUN_W &&
        y >= BUTTON_RUN_Y &&
        y < BUTTON_RUN_Y + BUTTON_RUN_H
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
