
#include "handlers.h"
#include "transitions.h"
#include "subroutines.h"
#include "invalid.h"

void v_handler_right_button() {
  switch(primary_state) {
    case HOME:
      v_home_to_menu(CURSOR_MENU_LOW);
      break;
    case MENU:
      if(uc_cursor_position < CURSOR_MENU_HIGH) {CURSOR_RIGHT();}
			else {v_menu_to_home();}
      break;
    case CARD:
      v_card_to_stats();
      break;
    case STATS:
      if(uc_cursor_position < CURSOR_STATS_HIGH) {CURSOR_RIGHT();}
			else {v_invalid();}
      break;
    case SETTINGS:
    	if(uc_cursor_position < CURSOR_SETTINGS_HIGH) {CURSOR_RIGHT();}
    	break;
		case SHADE:
			(void) ss_shade_step_right();
			break;
		case SOUND:
			(void) ss_sound_step_right();
			break;
		case INVENTORY:
			(void) ss_inventory_step_right();
			break;
    default:
      break;
  }
}