#include "transitions.h"
#include "device_state.h"

void v_settings_to_sound() {
  uc_cursor_position = 0;
  primary_state = SOUND;
}

void v_settings_to_shade() {
  uc_cursor_position = 0;
  primary_state = SHADE;
}

void v_settings_to_menu() {
  uc_cursor_position = 5;
  primary_state = MENU;
}