#include "Termistor.h"
#include "mbed.h"
#include <cmath> 

Termistor::Termistor(PinName pin) : termo(pin) {
        count = 0;
}

float Termistor::calculate_temp() {
    count = termo.read_u16();
    float rtherm = 100000 * ((65535.0 / count) - 1);
    float result = 1 / (log(rtherm / 100000) / 4250 + 1 / (25 + 273.15)) - 273.15;
    return result;
}