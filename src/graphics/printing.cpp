#include "graphics_core.h"

static uint8_t option_indexes[NUM_CHARS_PER_LINE];

void draw_state(const char *state_name) {
	if(state_name == NULL) return;

	char *state_string = make_filled_string(' ', NUM_CHARS_PER_LINE + 1);
	if(state_string == NULL) return;

	center_string(state_name, state_string, NUM_CHARS_PER_LINE + 1);

	clear_window(&state_window);
	display.resetTextCursor(&state_window);
	display.println(state_string);

	free(state_string);
}


void draw_options(uint8_t num_options) {
	clear_window(&option_window); //unfortunate side effect, this also changes the active window

	if(num_options == 0) return;

	uint8_t spacing = (NUM_CHARS_PER_LINE - num_options) / (num_options + 1);
	spacing++; //number of characters to jump forward

	char *option_string = make_filled_string(' ', NUM_CHARS_PER_LINE + 1);
	if(option_string == NULL) return;

	int next_option_index = spacing - 1; //0 align
	for(int i = 0; i < num_options; i++) {
		option_string[next_option_index] = '#';
		option_indexes[i] = next_option_index; //save these for use when drawing the cursor so we don't have to re-calculate
		next_option_index += spacing;
	}

	display.pCurrentWindow = &option_window;
	display.fillWindow((color_t) &color_black);
	display.resetTextCursor(&option_window);
	display.print(option_string);

	free(option_string);
}


void draw_cursor(uint8_t cursor_position) {	
	clear_window(&cursor_window);  

	display.setTextCursor(option_indexes[cursor_position] * 6, 0, &cursor_window); //6 is the width of a character
	display.print("*");
}