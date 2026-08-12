#ifndef DISPLAY_MODULE_H
#define DISPLAY_MODULE_H

#include <Arduino.h>
#include <TFT_eSPI.h>

void displayInit();

TFT_eSPI& displayGetTFT();

void displayClear();

void displayDrawHeader();

void displayDrawBenchmarkRunning(
    uint8_t index
);

void displayDrawBenchmarkResult(
    uint8_t index,
    uint8_t status
);

void displayDrawBenchmarkFinished();

#endif