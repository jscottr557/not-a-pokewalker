#include "transitions.h"
#include "graphics_core.h" 
#include "device_state.h"

void v_comms_to_home() {
	uc_cursor_position = CURSOR_NO_SEL;
  primary_state = HOME;
	draw_state(state_to_string(primary_state));
	draw_options(0);
}
