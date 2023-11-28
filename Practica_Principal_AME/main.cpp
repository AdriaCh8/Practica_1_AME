#include "mbed.h"
#include "ThisThread.h"
#include "Termistor.h"
#include "Rotator.h"
#include "Grove_LCD_RGB_Backlight.h"

// Inicializa el potenciómetro en el pin A0
Rotator potenciometro(A1);
Termistor temp(A0);
Grove_LCD_RGB_Backlight lcd(D14,D15);
DigitalOut led(LED1);
DigitalOut led_fred(LED2);
DigitalOut led_calor(LED3);

void blink(int v){
    bool token = false;
    if(v==1){
        token = true;
        while(token){
           led_fred=!led_fred; 
           ThisThread::sleep_for(300ms);
        }
    }
    if(v==2){
        token = true;
        while(token){
        led_calor=!led_calor; 
        ThisThread::sleep_for(300ms);
        }
    }else{
        while(true){
           led=!led; 
           ThisThread::sleep_for(300ms);
        }
    }
            
}
    
// main() runs in its own thread in the OS
int main()
{
        //Abrimos un led conforme esta en marcha y mostramos un mensaje
        blink(0);
        char inicio[] = "Inicializando...";
        lcd.print(inicio);
        float temperatura = temp.calculate_temp();
        int temperatura_deseada;
        char str[] = "Temperatura: ";
        char str2[] = "T.deseada: ";
        ThisThread::sleep_for(4s);
        //cuando todo esta listo borramos lo que havia y mostramos lo que toca
        lcd.clear();
    while (true) {
        lcd.print(str);
        ThisThread::sleep_for(300ms);
        lcd.write(temperatura);
        ThisThread::sleep_for(500ms);
        lcd.clear();
        lcd.print(str2);
        ThisThread::sleep_for(300ms);
        lcd.write(temperatura_deseada);
        ThisThread::sleep_for(500ms);
     

        temperatura_deseada = potenciometro.calculate_value();

        // Imprime el valor del potenciómetro
        printf("Valor del potenciómetro: %d\n", temperatura_deseada);
        // Si el valor de temperatura deseada esta bor debajo de la que tenemos encendemos el led azul y empezamos a bajar la temperatura
        // Si esta por encima subimos la temperatura y encendemos el led rojo.
        if(temperatura_deseada<temperatura){
            blink(1);
            temperatura--;
        }else{
            blink(2);
            temperatura++;
        }
        ThisThread::sleep_for(1s);
        lcd.clear();

    }

}




