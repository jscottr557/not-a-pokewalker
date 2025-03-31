#include <stdint.h>

#ifndef SUBROUTINES_H
#define SUBROUTINES_H

extern uint8_t sound;
extern uint8_t shade;

extern uint8_t items_held;
extern uint8_t mons_held;

void v_subroutine_sound(uint8_t button_number);
void v_subroutine_shade(uint8_t button_number);


#endif