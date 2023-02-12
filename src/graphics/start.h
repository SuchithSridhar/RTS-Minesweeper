#ifndef START_H
#define START_H

#include "../../include/raylib.h"

typedef struct {
    char *text;
    Rectangle bounds;
} MenuButton;

typedef struct {
    char *title;
    MenuButton *menu_button_array;
    int button_mouse_over;
} StartMenu;

typedef struct {
    MenuButton *menu_button_array;
    int button_mouse_over;
} Statistics;

typedef struct {
    MenuButton *menu_button_array;
    int button_mouse_over;
} Settings;

typedef struct {
    MenuButton *menu_button_array;
    int button_mouse_over;
} StartSettings;

typedef struct {
    StartMenu *menu;
    Statistics *statistics;
    Settings *settings;
    StartSettings *start_settings;
} MenusBundle;

/**
 * The initMenusBundle function creates the initial data for the MenusBundle
 * struct Memory is allocated using malloc and must be freed using the sibling
 * function freeMenusBundle
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 * @return returns a MenusBundle pointer which is to be used in the game.
 */
MenusBundle *initMenusBundle(int *screen_width, int *screen_height);

/**
 * The initStartMenu function creates the initial data for the StartMenu struct
 * Memory is allocated using malloc and must be freed using the sibling function
 * freeStartMenu
 * @param menu_bundle pointer to a MenusBundle struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void initStartMenu(MenusBundle *menu_bundle, int *screen_width,
                   int *screen_height);

/**
 * The initStartGameSettings function creates the initial data for the
 * StartSettings struct Memory is allocated using malloc and must be freed using
 * the sibling function freeStartGameSettings
 * @param menu_bundle pointer to a MenusBundle struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void initStartGameSettings(MenusBundle *menu_bundle, int *screen_width,
                           int *screen_height);

/**
 * The initSettings function creates the initial data for the Settings struct
 * Memory is allocated using malloc and must be freed using the sibling function
 * freeSettings
 * @param menu_bundle pointer to a MenusBundle struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void initSettings(MenusBundle *menu_bundle, int *screen_width,
                  int *screen_height);

/**
 * The initStatistics function creates the initial data for the Statistics
 * struct Memory is allocated using malloc and must be freed using the sibling
 * function freeStatistics
 * @param menu_bundle pointer to a MenusBundle struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void initStatistics(MenusBundle *menu_bundle, int *screen_width,
                    int *screen_height);

/**
 * The createMenuButtonArray function creates a MenuButton array
 * Memory is allocated using malloc and must be freed using the sibling function
 * freeMenuButtonArray
 * @param num_menu_button a number corresponding to the number of buttons
 * @param titles is a array of pointers of strings corresponding to the button
 * titles
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 * @return A menu button pointer which points to the new menu button array
 */
MenuButton *createMenuButtonArray(int num_menu_button, char **titles,
                                  int *screen_width, int *screen_height);

/**
 * The initMenuButtonBounds function creates the bounds for the menu button
 * @param posx the x position of the rectangle
 * @param posy the y position of the rectangle
 * @param width the width of the rectangle
 * @param height the height of the rectangle
 * @return A rectangle which represents the bounds of the button
 */
Rectangle initMenuButtonBounds(float posx, float posy, float width,
                               float height);

/**
 * The freeMenuButtonArray function frees the dynamically allocated memory
 * assigned to a MenuButton array
 * @param menu_button_array a pointer to a memory button_array
 */
void freeMenuButtonArray(MenuButton *menu_button_array);

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
 * the drawMenuButton function uses a MenuButton struct to draw it on the screen
 * @param menu_button a pointer to a menu button
 */
void drawMenuButton(MenuButton *menu_button);

/**
 * The drawStartMenu function uses a StartMenu struct to draw the buttons and
 * the title of the start menu
 * @param menu pointer to a StartMenu struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void drawStartMenu(StartMenu *menu, int *screen_width, int *screen_height);

/**
 * The drawStartGameSettings function uses a StartSettings struct to draw the
 * buttons of the game initialization menu
 * @param start_settings pointer to a StartSettings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void drawStartGameSettings(StartSettings *start_settings, int *screen_width,
                           int *screen_height);

/**
 * The drawSettings function uses a Settings struct to draw the buttons and GUI
 * of the settings menu
 * @param settings pointer to a Settings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void drawSettings(Settings *settings, int *screen_width, int *screen_height);

/**
 * The drawStatistics function uses a Statistics struct to draw the buttons of
 * the statistics menu
 * @param statistics pointer to a Statistics struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void drawStatistics(Statistics *statistics, int *screen_width,
                    int *screen_height);

/**
 * The handleGUIDraw function determines which draw function to call, and
 * whether or not a button needs to be highlighted or not
 * @param menu_bundle a pointer to a MenusBundle struct
 * @param mp a pointer to a Vector2 struct representing the current position of
 * the mouse.
 * @param state a pointer to an integer representing the state
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void handleGUIDraw(MenusBundle *menu_bundle, Vector2 *mp, int *state,
                   int *screen_width, int *screen_height);

/**
 * The setMenuBounds function sets creates the rectangle bounds for the buttons
 * in the StartMenu struct
 * @param menu pointer to a StartMenu struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void setMenuBounds(StartMenu *menu, int *screen_width, int *screen_height);

/**
 * The setStartGameBounds function sets creates the rectangle bounds for the
 * buttons in the StartSettings struct
 * @param start_settings pointer to a StartSettings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void setStartGameBounds(StartSettings *start_settings, int *screen_width,
                        int *screen_height);

/**
 * The setSettingsBounds function sets creates the rectangle bounds for the
 * buttons in the Settings struct
 * @param settings pointer to a Settings struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void setSettingsBounds(Settings *settings, int *screen_width,
                       int *screen_height);

/**
 * The setStatsBounds function sets creates the rectangle bounds for the buttons
 * in the Statistics struct
 * @param statistics pointer to a Statistics struct
 * @param screen_width represents the current screen width
 * @param screen_height represents the current screen height
 */
void setStatsBounds(Statistics *stats, int *screen_width, int *screen_height);

/**
 * The checkHover function determines whether the mouse is hovered over a menu
 * button
 * @param menu_button_array a pointer to an array of MenuButtons
 * @param mp a pointer to a Vector2 which represents the current position of the
 * mouse
 * @param start_index the first index to check hover
 * @param end_index the last index to check hover
 * @return bool | true if the mp is over the bounds of one of the MenuButtons,
 * false otherwise
 */
bool checkHover(MenuButton *menu_button_array, Vector2 *mp, int start_index,
                int end_index);

/**
 * The mouseHoverButton changes the colour of a button which is being hovered
 * @param button pointer to a specific MenuButton
 */
void mouseHoverButton(MenuButton *button);

/**
 * The startHover function determines whether or not a button is being hovered,
 * and if so change the button hover variable to reflect this
 * @param mp a pointer to a Vector2 struct representing the current mouse
 * position
 * @param menu a pointer to a StartMenu struct
 */
void startHover(Vector2 *mp, StartMenu *menu);

/**
 * The startSettingsHover function determines whether or not a button is being
 * hovered, and if so change the button hover variable to reflect this
 * @param mp a pointer to a Vector2 struct representing the current mouse
 * position
 * @param start_settings a pointer to a StartSettings struct
 */
void startSettingsHover(Vector2 *mp, StartSettings *start_settings);

/**
 * The settingsHover function determines whether or not a button is being
 * hovered, and if so change the button hover variable to reflect this
 * @param mp a pointer to a Vector2 struct representing the current mouse
 * position
 * @param settings a pointer to a Settings struct
 */
void settingsHover(Vector2 *mp, Settings *settings);

/**
 * The statisticsHover function determines whether or not a button is being
 * hovered, and if so change the button hover variable to reflect this
 * @param mp a pointer to a Vector2 struct representing the current mouse
 * position
 * @param statistics a pointer to a Statistics struct
 */
void statisticsHover(Vector2 *mp, Statistics *statistics);

/**
 * The handleStateClicks function handles whether or not a click will result in
 * a state change
 * @param menu_bundle a pointer to a MenusBundle struct
 * @param mp a pointer to a Vector2 struct representing the current position of
 * the mouse.
 * @param state a pointer to an integer representing the state
 */
void handleStateClicks(MenusBundle *menu_bundle, Vector2 *mp, int *state);

/**
 * The handleStartMenuClick function changes the state depending on whether or
 * not a click has occured over a state changing button
 * @param menu a pointer to a StartMenu struct
 * @param state a pointer to an integer representing the state
 */
void handleStartMenuClick(StartMenu *menu, int *state);

/**
 * The handleStartGameClick function changes the state depending on whether or
 * not a click has occured over a state changing button
 * @param start_settings a pointer to a StartSettings struct
 * @param state a pointer to an integer representing the state
 */
void handleStartGameClick(StartSettings *start_settings, int *state);

/**
 * The handleSettingsClick function changes the state depending on whether or
 * not a click has occured over a state changing button
 * @param settings a pointer to a Settings struct
 * @param state a pointer to an integer representing the state
 */
void handleSettingsClick(Settings *settings, int *state);

/**
 * The handleStatisticsClick function changes the state depending on whether or
 * not a click has occured over a state changing button
 * @param state a pointer to an integer representing the state
 */
void handleStatisticsClick(int *state);
#endif
