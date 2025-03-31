#include "handlers.h"
#include "transitions.h"

void v_handler_left_button(states_t state) {
  switch(state) {
    case HOME:
      v_home_to_menu(CURSOR_MENU_HIGH);
      break;
    case MENU:
      if(uc_cursor_position > CURSOR_MENU_LOW) {CURSOR_LEFT();}
      else {v_menu_to_home();}
      break;
    case CARD:
      v_card_to_menu();
      break;
    case STATS:
      if(uc_cursor_position > CURSOR_STATS_LOW) {CURSOR_LEFT();}
      else {v_stats_to_card();}
			break;
    case SETTINGS:
      if(uc_cursor_position > CURSOR_SETTINGS_LOW) {CURSOR_LEFT();}
      else{v_settings_to_menu();}
      break;
    default:
      break;
  }
}