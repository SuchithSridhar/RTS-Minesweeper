#include "../../include/raylib.h"
#include "../../include/raymath.h"
#include <stdio.h>
#include <stdlib.h>

#include "constants.h"
#include "menu.h"
#include "start.h"
#include "state.h"

MenusBundle *initMenusBundle(int *screen_width, int *screen_height) {
    MenusBundle *menu_bundle = malloc(sizeof(MenusBundle));
    initStartMenu(menu_bundle, screen_width, screen_height);
    initStartGameSettings(menu_bundle, screen_width, screen_height);
    initSettings(menu_bundle, screen_width, screen_height);
    initStatistics(menu_bundle, screen_width, screen_height);
    return menu_bundle;
}

MenuButton *createMenuButtonArray(int num_menu_button, char *titles[],
                                  int *screen_width, int *screen_height) {
    MenuButton *menu_button_array =
        malloc(sizeof(MenuButton) * num_menu_button);
    for (int i = 0; i < num_menu_button; i++) {
        menu_button_array[i].text = titles[i];
    }
    return menu_button_array;
}

void initStartMenu(MenusBundle *menu_bundle, int *screen_width,
                   int *screen_height) {
    StartMenu *menu = malloc(sizeof(StartMenu));
    menu_bundle->menu = menu;
    menu->title = GAME_TITLE;
    char *titles[] = {START_BUTTON_TITLE, SETTINGS_BUTTON_TITLE,
                      STATS_BUTTON_TITLE, QUIT_BUTTON_TITLE};
    menu->menu_button_array = createMenuButtonArray(
        NUM_MENU_BUTTONS, titles, screen_width, screen_height);
    menu->button_mouse_over = 0;
    setMenuBounds(menu, screen_width, screen_height);
}

void initStartGameSettings(MenusBundle *menu_bundle, int *screen_width,
                           int *screen_height) {
    StartSettings *start_settings = malloc(sizeof(StartSettings));
    menu_bundle->start_settings = start_settings;
    char *titles[] = {BACK_BUTTON_TITLE, START_BUTTON_TITLE};
    start_settings->menu_button_array = createMenuButtonArray(
        NUM_SETTINGS_BUTTONS, titles, screen_width, screen_height);
    start_settings->button_mouse_over = 0;
    setStartGameBounds(start_settings, screen_width, screen_height);
}

void initSettings(MenusBundle *menu_bundle, int *screen_width,
                  int *screen_height) {
    Settings *settings = malloc(sizeof(Settings));
    menu_bundle->settings = settings;
    char *titles[] = {BACK_BUTTON_TITLE, APPLY_BUTTON_TITLE};
    settings->menu_button_array = createMenuButtonArray(
        NUM_SETTINGS_BUTTONS, titles, screen_width, screen_height);
    settings->button_mouse_over = 0;
    setSettingsBounds(settings, screen_width, screen_height);
}

void initStatistics(MenusBundle *menu_bundle, int *screen_width,
                    int *screen_height) {
    Statistics *statistics = malloc(sizeof(Statistics));
    menu_bundle->statistics = statistics;
    char *titles[] = {BACK_BUTTON_TITLE};
    statistics->menu_button_array = createMenuButtonArray(
        NUM_STATS_BUTTONS, titles, screen_width, screen_height);
    statistics->button_mouse_over = 0;
    setStatsBounds(statistics, screen_width, screen_height);
}

void freeMenusBundle(MenusBundle *menu_bundle) {
    freeSettings(menu_bundle->settings);
    freeStartGameSettings(menu_bundle->start_settings);
    freeStatistics(menu_bundle->statistics);
    freeStartMenu(menu_bundle->menu);
    free(menu_bundle);
}

void freeStartMenu(StartMenu *menu) {
    freeMenuButtonArray(menu->menu_button_array);
    free(menu);
}

void freeStartGameSettings(StartSettings *start_settings) {
    freeMenuButtonArray(start_settings->menu_button_array);
    free(start_settings);
}

void freeSettings(Settings *settings) {
    freeMenuButtonArray(settings->menu_button_array);
    free(settings);
}

void freeStatistics(Statistics *statistics) {
    freeMenuButtonArray(statistics->menu_button_array);
    free(statistics);
}

void freeMenuButtonArray(MenuButton *menu_button_array) {
    free(menu_button_array);
}

Rectangle initMenuButtonBounds(float posx, float posy, float width,
                               float height) {
    Rectangle newRect = {posx, posy, width, height};
    return newRect;
}
void setMenuBounds(StartMenu *menu, int *screen_width, int *screen_height) {
    float button_width = (*screen_width / 5.0f);
    float button_height = (*screen_height / 10.0f);
    for (int i = 0; i < NUM_MENU_BUTTONS; i++) {
        menu->menu_button_array[i].bounds = initMenuButtonBounds(
            *screen_width / 2.0f - button_width / 2.0f,
            i * (*screen_height / 2.0f - button_height / 2.0f) /
                    NUM_MENU_BUTTONS +
                *screen_height / 4.0f,
            button_width, button_height);
    }
}

void setStartGameBounds(StartSettings *start_settings, int *screen_width,
                        int *screen_height) {
    Vector2 position;
    position.x = (*screen_width / 2.0f - *screen_width / 4.0f);
    position.y = (*screen_height / 2.0f - *screen_height / 3.5f);
    // Assumes button width and height are the same
    float button_width = (*screen_width / 5.0f);
    float button_height = (*screen_height / 10.0f);
    for (int i = 0; i < NUM_SETTINGS_BUTTONS; i++) {
        if (i == 0) {
            start_settings->menu_button_array[i].bounds =
                initMenuButtonBounds(position.x + button_width / 7.0f,
                                     (position.y + *screen_height / 1.5f) -
                                         button_height - button_height / 7.0f,
                                     button_width, button_height);
        } else {
            start_settings->menu_button_array[i].bounds =
                initMenuButtonBounds((position.x + *screen_width / 2.0f) -
                                         button_width - button_width / 7.0f,
                                     (position.y + *screen_height / 1.5f) -
                                         button_height - button_height / 7.0f,
                                     button_width, button_height);
        }
    }
}

void setSettingsBounds(Settings *settings, int *screen_width,
                       int *screen_height) {

    Vector2 position;
    position.x = (*screen_width / 2.0f - *screen_width / 4.0f);
    position.y = (*screen_height / 2.0f - *screen_height / 3.5f);
    // Assumes button *screen_width and *screen_height are the same
    float button_width = (*screen_width / 5.0f);
    float button_height = (*screen_height / 10.0f);

    for (int i = 0; i < NUM_SETTINGS_BUTTONS; i++) {
        if (i == 0) {
            settings->menu_button_array[i].bounds =
                initMenuButtonBounds(position.x + button_width / 7.0f,
                                     (position.y + *screen_height / 1.5f) -
                                         button_height - button_height / 7.0f,
                                     button_width, button_height);
        } else {
            settings->menu_button_array[i].bounds =
                initMenuButtonBounds((position.x + *screen_width / 2.0f) -
                                         button_width - button_width / 7.0f,
                                     (position.y + *screen_height / 1.5f) -
                                         button_height - button_height / 7.0f,
                                     button_width, button_height);
        }
    }
}

void setStatsBounds(Statistics *stats, int *screen_width, int *screen_height) {
    Vector2 position;
    position.x = (*screen_width / 2.0f - *screen_width / 4.0f);
    position.y = (*screen_height / 2.0f - *screen_height / 3.5f);
    float button_width = (*screen_width / 5.0f);
    float button_height = (*screen_height / 10.0f);
    for (int i = 0; i < NUM_STATS_BUTTONS; i++) {
        stats->menu_button_array[i].bounds = initMenuButtonBounds(
            position.x + *screen_width / 4.0f - button_width / 2.0f,
            (position.y + *screen_height / 1.5f) - button_height -
                button_height / 7.0f,
            button_width, button_height);
    }
}

void updateBounds(MenusBundle *menu_bundle, int *screen_width, int *screen_height){
    setMenuBounds(menu_bundle->menu, screen_width, screen_height);
    setSettingsBounds(menu_bundle->settings, screen_width, screen_height);
    setStartGameBounds(menu_bundle->start_settings, screen_width, screen_height);
    setStatsBounds(menu_bundle->statistics, screen_width, screen_height);
}

void handleGUIDraw(MenusBundle *menu_bundle, Vector2 *mp, int *state, int *screen_width, int *screen_height){
    switch (*state){
        case (STATE_START):
            drawStartMenu(menu_bundle->menu, screen_width, screen_height);
            startHover(mp, menu_bundle->menu);
            break;
        case (STATE_START_SETTINGS):
            drawStartGameSettings(menu_bundle->start_settings, screen_width, screen_height);
            startSettingsHover(mp, menu_bundle->start_settings);
            break;
        case (STATE_SETTINGS):
            drawSettings(menu_bundle->settings, screen_width, screen_height);
            settingsHover(mp, menu_bundle->settings);
            break;
        case (STATE_STATISTICS):
            drawStatistics(menu_bundle->statistics, screen_width, screen_height);
            statisticsHover(mp, menu_bundle->statistics);
            break;
        default:
            // TODO: Add an error message.
            break;
    }
}

void drawMenuButton(MenuButton *menu_button) {
    Vector2 text_position;
    text_position.x = menu_button->bounds.x + (menu_button->bounds.width / 2.0f) - ((float)MeasureText(menu_button->text, 
    menu_button->bounds.width / FONT_SIZE_BUTTON)) / 2.0f;
    text_position.y = menu_button->bounds.y + (menu_button->bounds.height / 2.0f);
    DrawRectangleRec(menu_button->bounds, BLACK);
    DrawText(menu_button->text, text_position.x, text_position.y, menu_button->bounds.width 
    / FONT_SIZE_BUTTON, RAYWHITE);
}

void drawStartMenu(StartMenu *menu, int *screen_width, int *screen_height) {
    for (int i = 0; i < NUM_MENU_BUTTONS; i++) {
        drawMenuButton(&menu->menu_button_array[i]);
    }
    Vector2 title_position;
    title_position.x = *screen_width / 2.0f - ((float)MeasureText(menu->title, *screen_width / FONT_SIZE_TITLE)) / 2.0f;
    title_position.y = *screen_height / 10.0f;
    DrawText(menu->title, title_position.x, title_position.y, *screen_width / FONT_SIZE_TITLE, BLACK);
}
void drawStartGameSettings(StartSettings *start_settings, int *screen_width,
                           int *screen_height) {
    Vector2 position;
    position.x = (*screen_width / 2.0f - *screen_width / 4.0f);
    position.y = (*screen_height / 2.0f - *screen_height / 3.5f);
    DrawRectangle(position.x, position.y, *screen_width / 2.0f,
                  *screen_height / 1.5f, BLACK);
    for (int i = 0; i < NUM_SETTINGS_BUTTONS; i++) {
        drawMenuButton(&start_settings->menu_button_array[i]);
    }
}

void drawSettings(Settings *settings, int *screen_width, int *screen_height) {
    Vector2 position;
    position.x = (*screen_width / 2.0f - *screen_width / 4.0f);
    position.y = (*screen_height / 2.0f - *screen_height / 3.5f);
    DrawRectangle(position.x, position.y, *screen_width / 2.0f,
                  *screen_height / 1.5f, BLACK);
    for (int i = 0; i < NUM_SETTINGS_BUTTONS; i++) {
        drawMenuButton(&settings->menu_button_array[i]);
    }
}

void drawStatistics(Statistics *stats, int *screen_width, int *screen_height) {
    Vector2 position;
    position.x = (*screen_width / 2.0f - *screen_width / 4.0f);
    position.y = (*screen_height / 2.0f - *screen_height / 3.5f);
    DrawRectangle(position.x, position.y, *screen_width / 2.0f,
                  *screen_height / 1.5f, BLACK);
    for (int i = 0; i < NUM_STATS_BUTTONS; i++) {
        drawMenuButton(&stats->menu_button_array[i]);
    }
}
void mouseHoverButton(MenuButton *button) {
    DrawRectangleRec(button->bounds, DARKGRAY);
    Vector2 text_position;
    text_position.x = button->bounds.x + (button->bounds.width / 2.0f) - ((float)MeasureText(button->text, button->bounds.width 
    / FONT_SIZE_BUTTON)) / 2.0f;
    text_position.y = button->bounds.y + (button->bounds.height / 2.0f);
    DrawText(button->text, text_position.x, text_position.y, button->bounds.width 
    / FONT_SIZE_BUTTON, YELLOW);
}
bool checkHover(MenuButton *menu_button_array, Vector2 *mp, int start_index,
                int end_index) {
    for (int i = start_index; i <= end_index; i++) {
        if (CheckCollisionPointRec(*mp, menu_button_array[i].bounds))
            return true;
    }
    return false;
}
void startHover(Vector2 *mp, StartMenu *menu) {
    if (checkHover(menu->menu_button_array, mp, 0, 3)) {
        if (checkHover(menu->menu_button_array, mp, 0, 0)) {
            mouseHoverButton(&menu->menu_button_array[START_BUTTON_INTEGER]);
            menu->button_mouse_over = START_BUTTON_INTEGER + 1;
        } else if (checkHover(menu->menu_button_array, mp, 1, 1)) {
            mouseHoverButton(&menu->menu_button_array[SETTINGS_BUTTON_INTEGER]);
            menu->button_mouse_over = SETTINGS_BUTTON_INTEGER + 1;
        } else if (checkHover(menu->menu_button_array, mp, 2, 2)) {
            mouseHoverButton(&menu->menu_button_array[STATS_BUTTON_INTEGER]);
            menu->button_mouse_over = STATS_BUTTON_INTEGER + 1;
        } else {
            mouseHoverButton(&menu->menu_button_array[QUIT_BUTTON_INTEGER]);
            menu->button_mouse_over = QUIT_BUTTON_INTEGER + 1;
        }
    }
}

void startSettingsHover(Vector2 *mp, StartSettings *start_settings) {
    if (checkHover(start_settings->menu_button_array, mp, 0, 1)) {
        if (checkHover(start_settings->menu_button_array, mp, 0, 0)) {
            mouseHoverButton(
                &start_settings->menu_button_array[BACK_BUTTON_INTEGER]);
            start_settings->button_mouse_over = BACK_BUTTON_INTEGER + 1;
        } else {
            mouseHoverButton(
                &start_settings->menu_button_array[START_GAME_BUTTON_INTEGER]);
            start_settings->button_mouse_over = START_GAME_BUTTON_INTEGER + 1;
        }
    }
}

void settingsHover(Vector2 *mp, Settings *settings) {
    if (checkHover(settings->menu_button_array, mp, 0, 1)) {
        if (checkHover(settings->menu_button_array, mp, 0, 0)) {
            mouseHoverButton(&settings->menu_button_array[BACK_BUTTON_INTEGER]);
            settings->button_mouse_over = BACK_BUTTON_INTEGER + 1;
        } else {
            mouseHoverButton(
                &settings->menu_button_array[APPLY_BUTTON_INTEGER]);
            settings->button_mouse_over = APPLY_BUTTON_INTEGER + 1;
        }
    }
}

void statisticsHover(Vector2 *mp, Statistics *statistics) {
    if (checkHover(statistics->menu_button_array, mp, 0, 0)) {
        mouseHoverButton(&statistics->menu_button_array[BACK_BUTTON_INTEGER]);
        statistics->button_mouse_over = BACK_BUTTON_INTEGER + 1;
    }
}

void handleStartMenuClick(StartMenu *menu, int *state) {
    switch (menu->button_mouse_over) {
    case (START_BUTTON_INTEGER + 1):
        *state = STATE_START_SETTINGS;
        break;
    case (SETTINGS_BUTTON_INTEGER + 1):
        *state = STATE_SETTINGS;
        break;
    case (STATS_BUTTON_INTEGER + 1):
        *state = STATE_STATISTICS;
        break;
    case (QUIT_BUTTON_INTEGER + 1):
        *state = STATE_EXIT;
        break;
    default:
        break;
    }
}
void handleStartGameClick(StartSettings *start_settings, int *state) {
    switch (start_settings->button_mouse_over) {
    case (BACK_BUTTON_INTEGER + 1):
        *state = STATE_START;
        break;
    case (START_GAME_BUTTON_INTEGER + 1):
        *state = STATE_TRANSITION_GAMEPLAY;
        break;
    default:
        break;
    }
}

void handleSettingsClick(Settings *settings, int *state) {
    switch (settings->button_mouse_over) {
    case (BACK_BUTTON_INTEGER + 1):
        *state = STATE_START;
        break;
    case (APPLY_BUTTON_INTEGER + 1):
        *state = STATE_SETTINGS;
        break;
    default:
        break;
    }
}

void handleStatisticsClick(int *state) { *state = STATE_START; }
void handleStateClicks(MenusBundle *menu_bundle, Vector2 *mp, int *state) {
    *mp = GetMousePosition();
    switch (*state) {
    case (STATE_START):
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) &&
            menu_bundle->menu->button_mouse_over > NO_HOVER)
            handleStartMenuClick(menu_bundle->menu, state);
        break;
    case (STATE_START_SETTINGS):
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) &&
            menu_bundle->start_settings->button_mouse_over > NO_HOVER)
            handleStartGameClick(menu_bundle->start_settings, state);
        break;
    case (STATE_SETTINGS):
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) &&
            menu_bundle->settings->button_mouse_over > NO_HOVER)
            handleSettingsClick(menu_bundle->settings, state);
        break;
    case (STATE_STATISTICS):
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) &&
            menu_bundle->statistics->button_mouse_over > NO_HOVER)
            handleStatisticsClick(state);
        break;
    default:
        // TODO: Add an error message.
        break;
    }
    menu_bundle->menu->button_mouse_over = NO_HOVER;
    menu_bundle->settings->button_mouse_over = NO_HOVER;
    menu_bundle->start_settings->button_mouse_over = NO_HOVER;
    menu_bundle->statistics->button_mouse_over = NO_HOVER;
}
