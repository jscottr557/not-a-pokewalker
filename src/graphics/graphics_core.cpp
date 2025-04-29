#include "graphics_core.h"
#include "string_tools.h"

static KWH018ST01_4WSPI display;

static uint8_t num_options_on_screen;

static wind_info_t state_window;

void graphics_init() {
	display.begin(DC_PIN, CS_PIN, PWM_PIN, SPI_PORT, SPI_SPEED);  
	display.clearDisplay();
	display.setWindowDefaults(&state_window);

	state_window.xMin = 0;
  state_window.yMin = 0;
  state_window.xMax = 127;
  state_window.yMax = 8;
  state_window.cursorX = 1;
  state_window.cursorY = 1;
  state_window.xReset = 1;
  state_window.yReset = 1;
  state_window.currentSequenceData = (color_t)&color1;
  state_window.currentColorCycleLength = 1;
  state_window.currentColorOffset = 0;
}


void draw_state(const char *s_state_name) {
	char *s_state_string = make_filled_string(' ', CHAR_LINE_WIDTH + 1);
	center_string(state_name, state_string, CHAR_LINE_WIDTH + 1);
	display.pCurrentWindow = &state_window;
	display.setTextCursor(0, 0, )
	display.print(state_string);

}

void draw_options(uint8_t num_options) {

}

void draw_cursor(uint8_t cursor_position) {

}