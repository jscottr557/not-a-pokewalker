#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include "device_state.h"
#include "buttons.h"
#include "handlers.h"

static void print_state() {
  Serial.print("device state: ");
  Serial.println(state_to_string(primary_state));
  Serial.print("cursor pos: ");
  Serial.println(uc_cursor_position);
}

void v_driving_loop(void * pvParameters) {
  for(;;) {
    if(uc_button_left_flag > 0) {
      v_handler_left_button();
      uc_button_left_flag--;
      print_state();
    }
    if(uc_button_center_flag > 0) {
      v_handler_center_button();
      uc_button_center_flag--;
      print_state();
    }
    if(uc_button_right_flag > 0) {
      v_handler_right_button();
      uc_button_right_flag--;
      print_state();
    }

    vTaskDelay(0); //yield to let other things (animation and sound) run
  }
}
