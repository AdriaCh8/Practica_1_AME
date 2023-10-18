#ifndef MBED_TERMISTOR_H
#define MBED_TERMISTOR_H

#include "mbed.h"

class Termistor {
public:
    Termistor(PinName pin);
    float calculate_temp();

private:
    AnalogIn termo;
    float count;
};

#endif
