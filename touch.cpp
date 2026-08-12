#include "touch.h"
#include "settings.h"
#include "menu.h"

#include <TFT_eSPI.h>

extern TFT_eSPI tft;

// ============================================================
// ETAT TOUCH
// ============================================================

static bool touchWasPressed = false;

// ============================================================
// INITIALISATION
// ============================================================

void touchInit()
{
    Serial.println("[TOUCH] Initialisation...");

    touchWasPressed = false;

    Serial.println("[TOUCH] OK");
}

// ============================================================
// LECTURE TOUCH
// ============================================================

void touchUpdate()
{
    uint16_t x = 0;
    uint16_t y = 0;

    bool pressed = tft.getTouch(
        &x,
        &y
    );

    // Détection uniquement au début de l'appui
    if (pressed && !touchWasPressed)
    {
        touchWasPressed = true;

        Serial.print("[TOUCH] X=");
        Serial.print(x);

        Serial.print(" Y=");
        Serial.println(y);

        menuHandleTouch(
            x,
            y
        );
    }

    // Relâchement
    if (!pressed)
    {
        touchWasPressed = false;
    }

    delay(10);
}