#include "settings.h"
#include "display.h"
#include "touch.h"
#include "menu.h"

// ============================================================
// SETUP
// ============================================================

void setup()
{
    Serial.begin(
        115200
    );

    delay(300);

    Serial.println();
    Serial.println(
        "=============================="
    );

    Serial.println(
        "  3x0c3t BO4RD AFFICHAGE"
    );

    Serial.println(
        "=============================="
    );

    // --------------------------------------------------------
    // TFT
    // --------------------------------------------------------

    Serial.println(
        "[TFT] Initialisation..."
    );

    displayInit();

    Serial.println(
        "[TFT] OK"
    );

    // --------------------------------------------------------
    // TOUCH
    // --------------------------------------------------------

    Serial.println(
        "[TOUCH] Initialisation..."
    );

    touchInit();

    Serial.println(
        "[TOUCH] OK"
    );

    // --------------------------------------------------------
    // MENU
    // --------------------------------------------------------

    menuInit();

    Serial.println(
        "[MENU] OK"
    );

    Serial.println();
    Serial.println(
        "[SYSTEM] Pret."
    );
}

// ============================================================
// LOOP
// ============================================================

void loop()
{
    menuLoop();

    delay(5);
}