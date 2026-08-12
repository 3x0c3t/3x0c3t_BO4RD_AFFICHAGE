#include "settings.h"
#include "display.h"
#include "benchmark.h"
#include "touch.h"

#include <Arduino.h>

/*
 * ============================================================
 * 3x0c3t BO4RD - MENU
 * ============================================================
 */

static uint16_t statusColor(
    BenchmarkStatus status
)
{
    switch (status)
    {
        case BENCHMARK_RUNNING:
            return COLOR_RUNNING;

        case BENCHMARK_OK:
            return COLOR_OK;

        case BENCHMARK_ERROR:
            return COLOR_ERROR;

        default:
            return COLOR_BORDER;
    }
}

/*
 * ============================================================
 * DÉTECTION BENCHMARK
 * ============================================================
 */

static int8_t getBenchmarkAt(
    uint16_t x,
    uint16_t y
)
{
    if (
        x < BENCHMARK_BUTTON_X ||
        x >= BENCHMARK_BUTTON_X + BENCHMARK_BUTTON_W
    )
    {
        return -1;
    }

    for (
        uint8_t i = 0;
        i < BENCHMARK_COUNT;
        i++
    )
    {
        uint16_t buttonY =
            BENCHMARK_FIRST_Y +
            i *
            (BENCHMARK_H + BENCHMARK_GAP);

        if (
            y >= buttonY &&
            y < buttonY + BENCHMARK_H
        )
        {
            return i;
        }
    }

    return -1;
}

/*
 * ============================================================
 * BOUTON RUN
 * ============================================================
 */

static bool isRunButton(
    uint16_t x,
    uint16_t y
)
{
    return
        x >= RUN_BUTTON_X &&
        x < RUN_BUTTON_X + RUN_BUTTON_W &&
        y >= RUN_BUTTON_Y &&
        y < RUN_BUTTON_Y + RUN_BUTTON_H;
}

/*
 * ============================================================
 * DESSIN BENCHMARK
 * ============================================================
 */

static void drawBenchmarkButton(
    uint8_t index
)
{
    if (index >= BENCHMARK_COUNT)
    {
        return;
    }

    TFT_eSPI* tft =
        displayGetTFT();

    uint16_t y =
        BENCHMARK_FIRST_Y +
        index *
        (BENCHMARK_H + BENCHMARK_GAP);

    uint16_t border =
        statusColor(
            benchmarkGetStatus(index)
        );

    if (benchmarkIsSelected(index))
    {
        tft->fillRect(
            BENCHMARK_BUTTON_X,
            y,
            BENCHMARK_BUTTON_W,
            BENCHMARK_H,
            COLOR_SELECTED
        );
    }
    else
    {
        tft->fillRect(
            BENCHMARK_BUTTON_X,
            y,
            BENCHMARK_BUTTON_W,
            BENCHMARK_H,
            COLOR_BACKGROUND
        );
    }

    tft->drawRect(
        BENCHMARK_BUTTON_X,
        y,
        BENCHMARK_BUTTON_W,
        BENCHMARK_H,
        border
    );

    tft->setTextColor(
        COLOR_TEXT,
        benchmarkIsSelected(index)
            ? COLOR_SELECTED
            : COLOR_BACKGROUND
    );

    tft->setTextSize(1);

    tft->setCursor(
        BENCHMARK_BUTTON_X + 8,
        y + 10
    );

    tft->print(
        benchmarkName(index)
    );
}

/*
 * ============================================================
 * MENU INITIALISATION
 * ============================================================
 */

void menuInit()
{
    benchmarkInit();

    displayClear();

    displayDrawHeader();

    TFT_eSPI* tft =
        displayGetTFT();

    tft->setTextSize(1);

    for (
        uint8_t i = 0;
        i < BENCHMARK_COUNT;
        i++
    )
    {
        drawBenchmarkButton(i);
    }

    tft->fillRect(
        RUN_BUTTON_X,
        RUN_BUTTON_Y,
        RUN_BUTTON_W,
        RUN_BUTTON_H,
        COLOR_BACKGROUND
    );

    tft->drawRect(
        RUN_BUTTON_X,
        RUN_BUTTON_Y,
        RUN_BUTTON_W,
        RUN_BUTTON_H,
        COLOR_BORDER
    );

    tft->setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );

    tft->setCursor(
        RUN_BUTTON_X + 90,
        RUN_BUTTON_Y + 15
    );

    tft->print(
        "RUN"
    );
}

/*
 * ============================================================
 * BOUCLE MENU
 * ============================================================
 */

void menuLoop()
{
    uint16_t x;
    uint16_t y;

    if (!touchRead(
        &x,
        &y
    ))
    {
        return;
    }

    int8_t benchmark =
        getBenchmarkAt(
            x,
            y
        );

    if (benchmark >= 0)
    {
        benchmarkToggle(
            benchmark
        );

        drawBenchmarkButton(
            benchmark
        );

        delay(250);

        return;
    }

    if (isRunButton(
        x,
        y
    ))
    {
        benchmarkRunSelected();

        delay(250);

        for (
            uint8_t i = 0;
            i < BENCHMARK_COUNT;
            i++
        )
        {
            drawBenchmarkButton(i);
        }
    }
}