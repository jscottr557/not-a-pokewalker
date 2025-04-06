#include <stddef.h>
#include <Arduino_FreeRTOS.h>
#include <Arduino.h>

#include "prompt_block.h"
#include "buttons.h"

void v_block_with_prompt(const char *prompt) {
	//TODO:draw the prompt box & text
	//TODO:start the dot animation

	Serial.println(prompt);

	//block
	ulTaskNotifyTake(pdTRUE, portMAX_DELAY); //always executes in context of current task

	//RE-ENTRY HERE	
}