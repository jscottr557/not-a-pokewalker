#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <stdlib.h>
#include <time.h>

#include "device_state.h"
#include "buttons.h"
#include "handlers.h"


static void print_state() {
  Serial.print("device state: ");
  Serial.println(state_to_string(primary_state));
  Serial.print("cursor pos: ");
  Serial.println(uc_cursor_position);
}

TaskHandle_t x_driving_loop_handle;

void v_driving_loop(void *pvParameters) {
	srand(time(NULL)); //random number seeding for this task
	
	xTaskNotifyStateClear(NULL); //clear any notifications just in case
	ulTaskNotifyValueClear(NULL, UINT32_MAX);

  for(;;) {

		//wait for an input
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

		switch (uc_which_button) {
			case L_BUTTON:
				v_handler_left_button();
				break;
			case C_BUTTON:
				v_handler_center_button();
				break;
			case R_BUTTON:
				v_handler_right_button();
				break;
			default:
				//????
				break;
		}		
		uc_which_button = NONE_BUTTON;
  }
}
