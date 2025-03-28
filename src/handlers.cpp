#include "handlers.h"
#include "transitions.h"

void v_handler_left_button(states_t state) {
  switch(state) {
    case HOME:
      v_home_to_menu(5);
      break;
    case MENU:
      if(uc_cursor_position == 0) {v_menu_to_home(); break;}
      uc_cursor_position--; 
      break;
    case CARD:
      v_card_to_menu();
      break;
    case STATS:
      if(uc_cursor_position == 0) {v_stats_to_card(); break;}
      uc_cursor_position--;
    case SETTINGS:
      if(uc_cursor_position < 0) {
        uc_cursor_position--;
        break;
      }
      v_settings_to_menu();
      break;
    default:
      break;
  }
}

void v_handler_center_button(states_t state) {
  switch(state) {
    case HOME:
      v_home_to_menu(2);
      break;
    case MENU:
      switch(uc_cursor_position) {
        case 0:
          v_menu_to_radar();
          break;
        case 1:
          v_menu_to_dowsing();
          break;
        case 2:
          v_menu_to_comms();
          break;
        case 3:
          v_menu_to_card();
          break;
        case 4:
          v_menu_to_inventory();
          break;
        case 5:
          v_menu_to_settings();
          break;
        default:
          break;
      }
      break;
    case CARD:
      v_card_to_home();
      break;
    case STATS:
      v_stats_to_home();
      break;
    case SETTINGS:
      switch(uc_cursor_position) {
        case 0:
          v_settings_to_sound();
          break;
        case 1:
          v_settings_to_shade();
          break;
      }
      break;
    case SOUND:
      //save new sound setting
      v_sound_to_home();
      break;
    case SHADE:
      //save new shade setting
      v_shade_to_home();
      break;
    case INVENTORY:
      v_inventory_to_home();
      break;
    default:
      //its so over
      break;
  }
}

void v_handler_right_button(states_t state) {
  switch(state) {
    case HOME:
      v_home_to_menu(0);
      break;
    case MENU:
      if(uc_cursor_position == 5) {v_menu_to_home(); break;}
      uc_cursor_position++;
      break;
    case CARD:
      v_card_to_stats();
      break;
    case STATS:
      if(uc_cursor_position < 6) {
        uc_cursor_position++;
        break;
      }
      //play an err sound
      break;
    case SETTINGS:
    if(uc_cursor_position < 1) {
      uc_cursor_position++;
      break;
    }
    break;
    default:
      break;
  }
}