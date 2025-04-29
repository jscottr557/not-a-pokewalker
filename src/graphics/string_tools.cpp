#include <stdlib.h>
#include <stdint.h>

#include "string_tools.h"

char *make_filled_string(char fill, uint32_t total_size) {
	char *new_string = (char *) malloc(sizeof(char) * total_size);
	if(new_string == NULL) return NULL;

	for(uint32_t i = 0; i < total_size - 1; i++) {
		new_string[i] = fill;
	}
	new_string[total_size - 1] = '\0';

	return new_string;
}

void center_string(const char *str, char *buffer, uint32_t buffer_size) {
	if(str == NULL) return;
	if(buffer == NULL) return;

	uint32_t str_size = strlen(str) + 1;
	if(str_size > buffer_size) return;

	uint8_t starting_index = (buffer_size - str_size) / 2;
	for(uint32_t i = 0; i < str_size - 1; i++) {
		buffer[starting_index + i] = str[i];
	}

	//sanity check
	buffer[buffer_size - 1] = '\0';

	return;
}