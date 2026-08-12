#include "display.h"

static TFT_eSPI tft = TFT_eSPI();

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

TFT_eSPI& displayGetTFT()
{
return tft;
}

void displayClear()
{
tft.fillScreen(COLOR_BACKGROUND);
}

void displayDrawHeader()
{
tft.fillRect(
0,
HEADER_Y,
SCREEN_WIDTH,
HEADER_H,
COLOR_HEADER1
);

tft.setTextColor(
    COLOR_TITLE,
    COLOR_HEADER1
);

tft.setTextSize(1);

tft.setCursor(
    8,
    9
);

tft.print(BOARD_NAME);

tft.drawFastHLine(
    0,
    LINE1_Y,
    SCREEN_WIDTH,
    COLOR_BORDER
);

}

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

uint16_t innerWidth = LOADING_W - 2;

uint16_t width =
    (innerWidth * percent) / 100;

if (width > innerWidth)
{
    width = innerWidth;
}

if (width > 0)
{
    tft.fillRect(
        LOADING_X + 1,
        LOADING_Y + 1,
        width,
        LOADING_H - 2,
        COLOR_SELECTED
    );
}

}

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
    10,
    TITLE_Y + 4
);

tft.print(title);

tft.drawFastHLine(
    0,
    LINE3_Y,
    SCREEN_WIDTH,
    COLOR_BORDER
);

}

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

tft.fillRect(
    BENCHMARK_X,
    y,
    BENCHMARK_W,
    BENCHMARK_H,
    COLOR_BACKGROUND
);

tft.drawRect(
    BENCHMARK_X,
    y,
    BENCHMARK_W,
    BENCHMARK_H,
    color
);

tft.setTextColor(
    color,
    COLOR_BACKGROUND
);

tft.setTextSize(1);

tft.setCursor(
    BENCHMARK_X + 8,
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
    BENCHMARK_X + 220,
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
        tft.print("?");
        break;
}


}
