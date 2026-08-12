#include "touch.h"
#include "settings.h"

#include <TFT_eSPI.h>

extern TFT_eSPI tft;

void touchInit()
{
}

bool touchPressed(
    uint16_t& x,
    uint16_t& y
)
{
    return tft.getTouch(&x, &y);
}

