#include <Arduino.h>

#include "buttons.h"

uint8_t uc_button_vector[NUM_BUTTONS];

void v_enable_buttons() {
  attachInterrupt(digitalPinToInterrupt(L_BUTTON_PIN), v_left_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(C_BUTTON_PIN), v_center_ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(R_BUTTON_PIN), v_right_ISR, RISING);
  return;
}

void v_disable_buttons() {
  detachInterrupt(digitalPinToInterrupt(L_BUTTON_PIN));
  detachInterrupt(digitalPinToInterrupt(C_BUTTON_PIN));
  detachInterrupt(digitalPinToInterrupt(R_BUTTON_PIN));
  return;
}


void v_left_ISR() {
  uc_button_left_flag |= 1; //if we're REALLY low on space we can move all of the interrupt flags to a combined bit string
  return;
}

void v_center_ISR() {
  uc_button_center_flag |= 1;
  return;
}

void v_right_ISR() {
  uc_button_right_flag++;
  return;
}