#include "transitions.h"
#include "device_state.h"
#include "graphics_core.h"

void v_home_to_menu(uint8_t uc_cursor_start){
  TRANSITION_SIMPLE(uc_cursor_start, MENU);
	draw_state(state_to_string(primary_state));
	draw_options(CURSOR_MENU_HIGH + 1);
}
