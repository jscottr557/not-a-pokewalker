#include <stdint.h>

#ifndef BUTTONS_H
#define BUTTONS_H

#define L_BUTTON_PIN 3
#define C_BUTTON_PIN 2
#define R_BUTTON_PIN 20

#define NUM_BUTTONS 3

extern uint8_t uc_button_left_flag;
extern uint8_t uc_button_center_flag;
extern uint8_t uc_button_right_flag;


void v_disable_buttons(); //kill the interrupts
void v_enable_buttons(); //unkill the interrupts

void v_left_ISR();
void v_center_ISR();
void v_right_ISR();

#endif