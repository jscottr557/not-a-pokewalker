#include "transitions.h"
#include "device_state.h"

void v_inventory_to_home() {
  uc_cursor_position = 0;
  primary_state = HOME;
}

void v_inventory_to_menu() {
	uc_cursor_position = CURSOR_MENU_INVENTORY;
  primary_state = MENU;
}