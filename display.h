#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <TFT_eSPI.h>

extern TFT_eSPI tft;

void displayInit();

void displayClear(uint16_t color);

void drawHeader1();
void drawHeader2();

void drawInterface();

void drawBenchmarkButton(
    uint8_t index,
    const char* label,
    bool selected,
    uint16_t statusColor
);

void drawRunButton();

void drawStatus(const char* text);

#endif