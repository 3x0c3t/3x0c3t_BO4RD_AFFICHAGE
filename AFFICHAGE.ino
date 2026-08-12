#include "settings.h"
#include "display.h"
#include "touch.h"
#include "menu.h"
#include "benchmark.h"

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);
    delay(300);

    Serial.println();
    Serial.println("================================");
    Serial.println("       3x0c3t BO4RD");
    Serial.println("       AFFICHAGE / BENCHMARK");
    Serial.println("================================");

    displayInit();

    touchInit();

    menuInit();

    Serial.println();
    Serial.println("[SYSTEM] READY");
}

void loop()
{
    touchUpdate();
}