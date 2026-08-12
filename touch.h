#ifndef TOUCH_H
#define TOUCH_H

#include <Arduino.h>

void touchInit();

bool touchRead(
    uint16_t* x,
    uint16_t* y
);

#endif