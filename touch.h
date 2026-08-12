#ifndef AFFICHAGE_TOUCH_H
#define AFFICHAGE_TOUCH_H

#include <Arduino.h>

void touchInit();

bool touchPressed(
    uint16_t& x,
    uint16_t& y
);

#endif