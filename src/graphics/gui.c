#include <stdlib.h>

#include "../include/raylib.h"
#include "../include/raymath.h"

#include "gui.h"
#include "state.h"
#include "tmp_structs.h"
#include "constants.h"
#include "start.h"
int screen_width = INITIAL_SCREEN_WIDTH;
int screen_height = INITIAL_SCREEN_HEIGHT;
char title[] = GAME_TITLE;

int state = STATE_START;

void runGameGui() {
    Menu *menu =(Menu*) malloc(sizeof(menu));
    StartSettings *start_settings =(StartSettings*) malloc(sizeof(start_settings));
    Settings *settings =(Settings*) malloc(sizeof(settings));
    Statistics *statistics =(Statistics*) malloc(sizeof(statistics));

    initStartMenu(menu,screen_width,screen_height);
    initStartGameSettings(start_settings,screen_width,screen_height);
    initSettings(settings,screen_width,screen_height);
    initStatistics(statistics,screen_width,screen_height);
    InitWindow(screen_width, screen_height, title);

    SetTargetFPS(60);
    Vector2 mousePos= {0.0f, 0.0f};
    Vector2 *mp =&mousePos;
    while (!WindowShouldClose()) {
        mousePos = GetMousePosition();
                switch (state){
            case(STATE_START):
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)&&menu->button_mouse_over>0)
                    menuClick(menu,&state);
                break;
            case(STATE_START_SETTINGS):
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)&&start_settings->button_mouse_over>0)
                    startGameClick(start_settings,&state);
                break;
            case(STATE_GAME):
                // TODO: Add a click function for in game state
                break;
            case(STATE_SETTINGS):
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)&&settings->button_mouse_over>0)
                    settingsClick(settings,&state);
                break;
            case(STATE_STATISTICS):
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)&&statistics->button_mouse_over==1)
                    statsClick(&state);
                break;
            default:
                // TODO: Add an error message.
                break;
        }
        menu->button_mouse_over=0;
        settings->button_mouse_over=0;
        start_settings->button_mouse_over=0;
        statistics->button_mouse_over=0;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (state){
            case(STATE_START):
                drawStartMenu(menu,screen_width,screen_height);
                startHover(mp,menu);
                break;
            case(STATE_START_SETTINGS):
                drawStartGameSettings(start_settings,screen_width,screen_height);
                startSettingsHover(mp,start_settings);
                break;
            case(STATE_GAME):
                // TODO: Add a draw game function
                break;
            case(STATE_SETTINGS):
                drawSettings(settings,screen_width,screen_height);
                settingsHover(mp,settings);
                break;
            case(STATE_STATISTICS):
                drawStatistics(statistics,screen_width,screen_height);
                statisticsHover(mp,statistics);
                break;
            case(STATE_EXIT):
                exitGame();
                break;
            default:
                // TODO: Add an error message.
                break;
        }
        EndDrawing();
    }

    CloseWindow();
}
