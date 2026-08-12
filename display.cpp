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
// EFFACEMENT
// ============================================================

void displayClear()
{
    tft.fillScreen(COLOR_BACKGROUND);
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
        COLOR_HEADER
    );

    tft.setTextColor(
        COLOR_TITLE,
        COLOR_HEADER
    );

    tft.setTextSize(1);

    tft.setCursor(
        HEADER_TEXT_X,
        HEADER_TEXT_Y
    );

    tft.print(BOARD_NAME);

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

void displayDrawLoading(uint8_t percent)
{
    if (percent > 100)
    {
        percent = 100;
    }

    tft.drawRect(
        LOADING_X,
        LOADING_Y,
        LOADING_W,
        LOADING_H,
        COLOR_BORDER
    );

    uint16_t innerWidth =
        LOADING_W - 2;

    uint16_t fillWidth =
        (innerWidth * percent) / 100;

    if (fillWidth > innerWidth)
    {
        fillWidth = innerWidth;
    }

    if (fillWidth > 0)
    {
        tft.fillRect(
            LOADING_X + 1,
            LOADING_Y + 1,
            fillWidth,
            LOADING_H - 2,
            COLOR_SELECTED
        );
    }
}


// ============================================================
// TITRE
// ============================================================

void displayDrawTitle(const char* title)
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
        TITLE_TEXT_X,
        TITLE_Y + TITLE_TEXT_Y
    );

    tft.print(title);

    tft.drawFastHLine(
        0,
        LINE2_Y,
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
        index * (
            BENCHMARK_H +
            BENCHMARK_GAP
        );

    uint16_t color =
        COLOR_TEXT;


    switch (status)
    {
        case BENCHMARK_RUNNING:
            color = COLOR_RUNNING;
            break;

        case BENCHMARK_OK:
            color = COLOR_OK;
            break;

        case BENCHMARK_ERROR:
            color = COLOR_ERROR;
            break;

        case BENCHMARK_IDLE:
        default:
            color = COLOR_TEXT;
            break;
    }


    // --------------------------------------------------------
    // FOND
    // --------------------------------------------------------

    tft.fillRect(
        BENCHMARK_X,
        y,
        BENCHMARK_W,
        BENCHMARK_H,
        COLOR_BACKGROUND
    );


    // --------------------------------------------------------
    // BORDURE
    // --------------------------------------------------------

    tft.drawRect(
        BENCHMARK_X,
        y,
        BENCHMARK_W,
        BENCHMARK_H,
        color
    );


    // --------------------------------------------------------
    // NOM
    // --------------------------------------------------------

    tft.setTextColor(
        color,
        COLOR_BACKGROUND
    );

    tft.setTextSize(1);

    tft.setCursor(
        BENCHMARK_X + 8,
        y + 12
    );

    tft.print(
        benchmarkName(index)
    );


    // --------------------------------------------------------
    // RESULTAT
    // --------------------------------------------------------

    tft.setCursor(
        BENCHMARK_X + 155,
        y + 12
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
    }
}