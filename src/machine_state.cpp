#include "machine_state.h"
#include "buttons.h"

int8_t c_cursor_pos;

states_t device_state = HOME;

void v_handler_left_button(states_t state) {
  switch(state) {
    case HOME:
      c_cursor_pos = 5;
      device_state = MENU;
      break;
    case MENU:
      if(c_cursor_pos == 0) {device_state = HOME; break;}
      c_cursor_pos--;
      break;
    default:
      break;
  }
  uc_button_left_flag = 0;
}

void v_handler_center_button(states_t state) {
  switch(state) {
    case HOME:
      c_cursor_pos = 2;
      device_state = MENU;
      break;
    case MENU:
      
      break;
    default:
      break;
  }
  
}

void v_handler_right_button(states_t state) {
  switch(state) {
    case HOME:
      c_cursor_pos = 0;
      device_state = MENU;
      break;
    case MENU:
      if(c_cursor_pos == 5) {device_state = HOME; break;}
      c_cursor_pos++;
      break;
    default:
      break;
  }
  uc_button_right_flag = 0;
}