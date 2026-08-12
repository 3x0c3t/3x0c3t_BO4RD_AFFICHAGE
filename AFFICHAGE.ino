#include "settings.h"
#include "display.h"
#include "touch.h"
#include "menu.h"

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);
    delay(200);

    Serial.println();
    Serial.println("==============================");
    Serial.println("   3x0c3t BO4RD");
    Serial.println("   AFFICHAGE BENCHMARK");
    Serial.println("==============================");

    Serial.println("[TFT] Initialisation...");
    displayInit();
    Serial.println("[TFT] OK");

    Serial.println("[TOUCH] Initialisation...");
    touchInit();
    Serial.println("[TOUCH] OK");

    menuInit();

    Serial.println("[SYSTEM] Benchmark pret.");
}

void loop()
{
    menuLoop();
}
