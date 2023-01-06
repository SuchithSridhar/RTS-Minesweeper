#ifndef MENU_H
#define MENU_H

#define NUM_MENU_BUTTONS 4
#define NUM_SETTINGS_BUTTONS 2
#define NUM_STATS_BUTTONS 1

#define BACK_BUTTON_TITLE "BACK"
#define APPLY_BUTTON_TITLE "APPLY"
#define START_BUTTON_TITLE "START"
#define STATS_BUTTON_TITLE "STATISTICS"
#define SETTINGS_BUTTON_TITLE "SETTINGS"
#define QUIT_BUTTON_TITLE "QUIT"

//These constants are used to represent the different buttons. Used for hover checking(add 1 to these) and array indexing
#define START_BUTTON_INTEGER 0
#define SETTINGS_BUTTON_INTEGER 1
#define STATS_BUTTON_INTEGER 2
#define QUIT_BUTTON_INTEGER 3
#define BACK_BUTTON_INTEGER 0
#define APPLY_BUTTON_INTEGER 1
#define START_GAME_BUTTON_INTEGER 1

//This constant is used to represent that there was no hover detected
#define NO_HOVER 0
#endif