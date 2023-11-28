#ifndef MBED_LUXER_H
#define MBED_LUXER_H

#include "mbed.h"

class Luxer {
public:
    Luxer(PinName pin);
    float calculate_lux();

private:
    AnalogIn light;
};

#endif