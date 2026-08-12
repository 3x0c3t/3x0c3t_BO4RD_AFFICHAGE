#include "touch.h"
#include "settings.h"

#include <TFT_eSPI.h>

/*
 * ============================================================
 * 3x0c3t BO4RD - TOUCH
 * ============================================================
 *
 * TFT_eSPI gère le contrôleur tactile via sa configuration
 * User_Setup.h.
 * ============================================================
 */

static TFT_eSPI tft = TFT_eSPI();

/*
 * ============================================================
 * INITIALISATION
 * ============================================================
 */

void touchInit()
{
    /*
     * TFT_eSPI initialise le tactile avec init().
     * On ne redéfinit pas TOUCH_CS ici.
     */
}

/*
 * ============================================================
 * LECTURE
 * ============================================================
 */

bool touchRead(
    uint16_t* x,
    uint16_t* y
)
{
    if (x == nullptr || y == nullptr)
    {
        return false;
    }

    uint16_t tx;
    uint16_t ty;

    if (!tft.getTouch(
        &tx,
        &ty
    ))
    {
        return false;
    }

    *x = tx;
    *y = ty;

    return true;
}