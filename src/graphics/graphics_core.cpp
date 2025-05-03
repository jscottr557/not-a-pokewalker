#include "graphics_core.h"
#include "string_tools.h"

KWH018ST01_4WSPI display;

wind_info_t state_window;
wind_info_t option_window;
wind_info_t cursor_window;

ILI9163C_color_18_t color_white;
ILI9163C_color_18_t color_black;


void graphics_init() {
	display.begin(DC_PIN, CS_PIN, PWM_PIN, SPI_PORT, SPI_SPEED);  
	display.clearDisplay();
	
	display.setWindowDefaults(&state_window);
	state_window.xMin = 0;
  state_window.yMin = 0;
  state_window.xMax = 127;
  state_window.yMax = 8;
  state_window.cursorX = 0;
  state_window.cursorY = 0;
  state_window.xReset = 1;
  state_window.yReset = 1;
	display.setWindowColorSequence(&state_window, (color_t) &color_white);

	display.setWindowDefaults(&option_window);
	option_window.xMin = 0;
  option_window.yMin = 9;
  option_window.xMax = 127;
  option_window.yMax = 17;
  option_window.cursorX = 0;
  option_window.cursorY = 0;
  option_window.xReset = 1;
  option_window.yReset = 1;
	display.setWindowColorSequence(&option_window, (color_t) &color_white);

	display.setWindowDefaults(&cursor_window);
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
	color_black = (display.rgbTo18b( 0, 0, 0 ));
}

void clear_window(wind_info_t *window_to_clear) {
	display.pCurrentWindow = window_to_clear;
	display.fillWindow((color_t) &color_black);
}