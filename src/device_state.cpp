#include "device_state.h"
#include "buttons.h"

states_t primary_state = HOME;

uint8_t uc_cursor_position;

uint32_t today_steps;
uint32_t history_steps[7];
uint32_t all_time_steps;
uint32_t total_days;
uint32_t watts;

uint8_t sound;
uint8_t shade;

const char * state_to_string(states_t state) {
  const char * name_list[NUM_MACHINE_STATES];

  name_list[0] = "home";
  name_list[1] = "menu";
  name_list[2] = "radar";
  name_list[3] = "dowsing";
  name_list[4] = "comms";
  name_list[5] = "card";
  name_list[6] = "inventory";
  name_list[7] = "settings";
  name_list[8] = "sound";
  name_list[9] = "shade";
  name_list[10] = "stats";
  name_list[11] = "battle";
  name_list[12] = "switch";
  name_list[13] = "pause";
  name_list[14] = "err";

  return name_list[state];
}


