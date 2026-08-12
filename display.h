#ifndef AFFICHAGE_DISPLAY_H
#define AFFICHAGE_DISPLAY_H

#include <Arduino.h>
#include <TFT_eSPI.h>

#include "benchmark.h"

// ============================================================
// INITIALISATION
// ============================================================

void displayInit();

// ============================================================
// ACCES TFT
// ============================================================

TFT_eSPI& displayGetTFT();

// ============================================================
// AFFICHAGE
// ============================================================

void displayDrawMenu();

void displayDrawBenchmarkResult(
    uint8_t index,
    BenchmarkStatus status
);

#endif