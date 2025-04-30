#include "transitions.h"
#include "device_state.h"
#include "graphics_core.h"
#include "cursor_bounds.h"

void v_menu_to_home() {
  uc_cursor_position = CURSOR_NO_SEL;
  primary_state = HOME;
	draw_state(state_to_string(primary_state));
	draw_options(0);

}

void v_menu_to_radar() {
  uc_cursor_position = CURSOR_RADAR_LOW;
  primary_state = RADAR;
	draw_state(state_to_string(primary_state));

	draw_options(CURSOR_RADAR_HIGH + 1);
}

void v_menu_to_dowsing() {
  uc_cursor_position = CURSOR_DOWSING_LOW;
  primary_state = DOWSING;
	draw_state(state_to_string(primary_state));

	draw_options(CURSOR_DOWSING_HIGH + 1);
}

void v_menu_to_comms() {
  uc_cursor_position = CURSOR_NO_SEL;
  primary_state = COMMS;
	draw_state(state_to_string(primary_state));
	draw_options(0);

}

void v_menu_to_card() {
	uc_cursor_position = CURSOR_NO_SEL;
  primary_state = CARD;
	draw_state(state_to_string(primary_state));
	draw_options(0);

}

void v_menu_to_inventory() {
  uc_cursor_position = 0; //TODO: implement function to determine lower bound of inventory 
  primary_state = INVENTORY;
	draw_state(state_to_string(primary_state));

	draw_options(6); //TODO: use a function to calculate the number of options dynamically

}

void v_menu_to_settings() {
  uc_cursor_position = CURSOR_SETTINGS_LOW;
  primary_state = SETTINGS;
	draw_state(state_to_string(primary_state));

	draw_options(CURSOR_SETTINGS_HIGH + 1);
}