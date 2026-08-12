#ifndef DISPLAY_H
#define DISPLAY_H

#include <TFT_eSPI.h>

extern TFT_eSPI tft;

void displayInit();
void displayClear(uint16_t color);
void displayTitle(const char* title);
void displayButton(
    int16_t x,
    int16_t y,
    int16_t w,
    int16_t h,
    const char* label,
    uint16_t color
);

#endif
