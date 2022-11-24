#include <stdlib.h>

#include "../include/raylib.h"
#include "../include/raymath.h"

#include "gui.h"
#include "state.h"
#include "tmp_structs.h"
#include "constants.h"
#include "start.h"
int screen_width = SCREEN_WIDTH;
int screen_height = SCREEN_HEIGHT;
char title[] = TITLE;

int state = STATE_START;

void runGameGui() {
    Menu *menu =(Menu*) malloc(sizeof(menu));
    StartSettings *start_settings =(StartSettings*) malloc(sizeof(start_settings));
    Settings *settings =(Settings*) malloc(sizeof(settings));
    Statistics *statistics =(Statistics*) malloc(sizeof(statistics));

    InitStartMenu(menu,screen_width,screen_height);
    InitStartGameSettings(start_settings,screen_width,screen_height);
    InitSettings(settings,screen_width,screen_height);
    InitStatistics(statistics,screen_width,screen_height);
    InitWindow(screen_width, screen_height, title);

    SetTargetFPS(60);
    Vector2 mousePos= {0.0f, 0.0f};
    Vector2 *mp =&mousePos;
    while (!WindowShouldClose()) {
        mousePos = GetMousePosition();
                switch (state){
            case(STATE_START):
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)&&menu->button_hover>0)
                    MenuClick(menu,&state);
                break;
            case(STATE_START_SETTINGS):
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)&&start_settings->button_hover>0)
                    StartGameClick(start_settings,&state);
                break;
            case(STATE_GAME):
                // TODO: Add a click function for in game state
                break;
            case(STATE_SETTINGS):
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)&&settings->button_hover>0)
                    SettingsClick(settings,&state);
                break;
            case(STATE_STATISTICS):
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)&&statistics->button_hover==1)
                    StatsClick(&state);
                break;
            default:
                // TODO: Add an error message.
                break;
        }
        menu->button_hover=0;
        settings->button_hover=0;
        start_settings->button_hover=0;
        statistics->button_hover=0;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (state){
            case(STATE_START):
                DrawStartMenu(menu,screen_width,screen_height);
                StartHover(mp,menu);
                break;
            case(STATE_START_SETTINGS):
                DrawStartGameSettings(start_settings,screen_width,screen_height);
                StartSettingsHover(mp,start_settings);
                break;
            case(STATE_GAME):
                // TODO: Add a draw game function
                break;
            case(STATE_SETTINGS):
                DrawSettings(settings,screen_width,screen_height);
                SettingsHover(mp,settings);
                break;
            case(STATE_STATISTICS):
                DrawStatistics(statistics,screen_width,screen_height);
                StatisticsHover(mp,statistics);
                break;
            case(STATE_EXIT):
                ExitGame();
                break;
            default:
                // TODO: Add an error message.
                break;
        }
        EndDrawing();
    }

    CloseWindow();
}
