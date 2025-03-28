#include "transitions.h"
#include "device_state.h"

void v_home_to_menu(uint8_t uc_cursor_start){
  uc_cursor_position = uc_cursor_start;
  primary_state = MENU;
}

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

void v_card_to_home() {
  uc_cursor_position = 0;
  primary_state = HOME;
}

void v_card_to_menu() {
  //uc_cursor_position = 3;
  primary_state = MENU;
}

void v_card_to_stats() {
  uc_cursor_position = 0;
  primary_state = STATS;
}

void v_stats_to_home() {
  uc_cursor_position = 0;
  primary_state = HOME;
}

void v_stats_to_card() {
  uc_cursor_position = 3;
  primary_state = CARD;
}





