#include "transitions.h"
#include "device_state.h"

void v_radar_to_home() {
  uc_cursor_position = 0;
  primary_state = HOME;
}