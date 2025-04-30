#include "transitions.h"
#include "device_state.h"
#include "graphics_core.h"
#include "cursor_bounds.h"


void v_inventory_to_home() {
  uc_cursor_position = CURSOR_NO_SEL;
  primary_state = HOME;
	draw_state(state_to_string(primary_state));
	draw_options(0);
}

void v_inventory_to_menu() {
	uc_cursor_position = CURSOR_MENU_INVENTORY;
  primary_state = MENU;
	draw_state(state_to_string(primary_state));
	draw_options(CURSOR_MENU_HIGH + 1);
}