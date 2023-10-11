#include "mbed.h"
#include "ThisThread.h"
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <stdint.h>


AnalogIn termo(A0);


// main() runs in its own thread in the OS
int main()
{
    while (true) {
        float count;
        count = termo.read();
        float resistance;
        resistance = (100000 * ((65535/count)-1));
        printf("Hola");
        ThisThread::sleep_for(3s);
    }
}



