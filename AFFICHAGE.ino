#include "settings.h"
#include "display.h"
#include "touch.h"
#include "menu.h"

void setup()
{
    Serial.begin(115200);

    delay(500);

    Serial.println();
    Serial.println("==============================");
    Serial.println("   3x0c3t BO4RD");
    Serial.println("   AFFICHAGE");
    Serial.println("==============================");

    Serial.println("[TFT] Initialisation...");

    displayInit();

    Serial.println("[TFT] OK");

    Serial.println("[TOUCH] Initialisation...");

    touchInit();

    Serial.println("[TOUCH] OK");

    menuInit();

    Serial.println("[MENU] Pret");
}

void loop()
{
    menuLoop();

    delay(20);
}