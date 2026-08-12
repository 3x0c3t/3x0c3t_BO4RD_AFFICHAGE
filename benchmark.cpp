#include "benchmark.h"
#include "display.h"


// ============================================================
// ETAT
// ============================================================

static bool selected[BENCHMARK_COUNT];

static BenchmarkStatus status[
    BENCHMARK_COUNT
];

static int result[
    BENCHMARK_COUNT
];


// ============================================================
// NOMS
// ============================================================

const char* benchmarkName(
    uint8_t index
)
{
    switch (index)
    {
        case 0:
            return "COLORS";

        case 1:
            return "TEXT";

        case 2:
            return "LINES";

        case 3:
            return "RECTANGLES";

        case 4:
            return "CIRCLES";

        default:
            return "UNKNOWN";
    }
}


// ============================================================
// NOMBRE
// ============================================================

uint8_t benchmarkCount()
{
    return BENCHMARK_COUNT;
}


// ============================================================
// INITIALISATION
// ============================================================

void benchmarkInit()
{
    for (
        uint8_t i = 0;
        i < BENCHMARK_COUNT;
        i++
    )
    {
        selected[i] = false;

        status[i] =
            BENCHMARK_IDLE;

        result[i] = 0;
    }
}


// ============================================================
// SELECTION
// ============================================================

bool benchmarkIsSelected(
    uint8_t index
)
{
    if (index >= BENCHMARK_COUNT)
    {
        return false;
    }

    return selected[index];
}


// ============================================================
// STATUS
// ============================================================

BenchmarkStatus benchmarkGetStatus(
    uint8_t index
)
{
    if (index >= BENCHMARK_COUNT)
    {
        return BENCHMARK_ERROR;
    }

    return status[index];
}


// ============================================================
// TOGGLE
// ============================================================

void benchmarkToggle(
    uint8_t index
)
{
    if (index >= BENCHMARK_COUNT)
    {
        return;
    }

    selected[index] =
        !selected[index];
}


// ============================================================
// SELECT ALL
// ============================================================

void benchmarkSelectAll()
{
    for (
        uint8_t i = 0;
        i < BENCHMARK_COUNT;
        i++
    )
    {
        selected[i] = true;
    }
}


// ============================================================
// CLEAR ALL
// ============================================================

void benchmarkClearAll()
{
    for (
        uint8_t i = 0;
        i < BENCHMARK_COUNT;
        i++
    )
    {
        selected[i] = false;
    }
}


// ============================================================
// BENCHMARK COLORS
// ============================================================

void benchmarkColors()
{
    TFT_eSPI& tft =
        displayGetTFT();

    tft.fillScreen(TFT_RED);
    delay(250);

    tft.fillScreen(TFT_GREEN);
    delay(250);

    tft.fillScreen(TFT_BLUE);
    delay(250);

    tft.fillScreen(TFT_BLACK);
}


// ============================================================
// BENCHMARK TEXT
// ============================================================

void benchmarkText()
{
    TFT_eSPI& tft =
        displayGetTFT();

    tft.fillScreen(TFT_BLACK);

    tft.setTextColor(TFT_WHITE);

    tft.setTextSize(1);

    for (
        uint16_t y = 0;
        y < SCREEN_HEIGHT;
        y += 16
    )
    {
        tft.setCursor(
            5,
            y
        );

        tft.print(
            "3x0c3t BO4RD TEXT TEST"
        );
    }

    delay(500);
}


// ============================================================
// BENCHMARK LINES
// ============================================================

void benchmarkLines()
{
    TFT_eSPI& tft =
        displayGetTFT();

    tft.fillScreen(TFT_BLACK);

    for (
        uint16_t x = 0;
        x < SCREEN_WIDTH;
        x += 10
    )
    {
        tft.drawLine(
            0,
            0,
            x,
            SCREEN_HEIGHT - 1,
            TFT_CYAN
        );
    }

    for (
        uint16_t y = 0;
        y < SCREEN_HEIGHT;
        y += 10
    )
    {
        tft.drawLine(
            0,
            0,
            SCREEN_WIDTH - 1,
            y,
            TFT_GREEN
        );
    }

    delay(500);
}


// ============================================================
// BENCHMARK RECTANGLES
// ============================================================

void benchmarkRectangles()
{
    TFT_eSPI& tft =
        displayGetTFT();

    tft.fillScreen(TFT_BLACK);

    for (
        uint16_t size = 10;
        size < 120;
        size += 10
    )
    {
        int16_t x =
            (SCREEN_WIDTH - size) / 2;

        int16_t y =
            (SCREEN_HEIGHT - size) / 2;

        tft.drawRect(
            x,
            y,
            size,
            size,
            TFT_YELLOW
        );
    }

    delay(500);
}


// ============================================================
// BENCHMARK CIRCLES
// ============================================================

void benchmarkCircles()
{
    TFT_eSPI& tft =
        displayGetTFT();

    tft.fillScreen(TFT_BLACK);

    int16_t cx =
        SCREEN_WIDTH / 2;

    int16_t cy =
        SCREEN_HEIGHT / 2;

    for (
        uint16_t radius = 10;
        radius < 120;
        radius += 10
    )
    {
        tft.drawCircle(
            cx,
            cy,
            radius,
            TFT_MAGENTA
        );
    }

    delay(500);
}


// ============================================================
// EXECUTION
// ============================================================

void benchmarkRunSelected()
{
    for (
        uint8_t i = 0;
        i < BENCHMARK_COUNT;
        i++
    )
    {
        if (!selected[i])
        {
            continue;
        }


        // ----------------------------------------------------
        // RUNNING
        // ----------------------------------------------------

        status[i] =
            BENCHMARK_RUNNING;

        displayDrawBenchmarkResult(
            i,
            status[i],
            0
        );


        // ----------------------------------------------------
        // MESURE
        // ----------------------------------------------------

        unsigned long start =
            millis();


        // ----------------------------------------------------
        // EXECUTION
        // ----------------------------------------------------

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
                status[i] =
                    BENCHMARK_ERROR;
                break;
        }


        // ----------------------------------------------------
        // TEMPS
        // ----------------------------------------------------

        unsigned long elapsed =
            millis() - start;


        // ----------------------------------------------------
        // RESULTAT
        // ----------------------------------------------------

        result[i] = elapsed;

        status[i] =
            BENCHMARK_OK;

        displayDrawBenchmarkResult(
            i,
            status[i],
            elapsed
        );

        delay(300);
    }
}