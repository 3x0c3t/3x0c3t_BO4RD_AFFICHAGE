#include "benchmark.h"
#include "settings.h"
#include "display.h"

// ============================================================
// NOMS
// ============================================================

static const char* benchmarkNames[BENCHMARK_COUNT] =
{
    "B1 - COULEURS",
    "B2 - TEXTE",
    "B3 - RECTANGLES",
    "B4 - LIGNES",
    "B5 - CERCLES",
    "B6 - PIXELS"
};

// ============================================================
// SELECTION
// ============================================================

static bool benchmarkSelected[BENCHMARK_COUNT] =
{
    false,
    false,
    false,
    false,
    false,
    false
};

// ============================================================
// ETAT
// 0 = NON LANCE
// 1 = EN COURS
// 2 = VALIDE
// 3 = ECHOUE
// ============================================================

static uint8_t benchmarkStatus[BENCHMARK_COUNT] =
{
    0,
    0,
    0,
    0,
    0,
    0
};

// ============================================================
// NOM
// ============================================================

const char* benchmarkGetName(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
    {
        return "";
    }

    return benchmarkNames[index];
}

// ============================================================
// SELECTION
// ============================================================

bool benchmarkIsSelected(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
    {
        return false;
    }

    return benchmarkSelected[index];
}

// ============================================================
// TOGGLE
// ============================================================

void benchmarkToggle(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
    {
        return;
    }

    benchmarkSelected[index] =
        !benchmarkSelected[index];

    // Une nouvelle sélection remet le statut à
    // "non lancé"
    benchmarkStatus[index] = 0;
}

// ============================================================
// COULEUR ETAT
// ============================================================

uint16_t benchmarkGetStatusColor(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
    {
        return COLOR_STATUS_NONE;
    }

    switch (benchmarkStatus[index])
    {
        case 1:
            return COLOR_STATUS_RUNNING;

        case 2:
            return COLOR_STATUS_OK;

        case 3:
            return COLOR_STATUS_ERROR;

        default:
            return COLOR_STATUS_NONE;
    }
}

// ============================================================
// B1 - COULEURS
// ============================================================

static bool runColors()
{
    Serial.println("[B1] COULEURS");

    tft.fillScreen(TFT_RED);
    delay(300);

    tft.fillScreen(TFT_GREEN);
    delay(300);

    tft.fillScreen(TFT_BLUE);
    delay(300);

    tft.fillScreen(TFT_WHITE);
    delay(300);

    tft.fillScreen(TFT_BLACK);
    delay(300);

    return true;
}

// ============================================================
// B2 - TEXTE
// ============================================================

static bool runText()
{
    Serial.println("[B2] TEXTE");

    tft.fillScreen(TFT_BLACK);

    tft.setTextColor(TFT_WHITE);
    tft.setTextDatum(MC_DATUM);

    tft.drawString(
        "3x0c3t BO4RD",
        SCREEN_WIDTH / 2,
        SCREEN_HEIGHT / 2,
        4
    );

    delay(1000);

    return true;
}

// ============================================================
// B3 - RECTANGLES
// ============================================================

static bool runRectangles()
{
    Serial.println("[B3] RECTANGLES");

    tft.fillScreen(TFT_BLACK);

    for (int i = 0; i < 100; i += 10)
    {
        tft.drawRect(
            i,
            i,
            SCREEN_WIDTH - 2 * i,
            SCREEN_HEIGHT - 2 * i,
            TFT_WHITE
        );

        delay(20);
    }

    delay(500);

    return true;
}

// ============================================================
// B4 - LIGNES
// ============================================================

static bool runLines()
{
    Serial.println("[B4] LIGNES");

    tft.fillScreen(TFT_BLACK);

    for (int x = 0; x < SCREEN_WIDTH; x += 5)
    {
        tft.drawLine(
            0,
            0,
            x,
            SCREEN_HEIGHT,
            TFT_GREEN
        );
    }

    for (int y = 0; y < SCREEN_HEIGHT; y += 5)
    {
        tft.drawLine(
            0,
            0,
            SCREEN_WIDTH,
            y,
            TFT_BLUE
        );
    }

    delay(500);

    return true;
}

// ============================================================
// B5 - CERCLES
// ============================================================

static bool runCircles()
{
    Serial.println("[B5] CERCLES");

    tft.fillScreen(TFT_BLACK);

    int cx = SCREEN_WIDTH / 2;
    int cy = SCREEN_HEIGHT / 2;

    for (int r = 5; r < 110; r += 5)
    {
        tft.drawCircle(
            cx,
            cy,
            r,
            TFT_CYAN
        );
    }

    delay(500);

    return true;
}

// ============================================================
// B6 - PIXELS
// ============================================================

static bool runPixels()
{
    Serial.println("[B6] PIXELS");

    tft.fillScreen(TFT_BLACK);

    for (int y = 0; y < SCREEN_HEIGHT; y += 4)
    {
        for (int x = 0; x < SCREEN_WIDTH; x += 4)
        {
            tft.drawPixel(
                x,
                y,
                TFT_WHITE
            );
        }
    }

    delay(500);

    return true;
}

// ============================================================
// EXECUTION D'UN BENCHMARK
// ============================================================

static bool runBenchmark(uint8_t index)
{
    switch (index)
    {
        case 0:
            return runColors();

        case 1:
            return runText();

        case 2:
            return runRectangles();

        case 3:
            return runLines();

        case 4:
            return runCircles();

        case 5:
            return runPixels();

        default:
            return false;
    }
}

// ============================================================
// LANCEMENT DES BENCHMARKS SELECTIONNES
// ============================================================

void benchmarkRunSelected()
{
    bool atLeastOne = false;

    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        if (!benchmarkSelected[i])
        {
            continue;
        }

        atLeastOne = true;

        benchmarkStatus[i] = 1;

        Serial.print("[BENCH] START ");
        Serial.println(
            benchmarkGetName(i)
        );

        bool result =
            runBenchmark(i);

        benchmarkStatus[i] =
            result ? 2 : 3;

        Serial.print("[BENCH] ");
        Serial.print(
            benchmarkGetName(i)
        );

        Serial.println(
            result
            ? " -> VALIDE"
            : " -> ECHOUE"
        );
    }

    if (!atLeastOne)
    {
        Serial.println(
            "[BENCH] Aucun benchmark selectionne"
        );

        tft.fillScreen(COLOR_BACKGROUND);

        drawHeader1();
        drawHeader2();

        drawStatus(
            "Aucun benchmark selectionne"
        );

        delay(1200);
    }
}