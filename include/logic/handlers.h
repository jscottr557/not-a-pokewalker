#include "device_state.h"

#ifndef HANDLERS_H
#define HANDLERS

//these three functions implement the entire primary state machine
void v_handler_left_button(states_t state);
void v_handler_center_button(states_t state);
void v_handler_right_button(states_t state);

#endif