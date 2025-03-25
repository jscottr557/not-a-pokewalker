#include <stdint.h>

#ifndef STATE_H
#define STATE_H

#define NUM_MACHINE_STATES
#define NUM_INTERRUPTS

extern int8_t c_cursor_pos;

typedef enum states {
  HOME,
  MENU,
  RADAR,
  DOWSING,
  COMMS,
  CARD,
  INVENTORY,
  SETTINGS,
  SOUND,
  SHADE,
  STATS,
  BATTLE,
  SWITCH,
  PAUSE
} states_t;

extern states_t device_state;

void v_handler_left_button(states_t state);
void v_handler_center_button(states_t state);
void v_handler_right_button(states_t state);


#endif