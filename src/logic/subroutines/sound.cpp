#include <stdint.h>

#include "subroutines.h"
#include "device_state.h"
#include "buttons.h"
#include "invalid.h"
#include "cursor_bounds.h"


#define SOUND_HIGH 10 //don't remember, cant be bothered to grab the source. just a guess rn
#define SOUND_LOW 0

uint8_t sound_magnitude;

subroutine_status_t ss_sound_step(button_t button_number) {
	switch(button_number) {
		case BUTTON_LEFT:
			if(uc_cursor_position > SOUND_LOW) {
				CURSOR_LEFT();
				sound_magnitude--;
				//TODO: notify sound at updated volume
			}
			else {
				v_invalid();
			}
			return SS_CONTINUE;
		case BUTTON_CENTER:
			//TODO: save to disk
			return SS_HALT;
		case BUTTON_RIGHT:
			if(uc_cursor_position < SOUND_HIGH) {
				CURSOR_RIGHT();
				sound_magnitude++;
				//TODO: notify sound at updated volume
			}
			else {
				v_invalid();
			}
			return SS_CONTINUE;
	}
	return SS_ERR;
}
