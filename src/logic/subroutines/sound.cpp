#include <stdint.h>

#include "subroutines.h"
#include "device_state.h"
#include "invalid.h"
#include "cursor_bounds.h"


uint8_t sound_magnitude;

subroutine_status_t ss_sound_step_left() {
	if(uc_cursor_position > CURSOR_SOUND_LOW) {
		CURSOR_LEFT();
		sound_magnitude--;
	}
	else {
		sound_magnitude = CURSOR_SOUND_HIGH;
	}
	//TODO: notify sound at updated volume
	return SS_CONTINUE;
}

subroutine_status_t ss_sound_step_center() {
	//TODO: save to disk
	return SS_HALT;
}

subroutine_status_t ss_sound_step_right() {
	if(uc_cursor_position < CURSOR_SOUND_HIGH) {
		CURSOR_RIGHT();
		sound_magnitude++;
	}
	else {
		sound_magnitude = CURSOR_SOUND_LOW;
	}
	//TODO: notify sound at updated volume
	return SS_CONTINUE;
}
