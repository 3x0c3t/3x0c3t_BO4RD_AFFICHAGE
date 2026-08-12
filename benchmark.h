#ifndef AFFICHAGE_BENCHMARK_H
#define AFFICHAGE_BENCHMARK_H

#include <Arduino.h>

// ============================================================
// ETATS BENCHMARK
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

const char* benchmarkName(uint8_t index);

bool benchmarkIsSelected(uint8_t index);

BenchmarkStatus benchmarkGetStatus(uint8_t index);

// ============================================================
// CONTROLE
// ============================================================

void benchmarkToggle(uint8_t index);

void benchmarkSetStatus(
    uint8_t index,
    BenchmarkStatus status
);

void benchmarkClearAll();

void benchmarkRunSelected();

// ============================================================
// TESTS INDIVIDUELS
// ============================================================

void benchmarkColors();

void benchmarkText();

void benchmarkLines();

void benchmarkRectangles();

void benchmarkCircles();

#endif