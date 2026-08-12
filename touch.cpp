#include "touch.h"
#include "settings.h"

#include <TFT_eSPI.h>

static TFT_eSPI touchTft = TFT_eSPI();

// ============================================================
// INITIALISATION
// ============================================================

void touchInit()
{
    pinMode(TOUCH_CS, OUTPUT);

    digitalWrite(
        TOUCH_CS,
        HIGH
    );
}

// ============================================================
// LECTURE
// ============================================================

bool touchRead(
    int16_t& x,
    int16_t& y
)
{
    uint16_t rawX = 0;
    uint16_t rawY = 0;

    if (!touchTft.getTouch(
        &rawX,
        &rawY
    ))
    {
        return false;
    }

    x = rawX;
    y = rawY;

    return true;
}