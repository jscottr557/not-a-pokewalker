#include <stdint.h>

#include "buttons.h"

#ifndef SUBROUTINES_H
#define SUBROUTINES_H

#define SS_CONTINUE 1
#define SS_HALT 0
#define SS_ERR 2

typedef uint8_t subroutine_status_t;

extern uint8_t sound_magnitude;
extern uint8_t shade;

extern uint8_t items_held;
extern uint8_t mons_held;

subroutine_status_t ss_shade_step_left();
subroutine_status_t ss_shade_step_center();
subroutine_status_t ss_shade_step_right();

subroutine_status_t ss_sound_step_left();
subroutine_status_t ss_sound_step_center();
subroutine_status_t ss_sound_step_right();

subroutine_status_t ss_inventory_step_left();
subroutine_status_t ss_inventory_step_center();
subroutine_status_t ss_inventory_step_right();

subroutine_status_t ss_dowsing_init();
subroutine_status_t ss_dowsing_step_left();
subroutine_status_t ss_dowsing_step_right();
subroutine_status_t ss_dowsing_step_center();

subroutine_status_t ss_radar_init();
subroutine_status_t ss_radar_step_left();
subroutine_status_t ss_radar_step_right();
subroutine_status_t ss_radar_step_center();

subroutine_status_t ss_battle_init();
subroutine_status_t ss_battle_step_left();
subroutine_status_t ss_battle_step_right();
subroutine_status_t ss_battle_step_center();

subroutine_status_t ss_comms();


#endif