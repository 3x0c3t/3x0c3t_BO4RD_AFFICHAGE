#include "touch.h"
#include "settings.h"

#include <TFT_eSPI.h>

// ============================================================
// OBJET TFT / TOUCH
// ============================================================

static TFT_eSPI touchTFT;

// ============================================================
// INITIALISATION
// ============================================================

void touchInit()
{
    touchTFT.init();

    touchTFT.setRotation(
        TFT_ROTATION
    );
}

// ============================================================
// LECTURE TACTILE
// ============================================================

bool touchPressed(
    uint16_t& x,
    uint16_t& y
)
{
    uint16_t tx = 0;
    uint16_t ty = 0;

    if (!touchTFT.getTouch(
        &tx,
        &ty
    ))
    {
        return false;
    }

    x = tx;
    y = ty;

    return true;
}