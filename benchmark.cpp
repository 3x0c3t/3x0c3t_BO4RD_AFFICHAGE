#include "benchmark.h"
#include "display.h"
#include "settings.h"

static void waitAndReturn()
{
    delay(500);

    tft.fillScreen(TFT_BLACK);

    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);

    tft.drawString("TEST TERMINE", SCREEN_WIDTH / 2, 80, 2);
    tft.drawString("Retour au menu...", SCREEN_WIDTH / 2, 120, 2);

    tft.setTextDatum(TL_DATUM);

    delay(1200);
}

void benchmarkColors()
{
    displayTitle("BENCHMARK COULEURS");

    const uint16_t colors[] =
    {
        TFT_BLACK,
        TFT_WHITE,
        TFT_RED,
        TFT_GREEN,
        TFT_BLUE,
        TFT_YELLOW,
        TFT_CYAN,
        TFT_MAGENTA
    };

    const uint8_t count = sizeof(colors) / sizeof(colors[0]);

    unsigned long start = millis();

    for (uint8_t i = 0; i < count; i++)
    {
        tft.fillScreen(colors[i]);
        delay(250);
    }

    unsigned long elapsed = millis() - start;

    tft.fillScreen(TFT_BLACK);

    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);

    tft.drawString("COULEURS", 120, 70, 2);

    char buffer[32];

    sprintf(buffer, "Temps : %lu ms", elapsed);
    tft.drawString(buffer, 120, 120, 2);

    sprintf(buffer, "Tests  : %u", count);
    tft.drawString(buffer, 120, 150, 2);

    tft.setTextDatum(TL_DATUM);

    waitAndReturn();
}

void benchmarkLines()
{
    displayTitle("BENCHMARK LIGNES");

    unsigned long start = millis();

    for (int y = 0; y < SCREEN_HEIGHT; y += 4)
    {
        tft.drawLine(0, y, SCREEN_WIDTH - 1, SCREEN_HEIGHT - y - 1, TFT_GREEN);
    }

    for (int x = 0; x < SCREEN_WIDTH; x += 4)
    {
        tft.drawLine(x, 0, SCREEN_WIDTH - x - 1, SCREEN_HEIGHT - 1, TFT_CYAN);
    }

    unsigned long elapsed = millis() - start;

    tft.fillRect(20, 130, 200, 60, TFT_BLACK);

    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);

    char buffer[32];

    sprintf(buffer, "Temps : %lu ms", elapsed);
    tft.drawString(buffer, 120, 145, 2);

    sprintf(buffer, "FPS : %lu", elapsed ? 1000UL / elapsed : 0);
    tft.drawString(buffer, 120, 175, 2);

    tft.setTextDatum(TL_DATUM);

    waitAndReturn();
}

void benchmarkRectangles()
{
    displayTitle("BENCHMARK RECTANGLES");

    unsigned long start = millis();

    for (int i = 0; i < 80; i++)
    {
        int x = i % 120;
        int y = (i * 3) % 160;
        int w = 20 + (i % 60);
        int h = 15 + (i % 50);

        tft.drawRect(x, y + 60, w, h, TFT_YELLOW);
    }

    for (int i = 0; i < 30; i++)
    {
        int x = i % 100;
        int y = (i * 5) % 150;

        tft.fillRect(
            x,
            y + 60,
            15 + i,
            10 + (i % 20),
            TFT_BLUE
        );
    }

    unsigned long elapsed = millis() - start;

    tft.fillRect(20, 270, 200, 35, TFT_BLACK);

    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);

    char buffer[32];

    sprintf(buffer, "%lu ms", elapsed);
    tft.drawString(buffer, 120, 285, 2);

    tft.setTextDatum(TL_DATUM);

    waitAndReturn();
}

void benchmarkCircles()
{
    displayTitle("BENCHMARK CERCLES");

    unsigned long start = millis();

    for (int r = 5; r < 110; r += 5)
    {
        tft.drawCircle(
            SCREEN_WIDTH / 2,
            185,
            r,
            TFT_CYAN
        );
    }

    unsigned long elapsed = millis() - start;

    tft.fillRect(20, 65, 200, 35, TFT_BLACK);

    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);

    char buffer[32];

    sprintf(buffer, "Temps : %lu ms", elapsed);
    tft.drawString(buffer, 120, 82, 2);

    tft.setTextDatum(TL_DATUM);

    waitAndReturn();
}

void benchmarkPixels()
{
    displayTitle("BENCHMARK PIXELS");

    unsigned long start = millis();

    for (int y = 60; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            uint16_t color =
                tft.color565(
                    x % 256,
                    y % 256,
                    (x + y) % 256
                );

            tft.drawPixel(x, y, color);
        }
    }

    unsigned long elapsed = millis() - start;

    tft.fillRect(20, 130, 200, 60, TFT_BLACK);

    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);

    char buffer[32];

    sprintf(buffer, "Temps : %lu ms", elapsed);
    tft.drawString(buffer, 120, 145, 2);

    sprintf(
        buffer,
        "Pixels : %lu",
        (unsigned long)SCREEN_WIDTH * (SCREEN_HEIGHT - 60)
    );

    tft.drawString(buffer, 120, 175, 2);

    tft.setTextDatum(TL_DATUM);

    waitAndReturn();
}

void benchmarkText()
{
    displayTitle("BENCHMARK TEXTE");

    unsigned long start = millis();

    for (int i = 0; i < 100; i++)
    {
        tft.setTextColor(
            tft.color565(
                (i * 2) % 255,
                (i * 3) % 255,
                (i * 5) % 255
            ),
            TFT_BLACK
        );

        tft.drawString(
            "3x0c3t BO4RD",
            20 + (i % 5) * 5,
            65 + (i % 20) * 10,
            2
        );
    }

    unsigned long elapsed = millis() - start;

    tft.fillRect(20, 270, 200, 35, TFT_BLACK);

    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);

    char buffer[32];

    sprintf(buffer, "%lu ms", elapsed);
    tft.drawString(buffer, 120, 285, 2);

    tft.setTextDatum(TL_DATUM);

    waitAndReturn();
}

void benchmarkAll()
{
    benchmarkColors();
    benchmarkLines();
    benchmarkRectangles();
    benchmarkCircles();
    benchmarkPixels();
    benchmarkText();
}

