#include "mbed.h"
#include "Luxer.h"
#include <stack>

InterruptIn button(D2);
Luxer lux(A0);

stack<float> buffer;

bool aux = false;

float interrupt(){
    Timer timer0;
    timer0.reset();
    timer0.start();
    while(timer0<10){
        buffer.push(lux.calculate_lux());
        ThisThread::sleep_for(500ms);
    }
    timer0.stop();
    int size = buffer.size();
    float mitja = 0;
    while(buffer.size()!=0){
        mitja = mitja + buffer.top();
        buffer.pop();
    }
    
    aux = !aux;
    return mitja/size;
}

// main() runs in its own thread in the OS
int main()
{
    button.rise(interrupt);
    while (true) {
        printf("\n%d",aux);
        ThisThread::sleep_for(500ms);
    }
}

