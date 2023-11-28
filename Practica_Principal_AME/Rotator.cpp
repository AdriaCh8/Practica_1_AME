#include "Rotator.h"
#include "mbed.h"


Rotator::Rotator(PinName pin) : potenciometro(pin) {
        r = 0;
}

unsigned int Rotator::calculate_value() {
    unsigned int r = potenciometro.read_u16();

    if (r > 65536) {
        r = 65536;
    }

    unsigned int franja_size = 65536/30;
    unsigned int franja = r / franja_size + 10;

    return franja;
}