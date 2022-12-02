#ifndef START_H
#define START_H

#include "../../include/raylib.h"

#include "tmp_structs.h"
#include "constants.h"
/**
 * The `initStartMenu` method creates the initial data for the Menu struct
 * Memory is allocated using `malloc` and must be freed using the sibling function
 * `freeStartMenu` 
 * @param menu pointer to a Menu struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void initStartMenu(Menu *menu, int screen_width, int screen_height);

/**
 * The `initStartGameSettings` method creates the initial data for the StartSettings struct
 * Memory is allocated using `malloc` and must be freed using the sibling function
 * `freeStartGameSettings` 
 * @param start_settings pointer to a StartSettings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void initStartGameSettings(StartSettings *start_settings, int screen_width, int screen_height);

/**
 * The `initSettings` method creates the initial data for the Settings struct
 * Memory is allocated using `malloc` and must be freed using the sibling function
 * `freeSettings` 
 * @param settings pointer to a Settings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void initSettings(Settings *settings, int screen_width, int screen_height);

/**
 * The `initStatistics` method creates the initial data for the Statistics struct
 * Memory is allocated using `malloc` and must be freed using the sibling function
 * `freeStatistics` 
 * @param statistics pointer to a Statistics struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void initStatistics(Statistics *statistics, int screen_width, int screen_height);


/**
 * The `drawStartMenu` method uses a Menu struct to draw the buttons and the title of the start menu
 * @param menu pointer to a Menu struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void drawStartMenu(Menu *menu,double width,double height);

/**
 * The `drawStartGameSettings` method uses a StartSettings struct to draw the buttons of the game initialization menu
 * @param start_settings pointer to a StartSettings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void drawStartGameSettings(StartSettings *start_settings,double width, double height);

/**
 * The `drawSettings` method uses a Settings struct to draw the buttons and GUI of the settings menu
 * @param settings pointer to a Settings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void drawSettings(Settings *settings, double width, double height);

/**
 * The `drawStatistics` method uses a Statistics struct to draw the buttons of the statistics menu
 * @param statistics pointer to a Statistics struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void drawStatistics(Statistics *statistics, double width, double height);

/**
 * The `setMenuBounds` method sets creates the rectangle bounds for the buttons in the Menu struct
 * @param menu pointer to a Menu struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void setMenuBounds(Menu *menu,double width,double height);

/**
 * The `setStartGameBounds` method sets creates the rectangle bounds for the buttons in the StartSettings struct
 * @param start_settings pointer to a StartSettings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void setStartGameBounds(StartSettings *start_settings,double width,double height);

/**
 * The `setSettingsBounds` method sets creates the rectangle bounds for the buttons in the Settings struct
 * @param settings pointer to a Settings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void setSettingsBounds(Settings *settings,double width,double height);

/**
 * The `setStatsBounds` method sets creates the rectangle bounds for the buttons in the Statistics struct
 * @param statistics pointer to a Statistics struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
*/
void setStatsBounds(Statistics *stats,double width,double height);

/**
 * The `mouseHoverButton` changes the colour of a button which is being hovered
 * @param button pointer to a specific MenuButton
*/
void mouseHoverButton(MenuButton *button);

/**
 * The `startHover` method determines whether or not a button is being hovered, and if so change the button hover variable to reflect this
 * @param mp a pointer to a Vector2 struct representing the current mouse position
 * @param menu a pointer to a Menu struct
*/
void startHover(Vector2 *mp,Menu *menu);

/**
 * The `startSettingsHover` method determines whether or not a button is being hovered, and if so change the button hover variable to reflect this
 * @param mp a pointer to a Vector2 struct representing the current mouse position
 * @param start_settings a pointer to a StartSettings struct
*/
void startSettingsHover(Vector2 *mp,StartSettings *start_settings);

/**
 * The `settingsHover` method determines whether or not a button is being hovered, and if so change the button hover variable to reflect this
 * @param mp a pointer to a Vector2 struct representing the current mouse position
 * @param settings a pointer to a Settings struct
*/
void settingsHover(Vector2 *mp,Settings *settings);

/**
 * The `statisticsHover` method determines whether or not a button is being hovered, and if so change the button hover variable to reflect this
 * @param mp a pointer to a Vector2 struct representing the current mouse position
 * @param statistics a pointer to a Statistics struct
*/
void statisticsHover(Vector2 *mp, Statistics *statistics);

/**
 * The `menuClick` method changes the state depending on whether or not a click has occured over a state changing button
 * @param menu a pointer to a Menu struct
 * @param state a pointer to an integer representing the state
*/
void menuClick(Menu *menu,int *state);

/**
 * The `startGameClick` method changes the state depending on whether or not a click has occured over a state changing button
 * @param start_settings a pointer to a StartSettings struct
 * @param state a pointer to an integer representing the state
*/
void startGameClick(StartSettings *start_settings,int *state);

/**
 * The `settingsClick` method changes the state depending on whether or not a click has occured over a state changing button
 * @param settings a pointer to a Settings struct
 * @param state a pointer to an integer representing the state
*/
void settingsClick(Settings *settings,int *state);

/**
 * The `statsClick` method changes the state depending on whether or not a click has occured over a state changing button
 * @param state a pointer to an integer representing the state
*/
void statsClick(int *state);

void exitGame();

#endif