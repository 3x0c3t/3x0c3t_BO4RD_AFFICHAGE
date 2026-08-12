#ifndef TOUCH_MODULE_H
#define TOUCH_MODULE_H

#include <Arduino.h>

// ============================================================
// INITIALISATION
// ============================================================

void touchInit();

// ============================================================
// LECTURE TACTILE
// ============================================================

bool touchRead(
int16_t& x,
int16_t& y
);

#endif
