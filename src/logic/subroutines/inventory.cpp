#include <stdint.h>

#include "subroutines.h"
#include "device_state.h"
#include "cursor_bounds.h"
#include "invalid.h"

uint8_t items_held = 2;
uint8_t mons_held = 2;

subroutine_status_t ss_inventory_step_left() {
	if(uc_cursor_position > 0) {
		CURSOR_LEFT();
		return SS_CONTINUE;
	}

	return SS_HALT;
}

subroutine_status_t ss_inventory_step_center() {
	//aparrently just halt if selecting an item
	if(uc_cursor_position >= mons_held) {
		return SS_HALT;
	}

	return SS_CONTINUE;
}

subroutine_status_t ss_inventory_step_right() {
	if(uc_cursor_position < (items_held + mons_held) - 1) {
		CURSOR_RIGHT();
	}
	else {
		v_invalid();
	}

	return SS_CONTINUE;
}