#include "mbed.h"
#include "ThisThread.h"
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <stdint.h>


AnalogIn termo(A0);

float calculate_rtherm(int counts) {
    float result = 100000 * ((65535.0 / counts) - 1);
    return result;
}

float calculate_temp(float rtherm) {
    float result = 1 / (log(rtherm / 100000) / 4250 + 1 / (25 + 273.15)) - 273.15;
    return result;
}

// main() runs in its own thread in the OS
int main()
{
    while (true) {
        float count;
        count = termo.read_u16();
        float resistance = calculate_rtherm(count);
        float temp = calculate_temp(resistance);
        printf("==================================\n");
        printf("|       Sensor de Termistor       |\n");
        printf("|--------------------------------|\n");
        printf("| Resistencia: %.2f Ohm          |\n", resistance);
        printf("| Temperatura: %.2f °C           |\n", calculate_temp(resistance));
        printf("==================================\n");
        ThisThread::sleep_for(3s);
    }

}




