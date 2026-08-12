#include "display.h"
#include "settings.h"

static TFT_eSPI tft = TFT_eSPI();


// ============================================================
// INITIALISATION
// ============================================================

void displayInit()
{
    tft.init();

    tft.setRotation(
        TFT_ROTATION
    );

    tft.fillScreen(
        COLOR_BACKGROUND
    );

    tft.setTextFont(1);

    tft.setTextSize(1);

    tft.setTextColor(
        COLOR_TEXT
    );
}


// ============================================================
// TFT
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
    tft.fillScreen(
        COLOR_BACKGROUND
    );


    // --------------------------------------------------------
    // HEADER 1
    // --------------------------------------------------------

    tft.fillRect(
        0,
        0,
        SCREEN_WIDTH,
        HEADER1_H,
        COLOR_HEADER1
    );


    // --------------------------------------------------------
    // HEADER 2
    // --------------------------------------------------------

    tft.fillRect(
        0,
        HEADER1_H,
        SCREEN_WIDTH,
        HEADER2_H,
        COLOR_HEADER2
    );


    // --------------------------------------------------------
    // TITRE
    // --------------------------------------------------------

    tft.setTextColor(
        COLOR_TEXT
    );

    tft.setTextSize(2);

    tft.setCursor(
        8,
        6
    );

    tft.print(
        "3x0c3t BO4RD"
    );


    // --------------------------------------------------------
    // SOUS-TITRE
    // --------------------------------------------------------

    tft.setTextSize(1);

    tft.setCursor(
        8,
        HEADER1_H + 7
    );

    tft.print(
        "AFFICHAGE / BENCHMARKS"
    );


    // --------------------------------------------------------
    // LIGNE
    // --------------------------------------------------------

    tft.drawFastHLine(
        0,
        HEADER1_H + HEADER2_H,
        SCREEN_WIDTH,
        TFT_WHITE
    );
}


// ============================================================
// BENCHMARK RUNNING
// ============================================================

void displayDrawBenchmarkRunning(
    uint8_t index
)
{
    tft.fillScreen(
        TFT_BLACK
    );


    tft.setTextColor(
        TFT_YELLOW
    );

    tft.setTextSize(2);

    tft.setCursor(
        10,
        20
    );

    tft.print(
        "BENCHMARK"
    );


    tft.setTextSize(3);

    tft.setCursor(
        10,
        60
    );

    tft.print(
        index + 1
    );


    tft.setTextSize(2);

    tft.setCursor(
        10,
        110
    );

    tft.print(
        "EN COURS..."
    );


    tft.setTextColor(
        TFT_WHITE
    );
}


// ============================================================
// RESULTAT
// ============================================================

void displayDrawBenchmarkResult(
    uint8_t index,
    BenchmarkStatus status
)
{
    tft.fillScreen(
        TFT_BLACK
    );


    tft.setTextSize(2);

    tft.setTextColor(
        TFT_WHITE
    );


    tft.setCursor(
        10,
        20
    );

    tft.print(
        "BENCHMARK "
    );

    tft.print(
        index + 1
    );


    // --------------------------------------------------------
    // RESULTAT
    // --------------------------------------------------------

    if (status == BENCHMARK_OK)
    {
        tft.setTextColor(
            TFT_GREEN
        );

        tft.setCursor(
            10,
            70
        );

        tft.print(
            "VALIDE"
        );
    }
    else
    {
        tft.setTextColor(
            TFT_RED
        );

        tft.setCursor(
            10,
            70
        );

        tft.print(
            "ECHEC"
        );
    }


    delay(400);

    tft.setTextColor(
        TFT_WHITE
    );

    tft.setTextSize(1);
}


// ============================================================
// FIN DES BENCHMARKS
// ============================================================

void displayDrawBenchmarkFinished()
{
    tft.fillScreen(
        TFT_BLACK
    );


    tft.setTextColor(
        TFT_GREEN
    );

    tft.setTextSize(2);


    tft.setCursor(
        30,
        40
    );

    tft.print(
        "BENCHMARKS"
    );


    tft.setCursor(
        55,
        75
    );

    tft.print(
        "TERMINES"
    );


    // --------------------------------------------------------
    // BOUTON RETOUR
    // --------------------------------------------------------

    tft.fillRoundRect(
        40,
        125,
        240,
        45,
        6,
        TFT_DARKGREY
    );


    tft.drawRoundRect(
        40,
        125,
        240,
        45,
        6,
        TFT_WHITE
    );


    tft.setTextColor(
        TFT_WHITE
    );

    tft.setTextSize(2);

    tft.setCursor(
        83,
        140
    );

    tft.print(
        "RETOUR MENU"
    );
}