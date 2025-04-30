#include "handlers.h"
#include "transitions.h"
#include "buttons.h"
#include "subroutines.h"

void v_handler_center_button() {
	switch(primary_state) {
		case HOME:
			v_home_to_menu(CURSOR_MENU_COMMS);
			break;
		case MENU:
			switch(uc_cursor_position) {
				case CURSOR_MENU_RADAR:
					ss_radar_init();
					v_menu_to_radar();
					break;
				case CURSOR_MENU_DOWSING:
					ss_dowsing_init();
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
			(void) ss_sound_step_center();
			v_sound_to_home();
			break;
		case SHADE:
			(void) ss_shade_step_center();
			v_shade_to_home();
			break;
		case INVENTORY:
			if(ss_inventory_step_center() == SS_HALT) { v_inventory_to_home(); }
			else { /*?????????????????*/ } 
			break;
		case DOWSING:
			if(ss_dowsing_step_center() == SS_HALT) { v_dowsing_to_home(); }
			break;
		case RADAR:
			if(ss_radar_step_center() == SS_HALT) { v_radar_to_home(); }
			break;
		case COMMS:
			v_comms_to_home(); //PLACEHOLDER, TODO
			break;
		default:
			TRANSITION_SIMPLE(0, ERR);
			break;
	}
}