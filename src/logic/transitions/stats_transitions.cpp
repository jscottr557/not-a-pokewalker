#include "transitions.h"
#include "device_state.h"

void v_stats_to_home() {
  uc_cursor_position = 0;
  primary_state = HOME;
}

void v_stats_to_card() {
  uc_cursor_position = 3;
  primary_state = CARD;
}