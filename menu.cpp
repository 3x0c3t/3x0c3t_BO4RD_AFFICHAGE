#include "menu.h"
#include "display.h"
#include "touch.h"
#include "benchmark.h"
#include "settings.h"

static bool inside(
    uint16_t x,
    uint16_t y,
    int16_t bx,
    int16_t by,
    int16_t bw,
    int16_t bh
)
{
    return (
        x >= bx &&
        x < bx + bw &&
        y >= by &&
        y < by + bh
    );
}

void menuInit()
{
    tft.fillScreen(TFT_BLACK);

    displayTitle("DISPLAY BENCHMARK");

    displayButton(
        BUTTON_X1,
        BUTTON_Y1,
        BUTTON_W,
        BUTTON_H,
        "COULEURS",
        TFT_RED
    );

    displayButton(
        BUTTON_X2,
        BUTTON_Y1,
        BUTTON_W,
        BUTTON_H,
        "LIGNES",
        TFT_BLUE
    );

    displayButton(
        BUTTON_X1,
        BUTTON_Y2,
        BUTTON_W,
        BUTTON_H,
        "RECTANGLES",
        TFT_GREEN
    );

    displayButton(
        BUTTON_X2,
        BUTTON_Y2,
        BUTTON_W,
        BUTTON_H,
        "CERCLES",
        TFT_ORANGE
    );

    displayButton(
        BUTTON_X1,
        BUTTON_Y3,
        BUTTON_W,
        BUTTON_H,
        "PIXELS",
        TFT_PURPLE
    );

    displayButton(
        BUTTON_X2,
        BUTTON_Y3,
        BUTTON_W,
        BUTTON_H,
        "TEXTE",
        TFT_CYAN
    );

    displayButton(
        FULL_BUTTON_X,
        BUTTON_Y4,
        FULL_BUTTON_W,
        FULL_BUTTON_H,
        "BENCHMARK COMPLET",
        TFT_DARKGREEN
    );
}

void menuLoop()
{
    uint16_t x;
    uint16_t y;

    if (!touchPressed(x, y))
    {
        return;
    }

    Serial.print("[TOUCH] X=");
    Serial.print(x);
    Serial.print(" Y=");
    Serial.println(y);

    if (inside(
        x,
        y,
        BUTTON_X1,
        BUTTON_Y1,
        BUTTON_W,
        BUTTON_H
    ))
    {
        benchmarkColors();
        menuInit();
    }
    else if (inside(
        x,
        y,
        BUTTON_X2,
        BUTTON_Y1,
        BUTTON_W,
        BUTTON_H
    ))
    {
        benchmarkLines();
        menuInit();
    }
    else if (inside(
        x,
        y,
        BUTTON_X1,
        BUTTON_Y2,
        BUTTON_W,
        BUTTON_H
    ))
    {
        benchmarkRectangles();
        menuInit();
    }
    else if (inside(
        x,
        y,
        BUTTON_X2,
        BUTTON_Y2,
        BUTTON_W,
        BUTTON_H
    ))
    {
        benchmarkCircles();
        menuInit();
    }
    else if (inside(
        x,
        y,
        BUTTON_X1,
        BUTTON_Y3,
        BUTTON_W,
        BUTTON_H
    ))
    {
        benchmarkPixels();
        menuInit();
    }
    else if (inside(
        x,
        y,
        BUTTON_X2,
        BUTTON_Y3,
        BUTTON_W,
        BUTTON_H
    ))
    {
        benchmarkText();
        menuInit();
    }
    else if (inside(
        x,
        y,
        FULL_BUTTON_X,
        BUTTON_Y4,
        FULL_BUTTON_W,
        FULL_BUTTON_H
    ))
    {
        benchmarkAll();
        menuInit();
    }

    delay(250);
}

