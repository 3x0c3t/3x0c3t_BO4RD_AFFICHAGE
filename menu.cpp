#include "menu.h"

#include "settings.h"
#include "display.h"
#include "touch.h"
#include "benchmark.h"

// ============================================================
// ANTI DOUBLE-TOUCH
// ============================================================

static unsigned long lastTouch = 0;

#define TOUCH_DEBOUNCE 250

// ============================================================
// INITIALISATION
// ============================================================

void menuInit()
{
    benchmarkInit();

    displayDrawMenu();
}

// ============================================================
// RECHERCHE BENCHMARK
// ============================================================

static int8_t getBenchmarkAt(
    uint16_t x,
    uint16_t y
)
{
    if (
        x < BENCHMARK_BUTTON_X ||
        x > BENCHMARK_BUTTON_X +
            BENCHMARK_BUTTON_W
    )
    {
        return -1;
    }

    for (uint8_t i = 0;
         i < BENCHMARK_COUNT;
         i++)
    {
        uint16_t by =
            BENCHMARK_FIRST_Y +
            i *
            (
                BENCHMARK_H +
                BENCHMARK_GAP
            );

        if (
            y >= by &&
            y < by + BENCHMARK_H
        )
        {
            return i;
        }
    }

    return -1;
}

// ============================================================
// BOUTON LANCER
// ============================================================

static bool isRunButton(
    uint16_t x,
    uint16_t y
)
{
    return
        x >= RUN_BUTTON_X &&
        x <= RUN_BUTTON_X +
             RUN_BUTTON_W &&
        y >= RUN_BUTTON_Y &&
        y <= RUN_BUTTON_Y +
             RUN_BUTTON_H;
}

// ============================================================
// LOOP MENU
// ============================================================

void menuLoop()
{
    uint16_t x;
    uint16_t y;

    if (!touchPressed(
        x,
        y
    ))
    {
        return;
    }

    unsigned long now =
        millis();

    if (
        now - lastTouch <
        TOUCH_DEBOUNCE
    )
    {
        return;
    }

    lastTouch = now;

    Serial.print(
        "[TOUCH] X="
    );

    Serial.print(x);

    Serial.print(
        " Y="
    );

    Serial.println(y);

    // --------------------------------------------------------
    // BENCHMARK
    // --------------------------------------------------------

    int8_t benchmark =
        getBenchmarkAt(
            x,
            y
        );

    if (benchmark >= 0)
    {
        benchmarkToggle(
            (uint8_t)benchmark
        );

        displayDrawMenu();

        return;
    }

    // --------------------------------------------------------
    // LANCER
    // --------------------------------------------------------

    if (isRunButton(
        x,
        y
    ))
    {
        Serial.println(
            "[BENCH] Lancement"
        );

        benchmarkRunSelected();

        displayDrawMenu();

        return;
    }
}