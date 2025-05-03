#include "HyperDisplay_KWH018ST01_4WSPI.h"

#define PWM_PIN 5
#define CS_PIN 35
#define DC_PIN 34
#define SPI_PORT SPI
#define SPI_SPEED 32000000 

#define NUM_CHARS_PER_LINE 21 

extern KWH018ST01_4WSPI display;

extern wind_info_t state_window;
extern wind_info_t option_window;
extern wind_info_t cursor_window;

extern ILI9163C_color_18_t color_white;
extern ILI9163C_color_18_t color_black;

void graphics_init();
void clear_window(wind_info_t *window_to_clear);

/* printing functions */
void draw_state(const char *state_name); //Draws the given state in pre-defined state window
void draw_options(uint8_t num_options); //Draws specified number of "#s" in pre-defined option window
void draw_cursor(uint8_t cursor_position); //Draws "*"(the cursor) in pre-defined cursor window. position is an option index, not a pixel position
/*                    */

