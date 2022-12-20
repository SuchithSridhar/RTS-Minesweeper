#ifndef START_H
#define START_H

#include "../../include/raylib.h"

#include "constants.h"

typedef struct{
    char *text;
    float button_width;
    float button_height;
    Rectangle bounds;
} MenuButton;
typedef struct{
    char *title;
    MenuButton *menu_button_array;
    int button_mouse_over;
} StartMenu;
typedef struct{
    MenuButton *menu_button_array;
    int button_mouse_over;
} Statistics;
typedef struct{
    MenuButton *menu_button_array;
    int button_mouse_over;
} Settings;
typedef struct{
    MenuButton *menu_button_array;
    int button_mouse_over;
} StartSettings;
typedef struct{
    StartMenu *menu;
    Statistics *statistics;
    Settings *settings;
    StartSettings *start_settings;
} MenusBundle;
/**
 * The initMenusBundle method creates the initial data for the MenusBundle struct
 * Memory is allocated using malloc and must be freed using the sibling function
 * freeMenusBundle 
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 * @return returns a MenusBundle pointer which is to be used in the game.
*/
MenusBundle * initMenusBundle(int *screen_width, int *screen_height);
/**
 * The initStartMenu method creates the initial data for the StartMenu struct
 * Memory is allocated using malloc and must be freed using the sibling function
 * freeStartMenu 
 * @param menu_bundle pointer to a MenusBundle struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void initStartMenu(MenusBundle *menu_bundle, int *screen_width, int *screen_height);

/**
 * The initStartGameSettings method creates the initial data for the StartSettings struct
 * Memory is allocated using malloc and must be freed using the sibling function
 * freeStartGameSettings
 * @param menu_bundle pointer to a MenusBundle struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void initStartGameSettings(MenusBundle *menu_bundle, int *screen_width, int *screen_height);

/**
 * The initSettings method creates the initial data for the Settings struct
 * Memory is allocated using malloc and must be freed using the sibling function
 * freeSettings 
 * @param menu_bundle pointer to a MenusBundle struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void initSettings(MenusBundle *menu_bundle, int *screen_width, int *screen_height);

/**
 * The initStatistics method creates the initial data for the Statistics struct
 * Memory is allocated using malloc and must be freed using the sibling function
 * freeStatistics 
 * @param menu_bundle pointer to a MenusBundle struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void initStatistics(MenusBundle *menu_bundle, int *screen_width, int *screen_height);

/**
 * Frees the dynamically allocated memory assigned to the MenusBundle struct.
 * @param menu_bundle pointer to a MenusBundle struct, to free
*/
void freeMenusBundle(MenusBundle *menu_bundle);

/**
 * Frees the dynamically allocated memory assigned to the StartMenu struct.
 * @param menu a StartMenu pointer to free
*/
void freeStartMenu(StartMenu *menu);

/**
 * Frees the dynamically allocated memory assigned to the StartSettings struct.
 * @param start_settings a StartSettings pointer to free
*/
void freeStartGameSettings(StartSettings *start_settings);

/**
 * Frees the dynamically allocated memory assigned to the Settings struct.
 * @param settings a Settings pointer to free
*/
void freeSettings(Settings *settings);

/**
 * Frees the dynamically allocated memory assigned to the Statistics struct.
 * @param statistics a Statistics pointer to free
*/
void freeStatistics(Statistics *statistics);

/**
 * The drawStartMenu method uses a StartMenu struct to draw the buttons and the title of the start menu
 * @param menu pointer to a StartMenu struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void drawStartMenu(StartMenu *menu,int *screen_width,int *screen_height);

/**
 * The drawStartGameSettings method uses a StartSettings struct to draw the buttons of the game initialization menu
 * @param start_settings pointer to a StartSettings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void drawStartGameSettings(StartSettings *start_settings,int *screen_width, int *screen_height);

/**
 * The drawSettings method uses a Settings struct to draw the buttons and GUI of the settings menu
 * @param settings pointer to a Settings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void drawSettings(Settings *settings, int *screen_width, int *screen_height);

/**
 * The drawStatistics method uses a Statistics struct to draw the buttons of the statistics menu
 * @param statistics pointer to a Statistics struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void drawStatistics(Statistics *statistics, int *screen_width, int *screen_height);

/**
 * The handleGUIDraw method determines which draw method to call, and whether or not a button needs to be highlighted or not
 * @param menu_bundle a pointer to a MenusBundle struct
 * @param mp a pointer to a Vector2 struct representing the current position of the mouse. 
 * @param state a pointer to an integer representing the state 
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void handleGUIDraw(MenusBundle *menu_bundle,Vector2 *mp,int *state,int *screen_width,int*screen_height);
/**
 * The setMenuBounds method sets creates the rectangle bounds for the buttons in the StartMenu struct
 * @param menu pointer to a StartMenu struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void setMenuBounds(StartMenu *menu,int *screen_width,int*screen_height);

/**
 * The setStartGameBounds method sets creates the rectangle bounds for the buttons in the StartSettings struct
 * @param start_settings pointer to a StartSettings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void setStartGameBounds(StartSettings *start_settings,int *screen_width,int *screen_height);

/**
 * The setSettingsBounds method sets creates the rectangle bounds for the buttons in the Settings struct
 * @param settings pointer to a Settings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void setSettingsBounds(Settings *settings,int *screen_width,int *screen_height);

/**
 * The setStatsBounds method sets creates the rectangle bounds for the buttons in the Statistics struct
 * @param statistics pointer to a Statistics struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void setStatsBounds(Statistics *stats,int *screen_width,int *screen_height);

/**
 * The mouseHoverButton changes the colour of a button which is being hovered
 * @param button pointer to a specific MenuButton
*/
void mouseHoverButton(MenuButton *button);

/**
 * The startHover method determines whether or not a button is being hovered, and if so change the button hover variable to reflect this
 * @param mp a pointer to a Vector2 struct representing the current mouse position
 * @param menu a pointer to a StartMenu struct
*/
void startHover(Vector2 *mp,StartMenu *menu);

/**
 * The startSettingsHover method determines whether or not a button is being hovered, and if so change the button hover variable to reflect this
 * @param mp a pointer to a Vector2 struct representing the current mouse position
 * @param start_settings a pointer to a StartSettings struct
*/
void startSettingsHover(Vector2 *mp,StartSettings *start_settings);

/**
 * The settingsHover method determines whether or not a button is being hovered, and if so change the button hover variable to reflect this
 * @param mp a pointer to a Vector2 struct representing the current mouse position
 * @param settings a pointer to a Settings struct
*/
void settingsHover(Vector2 *mp,Settings *settings);

/**
 * The statisticsHover method determines whether or not a button is being hovered, and if so change the button hover variable to reflect this
 * @param mp a pointer to a Vector2 struct representing the current mouse position
 * @param statistics a pointer to a Statistics struct
*/
void statisticsHover(Vector2 *mp, Statistics *statistics);

/**
 * The handleStateClicks method handles whether or not a click will result in a state change
 * @param menu_bundle a pointer to a MenusBundle struct
 * @param mp a pointer to a Vector2 struct representing the current position of the mouse. 
 * @param state a pointer to an integer representing the state
*/
void handleStateClicks(MenusBundle *menu_bundle,Vector2 *mp,int *state);

/**
 * The handleStartMenuClick method changes the state depending on whether or not a click has occured over a state changing button
 * @param menu a pointer to a StartMenu struct
 * @param state a pointer to an integer representing the state
*/
void handleStartMenuClick(StartMenu *menu,int *state);

/**
 * The handleStartGameClick method changes the state depending on whether or not a click has occured over a state changing button
 * @param start_settings a pointer to a StartSettings struct
 * @param state a pointer to an integer representing the state
*/
void handleStartGameClick(StartSettings *start_settings,int *state);

/**
 * The handleSettingsClick method changes the state depending on whether or not a click has occured over a state changing button
 * @param settings a pointer to a Settings struct
 * @param state a pointer to an integer representing the state
*/
void handleSettingsClick(Settings *settings,int *state);

/**
 * The handleStatisticsClick method changes the state depending on whether or not a click has occured over a state changing button
 * @param state a pointer to an integer representing the state
*/
void handleStatisticsClick(int *state);
#endif