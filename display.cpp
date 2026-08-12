#include "display.h"
#include "settings.h"

TFT_eSPI tft = TFT_eSPI();

void displayInit()
{
    tft.init();

    // Rotation 2
    tft.setRotation(2);

    tft.fillScreen(TFT_BACKGROUND);
}

void displayClear(uint16_t color)
{
    tft.fillScreen(color);
}

void displayTitle(const char* title)
{
    tft.fillRect(
        0,
        0,
        SCREEN_WIDTH,
        55,
        TFT_NAVY
    );

    tft.setTextColor(TFT_WHITE, TFT_NAVY);
    tft.setTextDatum(MC_DATUM);

    tft.drawString(
        title,
        SCREEN_WIDTH / 2,
        27,
        2
    );

    tft.setTextDatum(TL_DATUM);
}

void displayButton(
    int16_t x,
    int16_t y,
    int16_t w,
    int16_t h,
    const char* label,
    uint16_t color
)
{
    tft.fillRoundRect(
        x,
        y,
        w,
        h,
        6,
        color
    );

    tft.drawRoundRect(
        x,
        y,
        w,
        h,
        6,
        TFT_WHITE
    );

    tft.setTextColor(
        TFT_WHITE,
        color
    );

    tft.setTextDatum(MC_DATUM);

    tft.drawString(
        label,
        x + w / 2,
        y + h / 2,
        2
    );

    tft.setTextDatum(TL_DATUM);
}