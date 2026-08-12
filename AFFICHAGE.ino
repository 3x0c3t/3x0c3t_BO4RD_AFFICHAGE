#include "settings.h"
#include "display.h"
#include "touch.h"

void menuInit();
void menuLoop();

/*
 * ============================================================
 * 3x0c3t BO4RD - AFFICHAGE
 * ============================================================
 */

void setup()
{
    Serial.begin(
        DEBUG_SERIAL_BAUD
    );

    delay(200);

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

    Serial.println(
        "[DISPLAY] Initialisation..."
    );

    displayInit();

    Serial.println(
        "[DISPLAY] OK"
    );

    Serial.println(
        "[TOUCH] Initialisation..."
    );

    touchInit();

    Serial.println(
        "[TOUCH] OK"
    );

    menuInit();

    Serial.println(
        "[MENU] OK"
    );

    Serial.println(
        "[SYSTEM] Pret"
    );
}

void loop()
{
    menuLoop();

    delay(10);
}