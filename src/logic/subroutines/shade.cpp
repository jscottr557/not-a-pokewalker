#include <stdint.h>

#include "subroutines.h"
#include "device_state.h"
#include "invalid.h"
#include "cursor_bounds.h"

#define SHADE_HIGH 9 
#define SHADE_LOW 0

uint8_t shade;

subroutine_status_t ss_shade_step_left() {
	if(uc_cursor_position > SHADE_LOW) {
		CURSOR_LEFT();
		shade--;
		//TODO: redraw screen at updated shade
	}
	else {
		v_invalid();
	}
	return SS_CONTINUE;
}

subroutine_status_t ss_shade_step_center() {
	//TODO: save to disk
	return SS_HALT;
}

subroutine_status_t ss_shade_step_right() {
	if(uc_cursor_position < SHADE_HIGH) {
		CURSOR_RIGHT();
		shade++;
		//TODO: redraw screen at updated shade
	}
	else {
		v_invalid();
	}
	return SS_CONTINUE;
}
