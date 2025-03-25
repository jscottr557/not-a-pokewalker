#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include "driving_loop.h"
#include "buttons.h"



void setup() {
  Serial.begin(9600);
  while(!Serial){}

  v_enable_buttons();
  xTaskCreate(v_driving_loop, "driving loop", 256, NULL, 1, NULL);

  Serial.println("inited!");
}

//scheduler should start automatically

void loop() {
  
}
