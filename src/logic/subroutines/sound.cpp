#include <stdint.h>

#include "subroutines.h"
#include "device_state.h"
#include "invalid.h"
#include "cursor_bounds.h"


#define SOUND_HIGH 2 
#define SOUND_LOW 0

uint8_t sound_magnitude;

subroutine_status_t ss_sound_step_left() {
	if(uc_cursor_position > SOUND_LOW) {
		CURSOR_LEFT();
		sound_magnitude--;
	}
	else {
		sound_magnitude = SOUND_HIGH;
	}
	//TODO: notify sound at updated volume
	return SS_CONTINUE;
}

subroutine_status_t ss_sound_step_center() {
	//TODO: save to disk
	return SS_HALT;
}

subroutine_status_t ss_sound_step_right() {
	if(uc_cursor_position < SOUND_HIGH) {
		CURSOR_RIGHT();
		sound_magnitude++;
	}
	else {
		sound_magnitude = SOUND_LOW;
	}
	//TODO: notify sound at updated volume
	return SS_CONTINUE;
}
