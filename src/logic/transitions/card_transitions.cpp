#include "transitions.h"
#include "device_state.h"

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