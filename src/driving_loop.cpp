#include <Arduino_FreeRTOS.h>
#include <stdlib.h>
#include <time.h>

#include "device_state.h"
#include "buttons.h"
#include "handlers.h"
#include "graphics_core.h"
#include "cursor_bounds.h"

TaskHandle_t x_driving_loop_handle;

void v_driving_loop(void *pvParameters) {
	srand(time(NULL)); //random number seeding for this task
	
	xTaskNotifyStateClear(NULL); //clear any notifications just in case
	ulTaskNotifyValueClear(NULL, UINT32_MAX);

	draw_state(state_to_string(primary_state));

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

		if(uc_cursor_position == CURSOR_NO_SEL) {
			clear_cursor_window();
		}
		else {
			draw_cursor(uc_cursor_position);
		}
  }

	
	
	
}
