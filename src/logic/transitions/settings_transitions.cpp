#include "transitions.h"
#include "device_state.h"
#include "graphics_core.h"
#include "cursor_bounds.h"

void v_settings_to_sound() {
  uc_cursor_position = CURSOR_SOUND_LOW;
  primary_state = SOUND;
	draw_state(state_to_string(primary_state));

	draw_options(CURSOR_SOUND_HIGH + 1);
}

void v_settings_to_shade() {
  uc_cursor_position = CURSOR_SHADE_LOW;
  primary_state = SHADE;
	draw_state(state_to_string(primary_state));

	draw_options(CURSOR_SHADE_HIGH + 1);
}

void v_settings_to_menu() {
  uc_cursor_position = CURSOR_MENU_SETTINGS;
  primary_state = MENU;

	draw_state(state_to_string(primary_state));

	draw_options(CURSOR_MENU_HIGH + 1);
}