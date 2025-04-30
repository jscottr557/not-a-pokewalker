#include "transitions.h"
#include "device_state.h"
#include "graphics_core.h"
#include "cursor_bounds.h"

void v_shade_to_home() {
  TRANSITION_SIMPLE(CURSOR_NO_SEL, HOME);
	draw_state(state_to_string(primary_state));
	draw_options(0);

}