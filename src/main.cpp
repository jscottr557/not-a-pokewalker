#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include "driving_loop.h"
#include "buttons.h"
#include "graphics_core.h"


void setup() {
  Serial.begin(9600);
  while(!Serial){} //Wait for the usb serial

  xTaskCreate(v_driving_loop, "driving loop", 1024, NULL, 1, &x_driving_loop_handle);
	v_enable_buttons();

	graphics_init();

  Serial.println("inited!");
}


void loop() {
  //scheduler starts automatically
}
