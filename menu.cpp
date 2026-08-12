#include "menu.h"

#include "settings.h"
#include "display.h"
#include "touch.h"
#include "benchmark.h"

static bool menuSelected[BENCHMARK_COUNT];

// ============================================================
// COULEUR ETAT
// ============================================================

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

        case BENCHMARK_IDLE:
        default:
            return COLOR_IDLE;
    }
}

// ============================================================
// INITIALISATION
// ============================================================

void menuInit()
{
    benchmarkInit();

    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        menuSelected[i] = false;
    }

    displayDrawHeader();

    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        int y =
            HEADER1_H +
            HEADER2_H +
            8 +
            i * (BENCHMARK_H + BENCHMARK_GAP);

        TFT_eSPI& tft = displayGetTFT();

        tft.drawRoundRect(
            5,
            y,
            SCREEN_WIDTH - 10,
            BENCHMARK_H,
            4,
            COLOR_BORDER
        );

        tft.setTextColor(TFT_WHITE);

        tft.setTextSize(1);

        tft.setCursor(
            12,
            y + 10
        );

        tft.print("B");
        tft.print(i + 1);
        tft.print(" - ");

        tft.print(
            benchmarkName(i)
        );
    }

    int runY =
        HEADER1_H +
        HEADER2_H +
        8 +
        BENCHMARK_COUNT *
        (BENCHMARK_H + BENCHMARK_GAP) +
        5;

    TFT_eSPI& tft = displayGetTFT();

    tft.fillRoundRect(
        5,
        runY,
        SCREEN_WIDTH - 10,
        BUTTON_RUN_H,
        5,
        TFT_DARKGREEN
    );

    tft.drawRoundRect(
        5,
        runY,
        SCREEN_WIDTH - 10,
        BUTTON_RUN_H,
        5,
        TFT_WHITE
    );

    tft.setTextColor(TFT_WHITE);

    tft.setTextSize(2);

    tft.setCursor(
        105,
        runY + 7
    );

    tft.print("LANCER !");
}

// ============================================================
// DESSIN D'UN BENCHMARK
// ============================================================

static void drawBenchmarkButton(
    uint8_t index
)
{
    TFT_eSPI& tft = displayGetTFT();

    int y =
        HEADER1_H +
        HEADER2_H +
        8 +
        index * (BENCHMARK_H + BENCHMARK_GAP);

    bool selected =
        benchmarkIsSelected(index);

    BenchmarkStatus status =
        benchmarkGetStatus(index);

    uint16_t background =
        selected
            ? COLOR_SELECTED
            : TFT_BLACK;

    tft.fillRoundRect(
        5,
        y,
        SCREEN_WIDTH - 10,
        BENCHMARK_H,
        4,
        background
    );

    tft.drawRoundRect(
        5,
        y,
        SCREEN_WIDTH - 10,
        BENCHMARK_H,
        4,
        COLOR_BORDER
    );

    tft.setTextColor(TFT_WHITE);

    tft.setTextSize(1);

    tft.setCursor(
        12,
        y + 10
    );

    tft.print("B");
    tft.print(index + 1);
    tft.print(" - ");

    tft.print(
        benchmarkName(index)
    );

    // Carré sélection
    tft.fillRect(
        145,
        y + 8,
        12,
        12,
        selected
            ? TFT_GREEN
            : TFT_DARKGREY
    );

    tft.drawRect(
        145,
        y + 8,
        12,
        12,
        TFT_WHITE
    );

    // Carré statut
    tft.fillRect(
        170,
        y + 8,
        12,
        12,
        statusColor(status)
    );

    tft.drawRect(
        170,
        y + 8,
        12,
        12,
        TFT_WHITE
    );
}

// ============================================================
// BOUCLE
// ============================================================

void menuLoop()
{
    int16_t x;
    int16_t y;

    if (!touchRead(x, y))
        return;

    int firstY =
        HEADER1_H +
        HEADER2_H +
        8;

    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        int buttonY =
            firstY +
            i * (BENCHMARK_H + BENCHMARK_GAP);

        if (
            x >= 5 &&
            x <= SCREEN_WIDTH - 5 &&
            y >= buttonY &&
            y <= buttonY + BENCHMARK_H
        )
        {
            benchmarkToggle(i);

            menuSelected[i] =
                benchmarkIsSelected(i);

            drawBenchmarkButton(i);

            delay(250);

            return;
        }
    }

    int runY =
        firstY +
        BENCHMARK_COUNT *
        (BENCHMARK_H + BENCHMARK_GAP) +
        5;

    if (
        x >= 5 &&
        x <= SCREEN_WIDTH - 5 &&
        y >= runY &&
        y <= runY + BUTTON_RUN_H
    )
    {
        benchmarkRunSelected();

        menuInit();

        delay(300);

        return;
    }
}