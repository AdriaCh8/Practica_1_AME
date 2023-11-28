#ifndef MBED_ROTATOR_H
#define MBED_ROTATOR_H

#include "mbed.h"

class Rotator {
public:
    Rotator(PinName pin);
    unsigned int calculate_value();

private:
    AnalogIn potenciometro;
    unsigned int r;
};

#endif