#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include "machine_state.h"
#include "buttons.h"

static void print_state() {
  Serial.print("device state: ");
  Serial.println(device_state);
  Serial.print("cursor pos: ");
  Serial.println(c_cursor_pos);
}

void v_driving_loop(void * pvParameters) {

  for(;;) { //if the counts are odd
    if(uc_button_left_flag % 2) {
      v_handler_left_button(device_state);
      uc_button_left_flag = 0;
      print_state();
    }
    if(uc_button_center_flag % 2) {
      v_handler_center_button(device_state);
      uc_button_center_flag = 0;
      print_state();
    }
    if(uc_button_right_flag % 2) {
      v_handler_right_button(device_state);
      uc_button_right_flag = 0;
      print_state();
    }

    vTaskDelay(0); //yield if we need to
  }
}
