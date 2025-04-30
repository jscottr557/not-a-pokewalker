#include <Arduino.h>

#include "graphics_core.h"
#include "string_tools.h"
#include "cursor_bounds.h" 
static KWH018ST01_4WSPI display;

static uint8_t option_indexes[NUM_CHARS_PER_LINE];

static wind_info_t state_window;
static wind_info_t option_window;
static wind_info_t cursor_window;

static ILI9163C_color_18_t color_white;
static ILI9163C_color_18_t color_black;


void graphics_init() {
	display.begin(DC_PIN, CS_PIN, PWM_PIN, SPI_PORT, SPI_SPEED);  
	display.clearDisplay();
	
	display.setWindowDefaults(&state_window);
	display.setWindowDefaults(&option_window);
	display.setWindowDefaults(&cursor_window);

	state_window.xMin = 0;
  state_window.yMin = 0;
  state_window.xMax = 127;
  state_window.yMax = 8;
  state_window.cursorX = 0;
  state_window.cursorY = 0;
  state_window.xReset = 1;
  state_window.yReset = 1;
	display.setWindowColorSequence(&state_window, (color_t) &color_white);


	option_window.xMin = 0;
  option_window.yMin = 9;
  option_window.xMax = 127;
  option_window.yMax = 17;
  option_window.cursorX = 0;
  option_window.cursorY = 0;
  option_window.xReset = 1;
  option_window.yReset = 1;
	display.setWindowColorSequence(&option_window, (color_t) &color_white);


	cursor_window.xMin = 0;
  cursor_window.yMin = 18;
  cursor_window.xMax = 127;
  cursor_window.yMax = 26;
  cursor_window.cursorX = 0;
  cursor_window.cursorY = 0;
  cursor_window.xReset = 1;
  cursor_window.yReset = 1;
	display.setWindowColorSequence(&cursor_window, (color_t) &color_white);


	color_white = (display.rgbTo18b( 255, 255, 255 ));
	color_black = (display.rgbTo18b( 0, 0, 0));


}


void draw_state(const char *state_name) {
	
		//TODO: parameter validation

	char *state_string = make_filled_string(' ', NUM_CHARS_PER_LINE + 1);
	//TODO: check return from make_filled_string is valid

	center_string(state_name, state_string, NUM_CHARS_PER_LINE + 1);

	display.pCurrentWindow = &state_window;

	display.fillWindow((color_t) &color_black);
	display.resetTextCursor(&state_window);
	display.println(state_string);

	free(state_string);
}


void draw_options(uint8_t num_options) {
	if(num_options < 0) return;

	display.pCurrentWindow = &option_window;
	display.fillWindow((color_t) &color_black);

	if(num_options == 0) return;

	uint8_t spacing = (NUM_CHARS_PER_LINE - num_options) / (num_options + 1);
	spacing++; //number of characters to jump forward

	char *option_string = make_filled_string(' ', NUM_CHARS_PER_LINE + 1);
	//TODO: check return from make_filled_string is valid

	int next_option_index = spacing - 1; //0 align
	for(int i = 0; i < num_options; i++) {
		option_string[next_option_index] = '|';
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
	

	display.pCurrentWindow = &cursor_window;
	display.fillWindow((color_t) &color_black);

	if(cursor_position == CURSOR_NO_SEL) return;

	display.setTextCursor(option_indexes[cursor_position] * 6, 0, &cursor_window);
	display.print("*");
}