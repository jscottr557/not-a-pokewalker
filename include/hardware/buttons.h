#include <stdint.h>

#ifndef BUTTONS_H
#define BUTTONS_H

#define L_BUTTON_PIN 20
#define C_BUTTON_PIN 2
#define R_BUTTON_PIN 3

#define L_BUTTON 0
#define R_BUTTON 1
#define C_BUTTON 2
#define NONE_BUTTON -1

typedef uint8_t button_t;

extern volatile uint8_t uc_which_button;

void v_disable_buttons(); //kill the interrupt lines
void v_enable_buttons(); //unkill the interrupt lines

void v_left_ISR();
void v_center_ISR();
void v_right_ISR();

#endif