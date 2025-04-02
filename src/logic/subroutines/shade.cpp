#include <stdint.h>

#include "subroutines.h"
#include "device_state.h"
#include "buttons.h"
#include "invalid.h"
#include "cursor_bounds.h"

#define SHADE_HIGH 10 //don't remember, cant be bothered to grab the source. just a guess rn
#define SHADE_LOW 0

uint8_t shade;

subroutine_status_t ss_shade_step(button_t button_number) {
	switch(button_number) {
		case BUTTON_LEFT:
			if(uc_cursor_position > SHADE_LOW) {
				CURSOR_LEFT();
				shade--;
				//TODO: redraw screen with updated shade
			}
			else {
				v_invalid();
			}
			return SS_CONTINUE;
		case BUTTON_CENTER:
			//TODO: save to disk
			return SS_HALT;
		case BUTTON_RIGHT:
			if(uc_cursor_position < SHADE_HIGH) {
				CURSOR_RIGHT();
				shade++;
				//TODO: redraw screen with updated shade
			}
			else {
				v_invalid();
			}
			return SS_CONTINUE;
	}
	return SS_ERR;
}
