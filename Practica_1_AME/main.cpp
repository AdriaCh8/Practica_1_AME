#include "mbed.h"
#include "ThisThread.h"
#include "Termistor.h"

Termistor temp(A0);

// main() runs in its own thread in the OS
int main()
{
    while (true) {
        float temperature = temp.calculate_temp();
        printf("==================================\n");
        printf("|       Sensor de Termistor       |\n");
        printf("|--------------------------------|\n");
        printf("| Temperatura: %.2f °C           |\n", temperature);
        printf("==================================\n");
        ThisThread::sleep_for(3s);
    }

}




