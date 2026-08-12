#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <Arduino.h>

#include "settings.h"

// ============================================================
// BENCHMARK
// ============================================================

void benchmarkInit();

void benchmarkRunSelected();

void benchmarkToggle(uint8_t index);

bool benchmarkIsSelected(uint8_t index);

BenchmarkStatus benchmarkGetStatus(uint8_t index);

const char* benchmarkName(uint8_t index);

#endif