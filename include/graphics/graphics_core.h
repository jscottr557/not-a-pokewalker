#include "HyperDisplay_KWH018ST01_4WSPI.h"

#define PWM_PIN 5
#define CS_PIN 35
#define DC_PIN 34
#define SPI_PORT SPI
#define SPI_SPEED 32000000 

#define CHAR_LINE_WIDTH 0 

void graphics_init();

//as a rule, try not to use globals in these functions



void draw_state(const char *state_name);

void draw_options(uint8_t num_options);
void draw_cursor(uint8_t cursor_position);