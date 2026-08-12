#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <Arduino.h>

#define BENCHMARK_COUNT 6

const char* benchmarkGetName(uint8_t index);

bool benchmarkIsSelected(uint8_t index);

void benchmarkToggle(uint8_t index);

uint16_t benchmarkGetStatusColor(uint8_t index);

void benchmarkRunSelected();

#endif