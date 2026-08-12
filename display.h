#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <TFT_eSPI.h>

#include "settings.h"

// ============================================================
// DISPLAY
// ============================================================

void displayInit();

void displayClear();

TFT_eSPI& displayGetTFT();

void displayDrawHeader();

void displayDrawLoading(uint8_t percent);

void displayDrawTitle(const char* title);

void displayDrawBenchmarkResult(
    uint8_t index,
    BenchmarkStatus status,
    int value
);

#endif