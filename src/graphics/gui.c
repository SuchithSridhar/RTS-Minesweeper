#include <stdlib.h>
#include <stdio.h>
#include "../include/raylib.h"
#include "../include/raymath.h"

#include "gui.h"
#include "state.h"
#include "constants.h"
#include "start.h"
#include "menu.h"

int screen_width = INITIAL_SCREEN_WIDTH;
int screen_height = INITIAL_SCREEN_HEIGHT;
char title[] = GAME_TITLE;

int state = STATE_START;

void runGameGui(){
    MenusBundle *menu_bundle = initMenusBundle(&screen_width, &screen_height);
    InitWindow(screen_width, screen_height, title);
    SetTargetFPS(60);
    Vector2 mousePos = {0.0f, 0.0f};
    Vector2 *mp = &mousePos;
    while (!WindowShouldClose() && state != STATE_EXIT){
        handleStateClicks(menu_bundle, mp, &state);
        handleGUIDraw(menu_bundle, mp, &state, &screen_width, &screen_height);
    }
    freeMemoryResources(menu_bundle);
    CloseWindow();
}
