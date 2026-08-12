#include "settings.h"
#include "display.h"
#include "menu.h"
#include "touch.h"

// ============================================================
// SETUP
// ============================================================

void setup()
{
    Serial.begin(DEBUG_SERIAL_BAUD);

    delay(200);

    Serial.println();
    Serial.println("==============================");
    Serial.println("  3x0c3t BO4RD AFFICHAGE");
    Serial.println("==============================");

    Serial.println("[TFT] Initialisation...");

    displayInit();

    Serial.println("[TFT] OK");

    Serial.println("[TOUCH] Initialisation...");

    touchInit();

    Serial.println("[TOUCH] OK");

    menuInit();

    Serial.println("[MENU] OK");
}

// ============================================================
// LOOP
// ============================================================

void loop()
{
    menuLoop();

    delay(10);
}