#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include "buttons.h"
#include "driving_loop.h"

uint8_t uc_which_button;
static BaseType_t xHigherPriorityTaskWoken = pdFALSE;  


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
	uc_which_button = L_BUTTON; 

	vTaskNotifyGiveFromISR(x_driving_loop_handle, &xHigherPriorityTaskWoken);
	if(xHigherPriorityTaskWoken == pdTRUE) portYIELD_FROM_ISR();
  return;
}

void v_center_ISR() {
	uc_which_button = C_BUTTON; 

	vTaskNotifyGiveFromISR(x_driving_loop_handle, &xHigherPriorityTaskWoken); 
	if(xHigherPriorityTaskWoken == pdTRUE) portYIELD_FROM_ISR();
  return;
}

void v_right_ISR() {
	uc_which_button = R_BUTTON; 

	vTaskNotifyGiveFromISR(x_driving_loop_handle, &xHigherPriorityTaskWoken); 
	if(xHigherPriorityTaskWoken == pdTRUE) portYIELD_FROM_ISR();
  return;
}