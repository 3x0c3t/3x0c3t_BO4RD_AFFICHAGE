#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <TFT_eSPI.h>

#include "settings.h"
#include "benchmark.h"

/*
 * ============================================================
 * 3x0c3t BO4RD - DISPLAY
 * ============================================================
 */

void displayInit();

void displayClear();

void displayDrawHeader();

void displayDrawBenchmarkResult(
    uint8_t index,
    BenchmarkStatus status
);

TFT_eSPI* displayGetTFT();

#endif