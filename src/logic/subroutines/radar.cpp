#include <stdlib.h>
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

#include "subroutines.h"
#include "cursor_bounds.h"
#include "prompt_block.h"
#include "device_state.h"

#define EARLY -1
#define LATE -2
#define MISS -3

#define MIN_MS 2000
#define MAX_MS 4000

TaskHandle_t x_alert_handle;

SemaphoreHandle_t sh_alert_lock;
static int8_t c_alert_index = 0;
static uint8_t uc_alert_count = 0;

uint8_t uc_check_for_miss();
void v_alert_generator(void *);
 
subroutine_status_t ss_radar_init() {
	c_alert_index = EARLY;
	uc_alert_count = 0;
	sh_alert_lock = xSemaphoreCreateMutex();
	xTaskCreate(v_alert_generator, "alert generator", 512, NULL, 1, &x_alert_handle);
	return SS_CONTINUE;
}

subroutine_status_t ss_radar_step_left() {
	xSemaphoreTake(sh_alert_lock, portMAX_DELAY);
	if(c_alert_index == LATE) {
		vTaskDelete(x_alert_handle);
		vSemaphoreDelete(sh_alert_lock);
		return SS_HALT;
	}
	xSemaphoreGive(sh_alert_lock);

	if(uc_cursor_position > CURSOR_RADAR_LOW) {
		CURSOR_LEFT();
	}
	else {
		uc_cursor_position = CURSOR_RADAR_HIGH;
	}
	return SS_CONTINUE;
}

subroutine_status_t ss_radar_step_right() {
	xSemaphoreTake(sh_alert_lock, portMAX_DELAY);
	if(c_alert_index == LATE) {
		vTaskDelete(x_alert_handle);
		vSemaphoreDelete(sh_alert_lock);
		return SS_HALT;
	}
	xSemaphoreGive(sh_alert_lock);

	if(uc_cursor_position < CURSOR_RADAR_HIGH) {
		CURSOR_RIGHT();
	}
	else {
		uc_cursor_position = CURSOR_RADAR_LOW;
	}
	return SS_CONTINUE;
}

subroutine_status_t ss_radar_step_center() {
	xSemaphoreTake(sh_alert_lock, portMAX_DELAY);

	if(uc_check_for_miss()) {
		vTaskDelete(x_alert_handle); //stop the alert generator
		vSemaphoreDelete(sh_alert_lock); //since we've deleted the other code that messes with c_alert_index, we can safely delete

		switch(c_alert_index) {
			case EARLY:
				v_block_with_prompt("too early!");
				break;
			case LATE:
				break;
			default:
				v_block_with_prompt("miss!");
				break;
		}
		return SS_HALT;
	}

	uc_alert_count++;
	vTaskDelete(x_alert_handle);

	if(uc_alert_count >= 2) { //go to battle
		v_block_with_prompt("found a pokemon!");
		//TODO: transition to battle
		return SS_HALT; //TEMP!!!!
	}
	else { //keep going
		v_block_with_prompt("found something...");
		xTaskCreate(v_alert_generator, "alert generator", 512, (void *)(&uc_alert_count), 1, &x_alert_handle); //restart the alert generator
	}

	xSemaphoreGive(sh_alert_lock);
	return SS_CONTINUE;
}

void v_alert_generator(void *param) {
	uint16_t uc_ms_to_wait = ((rand() % (MAX_MS - 1000)) + MIN_MS);
	vTaskDelay(pdMS_TO_TICKS(uc_ms_to_wait));

	xSemaphoreTake(sh_alert_lock, portMAX_DELAY);
	c_alert_index = rand() % 4;
	xSemaphoreGive(sh_alert_lock);

	//draw the alert
	Serial.print("!: ");
	Serial.println(c_alert_index);

	uc_ms_to_wait = ((rand() % (MAX_MS - 1000)) + MIN_MS);
	vTaskDelay(pdMS_TO_TICKS(uc_ms_to_wait));

	//undraw the alert

	xSemaphoreTake(sh_alert_lock, portMAX_DELAY);
	c_alert_index = LATE;
	xSemaphoreGive(sh_alert_lock);

	v_block_with_prompt("it got away...");
}

uint8_t uc_check_for_miss() {
	switch(c_alert_index) {
		case EARLY:
			return EARLY;
		case LATE:
			return LATE;
	}

	if(uc_cursor_position != c_alert_index) {
		return MISS;
	}
	return 0;
}