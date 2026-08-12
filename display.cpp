#include "display.h"

// ============================================================
// INSTANCE TFT
// ============================================================

static TFT_eSPI tft = TFT_eSPI();

// ============================================================
// INITIALISATION
// ============================================================

void displayInit()
{
    tft.init();

    tft.setRotation(TFT_ROTATION);

    tft.fillScreen(COLOR_BACKGROUND);

    tft.setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );

    tft.setTextSize(1);
}

// ============================================================
// ACCES TFT
// ============================================================

TFT_eSPI& displayGetTFT()
{
    return tft;
}

// ============================================================
// CLEAR
// ============================================================

void displayClear()
{
    tft.fillScreen(
        COLOR_BACKGROUND
    );
}

// ============================================================
// HEADER
// ============================================================

void displayDrawHeader()
{
    tft.fillRect(
        0,
        HEADER_Y,
        SCREEN_WIDTH,
        HEADER_H,
        COLOR_BACKGROUND
    );

    tft.setTextColor(
        COLOR_TITLE,
        COLOR_BACKGROUND
    );

    tft.setTextSize(1);

    tft.setCursor(
        8,
        9
    );

    tft.print(
        "3x0c3t BO4RD"
    );

    tft.drawFastHLine(
        0,
        LINE1_Y,
        SCREEN_WIDTH,
        COLOR_BORDER
    );
}

// ============================================================
// BARRE DE CHARGEMENT
// ============================================================

void displayDrawLoading(
    uint8_t percent
)
{
    if (percent > 100)
    {
        percent = 100;
    }

    tft.drawRect(
        10,
        LOADING_Y,
        SCREEN_WIDTH - 20,
        LOADING_H,
        COLOR_BORDER
    );

    uint16_t width =
        ((SCREEN_WIDTH - 22) * percent) / 100;

    if (width > 0)
    {
        tft.fillRect(
            11,
            LOADING_Y + 1,
            width,
            LOADING_H - 2,
            COLOR_SELECTED
        );
    }
}

// ============================================================
// TITRE
// ============================================================

void displayDrawTitle(
    const char* title
)
{
    tft.fillRect(
        0,
        TITLE_Y,
        SCREEN_WIDTH,
        TITLE_H,
        COLOR_BACKGROUND
    );

    tft.setTextColor(
        COLOR_TITLE,
        COLOR_BACKGROUND
    );

    tft.setTextSize(2);

    tft.setCursor(
        10,
        TITLE_Y + 6
    );

    tft.print(title);

    tft.drawFastHLine(
        0,
        LINE3_Y,
        SCREEN_WIDTH,
        COLOR_BORDER
    );
}

// ============================================================
// RESULTAT BENCHMARK
// ============================================================

void displayDrawBenchmarkResult(
    uint8_t index,
    BenchmarkStatus status,
    int value
)
{
    if (index >= BENCHMARK_COUNT)
    {
        return;
    }

    uint16_t y =
        BENCHMARK_FIRST_Y +
        index * (BENCHMARK_H + BENCHMARK_GAP);

    uint16_t color = COLOR_TEXT;

    switch (status)
    {
        case BENCHMARK_IDLE:
            color = COLOR_TEXT;
            break;

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
            color = COLOR_TEXT;
            break;
    }

    tft.drawRect(
        BENCHMARK_X,
        y,
        BENCHMARK_W,
        BENCHMARK_H,
        COLOR_BORDER
    );

    tft.setTextColor(
        color,
        COLOR_BACKGROUND
    );

    tft.setTextSize(1);

    tft.setCursor(
        BENCHMARK_X + 6,
        y + 7
    );

    switch (index)
    {
        case 0:
            tft.print("COLORS");
            break;

        case 1:
            tft.print("TEXT");
            break;

        case 2:
            tft.print("LINES");
            break;

        case 3:
            tft.print("RECTANGLES");
            break;

        case 4:
            tft.print("CIRCLES");
            break;

        default:
            tft.print("TEST");
            break;
    }

    tft.setCursor(
        BENCHMARK_X + 190,
        y + 7
    );

    switch (status)
    {
        case BENCHMARK_IDLE:
            tft.print("READY");
            break;

        case BENCHMARK_RUNNING:
            tft.print("RUN...");
            break;

        case BENCHMARK_OK:
            tft.print(value);
            tft.print(" ms");
            break;

        case BENCHMARK_ERROR:
            tft.print("ERROR");
            break;

        default:
            break;
    }
}