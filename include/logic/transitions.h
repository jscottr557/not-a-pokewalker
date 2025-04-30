#include <stdint.h>

#include "device_state.h"
#include "cursor_bounds.h"

#ifndef TRANSITIONS_H
#define TRANSITIONS_h

#define TRANSITION_SIMPLE(cursor_start, state) { \
																								uc_cursor_position = cursor_start;\
																								primary_state = state;\
																							 }

void v_simple_transition(uint8_t uc_cursor_start, states_t state); //deprecated over the macro, wastes a stack frame

void v_home_to_menu(uint8_t uc_cursor_start);

void v_menu_to_home();
void v_menu_to_radar();
void v_menu_to_dowsing();
void v_menu_to_comms();
void v_menu_to_card();
void v_menu_to_inventory();
void v_menu_to_settings();

void v_card_to_home();
void v_card_to_menu();
void v_card_to_stats();

void v_stats_to_home();
void v_stats_to_card();

void v_settings_to_sound();
void v_settings_to_shade();
void v_settings_to_menu();

void v_sound_to_home();
void v_shade_to_home();

void v_inventory_to_home();
void v_inventory_to_menu();

void v_dowsing_to_home();

void v_radar_to_home();

void v_comms_to_home();


#endif
