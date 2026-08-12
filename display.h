#ifndef DISPLAY_MODULE_H
#define DISPLAY_MODULE_H

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

void displayClear();

void displayDrawHeader();

// ============================================================
// BENCHMARK
// ============================================================

void displayDrawBenchmarkRunning(
uint8_t index
);

void displayDrawBenchmarkResult(
uint8_t index,
BenchmarkStatus status
);

void displayDrawBenchmarkFinished();

#endif
