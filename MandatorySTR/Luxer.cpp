#include "mbed.h"
#include "Luxer.h"

Luxer::Luxer(PinName pin) : light(pin) { 
}

float Luxer::calculate_lux(){
  float count = light.read();
  float lux = (((3.3 * 500) * (count * 3.3)) - 500) / (10);
  if (lux < 0) {
    return 0;
    }
    return lux;
}