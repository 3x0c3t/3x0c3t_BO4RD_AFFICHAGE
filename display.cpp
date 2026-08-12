#include "display.h"
#include "settings.h"
#include "menu.h"
#include "benchmark.h"

TFT_eSPI tft = TFT_eSPI();

// ============================================================
// INITIALISATION
// ============================================================

void displayInit()
{
    tft.init();

    tft.setRotation(SCREEN_ROTATION);

    tft.fillScreen(COLOR_BACKGROUND);

    tft.setTextWrap(false);
}

// ============================================================
// CLEAR
// ============================================================

void displayClear(uint16_t color)
{
    tft.fillScreen(color);
}

// ============================================================
// HEADER 1
// ============================================================

void drawHeader1()
{
    tft.fillRect(
        0,
        0,
        SCREEN_WIDTH,
        HEADER1_HEIGHT,
        COLOR_HEADER1
    );

    tft.setTextDatum(MC_DATUM);

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_HEADER1
    );

    tft.drawString(
        "3x0c3t BO4RD",
        SCREEN_WIDTH / 2,
        HEADER1_HEIGHT / 2,
        2
    );
}

// ============================================================
// HEADER 2
// ============================================================

void drawHeader2()
{
    int y = HEADER1_HEIGHT;

    tft.fillRect(
        0,
        y,
        SCREEN_WIDTH,
        HEADER2_HEIGHT,
        COLOR_HEADER2
    );

    tft.setTextDatum(MC_DATUM);

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_HEADER2
    );

    tft.drawString(
        "BENCHMARKS AFFICHAGE",
        SCREEN_WIDTH / 2,
        y + HEADER2_HEIGHT / 2,
        2
    );
}

// ============================================================
// INTERFACE COMPLETE
// ============================================================

void drawInterface()
{
    tft.fillScreen(COLOR_BACKGROUND);

    drawHeader1();
    drawHeader2();

    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        drawBenchmarkButton(
            i,
            benchmarkGetName(i),
            benchmarkIsSelected(i),
            benchmarkGetStatusColor(i)
        );
    }

    drawStatus("Selectionnez les benchmarks");

    drawRunButton();

    tft.setTextDatum(TL_DATUM);
}

// ============================================================
// BOUTON BENCHMARK
// ============================================================

void drawBenchmarkButton(
    uint8_t index,
    const char* label,
    bool selected,
    uint16_t statusColor
)
{
    int y =
        BENCHMARK_START_Y +
        index * (BENCHMARK_HEIGHT + BENCHMARK_SPACING);

    uint16_t background =
        selected
        ? COLOR_BUTTON_SELECTED
        : COLOR_BUTTON;

    // Corps
    tft.fillRoundRect(
        BENCHMARK_X,
        y,
        BENCHMARK_WIDTH,
        BENCHMARK_HEIGHT,
        5,
        background
    );

    // Contour
    tft.drawRoundRect(
        BENCHMARK_X,
        y,
        BENCHMARK_WIDTH,
        BENCHMARK_HEIGHT,
        5,
        COLOR_BUTTON_BORDER
    );

    // Carré d'état
    int statusX = BENCHMARK_X + 7;
    int statusY = y + 7;
    int statusSize = 16;

    tft.fillRect(
        statusX,
        statusY,
        statusSize,
        statusSize,
        statusColor
    );

    tft.drawRect(
        statusX,
        statusY,
        statusSize,
        statusSize,
        TFT_WHITE
    );

    // Texte
    tft.setTextDatum(ML_DATUM);

    tft.setTextColor(
        COLOR_TEXT,
        background
    );

    tft.drawString(
        label,
        BENCHMARK_X + 31,
        y + BENCHMARK_HEIGHT / 2,
        2
    );

    tft.setTextDatum(TL_DATUM);
}

// ============================================================
// BOUTON LANCER
// ============================================================

void drawRunButton()
{
    tft.fillRoundRect(
        RUN_BUTTON_X,
        RUN_BUTTON_Y,
        RUN_BUTTON_W,
        RUN_BUTTON_H,
        6,
        COLOR_RUN_BUTTON
    );

    tft.drawRoundRect(
        RUN_BUTTON_X,
        RUN_BUTTON_Y,
        RUN_BUTTON_W,
        RUN_BUTTON_H,
        6,
        TFT_WHITE
    );

    tft.setTextDatum(MC_DATUM);

    tft.setTextColor(
        TFT_WHITE,
        COLOR_RUN_BUTTON
    );

    tft.drawString(
        "LANCER !",
        SCREEN_WIDTH / 2,
        RUN_BUTTON_Y + RUN_BUTTON_H / 2,
        2
    );

    tft.setTextDatum(TL_DATUM);
}

// ============================================================
// STATUS
// ============================================================

void drawStatus(const char* text)
{
    tft.fillRect(
        STATUS_X,
        STATUS_Y,
        STATUS_W,
        STATUS_H,
        COLOR_BACKGROUND
    );

    tft.setTextDatum(MC_DATUM);

    tft.setTextColor(
        COLOR_TEXT_DIM,
        COLOR_BACKGROUND
    );

    tft.drawString(
        text,
        SCREEN_WIDTH / 2,
        STATUS_Y + STATUS_H / 2,
        1
    );

    tft.setTextDatum(TL_DATUM);
}