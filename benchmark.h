#ifndef BENCHMARK_MODULE_H
#define BENCHMARK_MODULE_H

#include <Arduino.h>

// ============================================================
// ETAT DES BENCHMARKS
// ============================================================

enum BenchmarkStatus
{
BENCHMARK_IDLE = 0,
BENCHMARK_RUNNING,
BENCHMARK_OK,
BENCHMARK_ERROR
};

// ============================================================
// INITIALISATION
// ============================================================

void benchmarkInit();

// ============================================================
// INFORMATIONS
// ============================================================

uint8_t benchmarkCount();

const char* benchmarkName(
uint8_t index
);

bool benchmarkIsSelected(
uint8_t index
);

BenchmarkStatus benchmarkGetStatus(
uint8_t index
);

// ============================================================
// SELECTION
// ============================================================

void benchmarkToggle(
uint8_t index
);

void benchmarkSelectAll();

void benchmarkClearAll();

// ============================================================
// EXECUTION
// ============================================================

void benchmarkRunSelected();

// ============================================================
// BENCHMARKS
// ============================================================

void benchmarkColors();

void benchmarkText();

void benchmarkLines();

void benchmarkRectangles();

void benchmarkCircles();

#endif
