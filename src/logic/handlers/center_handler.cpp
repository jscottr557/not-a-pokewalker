#include "handlers.h"
#include "transitions.h"

void v_handler_center_button(states_t state) {
	switch(state) {
		case HOME:
			v_home_to_menu(CURSOR_MENU_COMMS);
			break;
		case MENU:
			switch(uc_cursor_position) {
				case CURSOR_MENU_RADAR:
					v_menu_to_radar();
					break;
				case CURSOR_MENU_DOWSING:
					v_menu_to_dowsing();
					break;
				case CURSOR_MENU_COMMS:
					v_menu_to_comms();
					break;
				case CURSOR_MENU_CARD:
					v_menu_to_card();
					break;
				case CURSOR_MENU_INVENTORY:
					v_menu_to_inventory();
					break;
				case CURSOR_MENU_SETTINGS:
					v_menu_to_settings();
					break;
				default:
					break;
			}
			break;
		case CARD:
			v_card_to_home();
			break;
		case STATS:
			v_stats_to_home();
			break;
		case SETTINGS:
			switch(uc_cursor_position) {
				case CURSOR_SETTINGS_LOW:
					v_settings_to_sound();
					break;
				case CURSOR_SETTINGS_HIGH:
					v_settings_to_shade();
					break;
			}
			break;
		case SOUND:
			//save new sound setting
			v_sound_to_home();
			break;
		case SHADE:
			//save new shade setting
			v_shade_to_home();
			break;
		case INVENTORY:
			v_inventory_to_home();
			break;
		default:
			//its so over
			break;
	}
}