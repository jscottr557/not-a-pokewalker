#include "transitions.h"
#include "device_state.h"

void v_shade_to_home() {
  TRANSITION_SIMPLE(0, HOME);
}