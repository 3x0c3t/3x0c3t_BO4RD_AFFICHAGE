#ifndef BO4RD_DISPLAY_H
#define BO4RD_DISPLAY_H

#include <Arduino.h>

#include "settings.h"
#include "benchmark.h"

#include <TFT_eSPI.h>


// ============================================================
// INITIALISATION
// ============================================================

void displayInit();


// ============================================================
// ACCES TFT
// ============================================================

TFT_eSPI& displayGetTFT();


// ============================================================
// AFFICHAGE GENERAL
// ============================================================

void displayClear();

void displayDrawHeader();

void displayDrawLoading(uint8_t percent);

void displayDrawTitle(const char* title);


// ============================================================
// BENCHMARK
// ============================================================

void displayDrawBenchmarkRunning(
    uint8_t index
);

void displayDrawBenchmarkResult(
    uint8_t index,
    BenchmarkStatus status,
    int elapsedMs = 0,
    int fps = 0
);

void displayDrawBenchmarkFinished();


#endif