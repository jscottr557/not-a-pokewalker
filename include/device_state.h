#include <stdint.h>

#include <Arduino_FreeRTOS.h>

#ifndef DEVICE_STATE_H
#define DEVICE_STATE_H

#define NUM_MACHINE_STATES 15
#define NUM_INTERRUPTS

extern TaskHandle_t x_driving_loop_handle;

typedef enum primary_states {
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
  PAUSE,
  ERR
} states_t;

extern states_t primary_state;

const char * state_to_string(states_t state);

extern uint8_t uc_cursor_position;

extern uint32_t today_steps;
extern uint32_t history_steps[7];
extern uint32_t all_time_steps;
extern uint32_t total_days;
extern uint32_t watts;

#endif