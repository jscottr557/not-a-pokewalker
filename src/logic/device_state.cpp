#include "device_state.h"

states_t primary_state = HOME;

uint8_t uc_cursor_position;

//if stats was a subroutine, these would live there. It isn't, so they don't
uint32_t today_steps;
uint32_t history_steps[7];
uint32_t all_time_steps;
uint32_t total_days;
uint32_t watts;

static const char *name_list[NUM_MACHINE_STATES] = {"home",
  																									"menu",
  																									"radar",
  																									"dowsing",
  																									"comms",
  																									"card",
  																									"inventory",
  																									"settings",
  																									"sound",
  																									"shade",
  																									"stats",
  																									"battle",
  																									"switch",
  																									"pause",
  																									"err"};


const char *state_to_string(states_t state) {
  return name_list[state];
}


