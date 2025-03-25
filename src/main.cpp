#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "driving_loop.h"



void setup() {
  xTaskCreate(v_driving_loop, "driving loop", 50, NULL, 1, NULL);
}

void loop() {
  
}
