#ifndef CURSOR_BOUNDS_H
#define CURSOR_BOUNDS_H

#define CURSOR_LEFT() (uc_cursor_position--)
#define CURSOR_RIGHT() (uc_cursor_position++)
#define CURSOR_UP() (uc_cursor_position++)
#define CURSOR_DOWN() (uc_cursor_position--)

#define CURSOR_MENU_LOW 0
#define CURSOR_MENU_HIGH 5

#define CURSOR_STATS_LOW 0
#define CURSOR_STATS_HIGH 6

#define CURSOR_MENU_RADAR 0
#define CURSOR_MENU_DOWSING 1
#define CURSOR_MENU_COMMS 2
#define CURSOR_MENU_CARD 3
#define CURSOR_MENU_INVENTORY 4
#define CURSOR_MENU_SETTINGS 5

#define CURSOR_SETTINGS_LOW 0
#define CURSOR_SETTINGS_HIGH 1

#define CURSOR_DOWSING_LOW 0
#define CURSOR_DOWSING_HIGH 5

#define CURSOR_RADAR_LOW 0
#define CURSOR_RADAR_HIGH 3


#endif