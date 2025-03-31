#include "transitions.h"
#include "device_state.h"

void v_menu_to_home() {
  uc_cursor_position = 0;
  primary_state = HOME;
}

void v_menu_to_radar() {
  uc_cursor_position = 0;
  primary_state = RADAR;
}

void v_menu_to_dowsing() {
  uc_cursor_position = 0;
  primary_state = DOWSING;
}

void v_menu_to_comms() {
  uc_cursor_position = 0;
  primary_state = COMMS;
}

void v_menu_to_card() {
  //uc_cursor_position = 0;
  primary_state = CARD;
}

void v_menu_to_inventory() {
  uc_cursor_position = 0;
  primary_state = INVENTORY;
}

void v_menu_to_settings() {
  uc_cursor_position = 0;
  primary_state = SETTINGS;
}