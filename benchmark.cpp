#include "benchmark.h"
#include "settings.h"
#include "display.h"

#include <Arduino.h>
#include <TFT_eSPI.h>

// ============================================================
// NOMS DES BENCHMARKS
// ============================================================

static const char* benchmarkNames[BENCHMARK_COUNT] =
{
    "B1 - COULEURS",
    "B2 - TEXTE",
    "B3 - LIGNES",
    "B4 - RECTANGLES",
    "B5 - CERCLES"
};

// ============================================================
// SELECTIONS
// ============================================================

static bool benchmarkSelections[BENCHMARK_COUNT] =
{
    false,
    false,
    false,
    false,
    false
};

// ============================================================
// ETATS
// ============================================================

static BenchmarkStatus benchmarkStatuses[BENCHMARK_COUNT] =
{
    BENCHMARK_IDLE,
    BENCHMARK_IDLE,
    BENCHMARK_IDLE,
    BENCHMARK_IDLE,
    BENCHMARK_IDLE
};

// ============================================================
// INITIALISATION
// ============================================================

void benchmarkInit()
{
    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        benchmarkSelections[i] = false;
        benchmarkStatuses[i] = BENCHMARK_IDLE;
    }
}

// ============================================================
// NOM
// ============================================================

const char* benchmarkName(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
    {
        return "INCONNU";
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

    return benchmarkSelections[index];
}

// ============================================================
// ETAT
// ============================================================

BenchmarkStatus benchmarkGetStatus(uint8_t index)
{
    if (index >= BENCHMARK_COUNT)
    {
        return BENCHMARK_ERROR;
    }

    return benchmarkStatuses[index];
}

// ============================================================
// MODIFICATION ETAT
// ============================================================

void benchmarkSetStatus(
    uint8_t index,
    BenchmarkStatus status
)
{
    if (index >= BENCHMARK_COUNT)
    {
        return;
    }

    benchmarkStatuses[index] = status;
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

    benchmarkSelections[index] =
        !benchmarkSelections[index];

    benchmarkStatuses[index] =
        BENCHMARK_IDLE;
}

// ============================================================
// TOUT EFFACER
// ============================================================

void benchmarkClearAll()
{
    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        benchmarkSelections[i] = false;
        benchmarkStatuses[i] = BENCHMARK_IDLE;
    }
}

// ============================================================
// EXECUTION
// ============================================================

void benchmarkRunSelected()
{
    bool selected = false;

    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        if (benchmarkSelections[i])
        {
            selected = true;
            break;
        }
    }

    if (!selected)
    {
        Serial.println("[BENCH] Aucun benchmark selectionne");
        return;
    }

    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        if (!benchmarkSelections[i])
        {
            continue;
        }

        Serial.print("[BENCH] Execution : ");
        Serial.println(benchmarkNames[i]);

        benchmarkStatuses[i] =
            BENCHMARK_RUNNING;

        displayDrawMenu();

        delay(150);

        switch (i)
        {
            case 0:
                benchmarkColors();
                break;

            case 1:
                benchmarkText();
                break;

            case 2:
                benchmarkLines();
                break;

            case 3:
                benchmarkRectangles();
                break;

            case 4:
                benchmarkCircles();
                break;

            default:
                benchmarkStatuses[i] =
                    BENCHMARK_ERROR;
                break;
        }

        displayDrawMenu();

        delay(300);
    }

    Serial.println("[BENCH] Execution terminee");
}

// ============================================================
// B1 - COULEURS
// ============================================================

void benchmarkColors()
{
    TFT_eSPI& tft = displayGetTFT();

    unsigned long start = millis();

    tft.fillScreen(TFT_RED);
    delay(250);

    tft.fillScreen(TFT_GREEN);
    delay(250);

    tft.fillScreen(TFT_BLUE);
    delay(250);

    tft.fillScreen(TFT_BLACK);
    delay(100);

    unsigned long elapsed =
        millis() - start;

    Serial.print("[BENCH] Couleurs : ");
    Serial.print(elapsed);
    Serial.println(" ms");

    benchmarkStatuses[0] =
        BENCHMARK_OK;
}

// ============================================================
// B2 - TEXTE
// ============================================================

void benchmarkText()
{
    TFT_eSPI& tft = displayGetTFT();

    unsigned long start = millis();

    tft.fillScreen(TFT_BLACK);

    tft.setTextColor(
        TFT_WHITE,
        TFT_BLACK
    );

    tft.setTextSize(1);

    for (uint16_t y = 0; y < 220; y += 12)
    {
        tft.setCursor(
            5,
            y
        );

        tft.print(
            "3x0c3t BO4RD DISPLAY TEST"
        );
    }

    unsigned long elapsed =
        millis() - start;

    Serial.print("[BENCH] Texte : ");
    Serial.print(elapsed);
    Serial.println(" ms");

    benchmarkStatuses[1] =
        BENCHMARK_OK;
}

// ============================================================
// B3 - LIGNES
// ============================================================

void benchmarkLines()
{
    TFT_eSPI& tft = displayGetTFT();

    unsigned long start = millis();

    tft.fillScreen(TFT_BLACK);

    for (uint16_t x = 0; x < 320; x += 10)
    {
        tft.drawLine(
            0,
            0,
            x,
            239,
            TFT_WHITE
        );
    }

    for (uint16_t y = 0; y < 240; y += 10)
    {
        tft.drawLine(
            0,
            0,
            319,
            y,
            TFT_CYAN
        );
    }

    unsigned long elapsed =
        millis() - start;

    Serial.print("[BENCH] Lignes : ");
    Serial.print(elapsed);
    Serial.println(" ms");

    benchmarkStatuses[2] =
        BENCHMARK_OK;
}

// ============================================================
// B4 - RECTANGLES
// ============================================================

void benchmarkRectangles()
{
    TFT_eSPI& tft = displayGetTFT();

    unsigned long start = millis();

    tft.fillScreen(TFT_BLACK);

    for (uint16_t i = 0; i < 110; i += 5)
    {
        tft.drawRect(
            i,
            i / 2,
            320 - (i * 2),
            240 - i,
            TFT_GREEN
        );
    }

    unsigned long elapsed =
        millis() - start;

    Serial.print("[BENCH] Rectangles : ");
    Serial.print(elapsed);
    Serial.println(" ms");

    benchmarkStatuses[3] =
        BENCHMARK_OK;
}

// ============================================================
// B5 - CERCLES
// ============================================================

void benchmarkCircles()
{
    TFT_eSPI& tft = displayGetTFT();

    unsigned long start = millis();

    tft.fillScreen(TFT_BLACK);

    for (uint16_t r = 5; r < 115; r += 5)
    {
        tft.drawCircle(
            160,
            120,
            r,
            TFT_YELLOW
        );
    }

    unsigned long elapsed =
        millis() - start;

    Serial.print("[BENCH] Cercles : ");
    Serial.print(elapsed);
    Serial.println(" ms");

    benchmarkStatuses[4] =
        BENCHMARK_OK;
}