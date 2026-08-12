#ifndef TOUCH_MODULE_H
#define TOUCH_MODULE_H

#include <Arduino.h>

void touchInit();

bool touchRead(
    int16_t& x,
    int16_t& y
);

#endif