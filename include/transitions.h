#include <stdint.h>

#ifndef TRANSITIONS_H
#define TRANSITIONS_h

void v_home_to_menu(uint8_t uc_cursor_position);

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
#endif
