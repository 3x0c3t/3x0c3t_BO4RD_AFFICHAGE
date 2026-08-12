#include "menu.h"
#include "settings.h"
#include "display.h"
#include "touch.h"
#include "benchmark.h"

// ============================================================
// ETAT LOCAL
// ============================================================

static bool menuSelected[BENCHMARK_COUNT];

// ============================================================
// COULEUR DU STATUT
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
// POSITION Y D'UN BENCHMARK
// ============================================================

static int benchmarkY(
uint8_t index
)
{
return
HEADER1_H +
HEADER2_H +
8 +
index *
(
BENCHMARK_BUTTON_H +
BENCHMARK_BUTTON_GAP
);
}

// ============================================================
// DESSIN D'UN BENCHMARK
// ============================================================

static void drawBenchmarkButton(
uint8_t index
)
{
TFT_eSPI& tft =
displayGetTFT();

const int y =
    benchmarkY(index);

const bool selected =
    benchmarkIsSelected(index);

const BenchmarkStatus status =
    benchmarkGetStatus(index);

uint16_t background =
    selected
    ? COLOR_SELECTED
    : COLOR_BACKGROUND;

tft.fillRoundRect(
    BENCHMARK_BUTTON_X,
    y,
    BENCHMARK_BUTTON_W,
    BENCHMARK_BUTTON_H,
    4,
    background
);

tft.drawRoundRect(
    BENCHMARK_BUTTON_X,
    y,
    BENCHMARK_BUTTON_W,
    BENCHMARK_BUTTON_H,
    4,
    COLOR_BORDER
);

tft.setTextColor(
    COLOR_TEXT
);

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

// --------------------------------------------------------
// INDICATEUR SELECTION
// --------------------------------------------------------

tft.fillRect(
    145,
    y + 8,
    12,
    12,
    selected
    ? COLOR_OK
    : COLOR_IDLE
);

tft.drawRect(
    145,
    y + 8,
    12,
    12,
    COLOR_TEXT
);

// --------------------------------------------------------
// INDICATEUR STATUT
// --------------------------------------------------------

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
    COLOR_TEXT
);

}

// ============================================================
// DESSIN BOUTON RUN
// ============================================================

static void drawRunButton()
{
TFT_eSPI& tft =
displayGetTFT();

tft.fillRoundRect(
    BUTTON_RUN_X,
    RUN_BUTTON_Y,
    BUTTON_RUN_W,
    BUTTON_RUN_H,
    5,
    0x0320
);

tft.drawRoundRect(
    BUTTON_RUN_X,
    RUN_BUTTON_Y,
    BUTTON_RUN_W,
    BUTTON_RUN_H,
    5,
    COLOR_TEXT
);

tft.setTextColor(
    COLOR_TEXT
);

tft.setTextSize(2);

tft.setCursor(
    105,
    RUN_BUTTON_Y + 7
);

tft.print(
    "LANCER !"
);

}

// ============================================================
// INITIALISATION
// ============================================================

void menuInit()
{
benchmarkInit();

for (
    uint8_t i = 0;
    i < BENCHMARK_COUNT;
    i++
)
{
    menuSelected[i] = false;
}

displayDrawHeader();

for (
    uint8_t i = 0;
    i < BENCHMARK_COUNT;
    i++
)
{
    drawBenchmarkButton(i);
}

drawRunButton();

}

// ============================================================
// BOUCLE
// ============================================================

void menuLoop()
{
int16_t x = 0;
int16_t y = 0;


if (!touchRead(x, y))
{
    return;
}

// --------------------------------------------------------
// BOUTONS BENCHMARK
// --------------------------------------------------------

for (
    uint8_t i = 0;
    i < BENCHMARK_COUNT;
    i++
)
{
    const int buttonY =
        benchmarkY(i);

    if (
        x >= BENCHMARK_BUTTON_X &&
        x < BENCHMARK_BUTTON_X +
            BENCHMARK_BUTTON_W &&
        y >= buttonY &&
        y < buttonY +
            BENCHMARK_BUTTON_H
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

// --------------------------------------------------------
// BOUTON LANCER
// --------------------------------------------------------

if (
    x >= RUN_BUTTON_X &&
    x < RUN_BUTTON_X +
        RUN_BUTTON_W &&
    y >= RUN_BUTTON_Y &&
    y < RUN_BUTTON_Y +
        RUN_BUTTON_H
)
{
    benchmarkRunSelected();

    menuInit();

    delay(300);
}

}
