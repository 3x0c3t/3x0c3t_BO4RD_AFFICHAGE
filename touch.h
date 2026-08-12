#ifndef TOUCH_H
#define TOUCH_H

#include <stdint.h>

void touchInit();

bool touchPressed(
    uint16_t& x,
    uint16_t& y
);

#endif
