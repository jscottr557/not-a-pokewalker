#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include "driving_loop.h"
#include "buttons.h"


void setup() {
  Serial.begin(9600);
  while(!Serial){}

  xTaskCreate(v_driving_loop, "driving loop", 256, NULL, 1, &x_driving_loop_handle);
	v_enable_buttons(); //if this were first bad memory access could result, see ISRs


  Serial.println("inited!");
}


void loop() {
  //scheduler starts automatically
}
