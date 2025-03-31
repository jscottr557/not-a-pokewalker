#include "transitions.h"
#include "device_state.h"

void v_home_to_menu(uint8_t uc_cursor_start){
  TRANSITION_SIMPLE(uc_cursor_start, MENU);
}
