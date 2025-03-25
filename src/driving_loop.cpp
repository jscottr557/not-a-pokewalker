#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include "machine_state.h"
#include "buttons.h"

void v_driving_loop(void * pvParameters) {

  for(;;) { //if the counts are odd
    if(uc_button_left_flag % 2) {
      v_handler_left_button(device_state);
    }
    if(uc_button_center_flag % 2) {
      v_handler_right_button(device_state);
    }
    if(uc_button_right_flag % 2) {
      v_handler_right_button(device_state);
    }
  }
}
