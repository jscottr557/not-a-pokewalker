#include <stdlib.h>
#include <Arduino.h>

#include "subroutines.h"
#include "cursor_bounds.h"
#include "device_state.h"
#include "prompt_block.h"

#define STARTING_GUESSES 2

static uint8_t uc_guesses_count = 0;
static uint8_t uc_item_index = 0;

subroutine_status_t ss_dowsing_step_left() {
	if(uc_cursor_position > CURSOR_DOWSING_LOW) {
		CURSOR_LEFT();
	}
	else {
		uc_cursor_position = CURSOR_DOWSING_HIGH;
	}
	return SS_CONTINUE;
}

subroutine_status_t ss_dowsing_step_right() {
	if(uc_cursor_position < CURSOR_DOWSING_HIGH) {
		CURSOR_RIGHT();
	}
	else {
		uc_cursor_position = CURSOR_DOWSING_LOW;
	}
	return SS_CONTINUE;
}

subroutine_status_t ss_dowsing_step_center() {
	uc_guesses_count++;

	//TODO: search animation

	if(uc_cursor_position == uc_item_index) { //found it
		//TODO: happy ding
		//TODO: draw item
		v_block_with_prompt("found!");
		//TODO: add the item to inventory, may need to invoke a SWITCH here... doesn't really fit the invariates, may be an informal state
		
		uc_guesses_count = 0;
		return SS_HALT;
	}
	
	if(uc_guesses_count == STARTING_GUESSES) { //out of guesses
		//TODO: sad ding
		//TODO: draw item
		Serial.println(uc_item_index); //FOR DEBUGGING ONLY, REMOVE WHEN DONE
		v_block_with_prompt("out of guesses :(");
		uc_guesses_count = 0;

		return SS_HALT;
	}

	uint8_t uc_distance_to_item = uc_item_index - uc_cursor_position;
	if(uc_distance_to_item < 0) uc_distance_to_item *= -1;

	//TODO: sad ding
	v_block_with_prompt("miss!");

	if(uc_distance_to_item == 1) {
		v_block_with_prompt("It's near!");
	}
	else {
		v_block_with_prompt("It's far away...");
	}

	return SS_CONTINUE;
}

subroutine_status_t ss_dowsing_init() {
	uc_item_index = rand() % (CURSOR_DOWSING_HIGH + 1); //between CURSOR_DOWSING_LOW & CURSOR_DOWSING_HIGH... (not uniformly distributed)
	return SS_CONTINUE;
}