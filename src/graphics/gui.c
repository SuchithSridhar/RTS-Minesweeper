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
char title[] = "Minesweeper RTS";

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
                if((CheckCollisionPointRec(*mp,menu->menu_button_array[0].bounds)
                ||CheckCollisionPointRec(*mp,menu->menu_button_array[1].bounds)
                ||CheckCollisionPointRec(*mp,menu->menu_button_array[2].bounds)
                ||CheckCollisionPointRec(*mp,menu->menu_button_array[3].bounds))){
                    if((CheckCollisionPointRec(*mp,menu->menu_button_array[0].bounds))){
                        MouseHoverButton(&menu->menu_button_array[0]);
                        menu->button_hover=1;
                    }
                    else if(CheckCollisionPointRec(*mp,menu->menu_button_array[1].bounds)){
                        MouseHoverButton(&menu->menu_button_array[1]);
                        menu->button_hover=2;
                    }
                    else if(CheckCollisionPointRec(*mp,menu->menu_button_array[2].bounds)){
                        MouseHoverButton(&menu->menu_button_array[2]);
                        menu->button_hover=3;
                    }
                    else{
                        MouseHoverButton(&menu->menu_button_array[3]);
                        menu->button_hover=4;
                    }
                }
                break;
            case(STATE_START_SETTINGS):
                DrawStartGameSettings(start_settings,screen_width,screen_height);
                if(CheckCollisionPointRec(*mp,start_settings->menu_button_array[0].bounds)||CheckCollisionPointRec(*mp,start_settings->menu_button_array[1].bounds)){
                    if((CheckCollisionPointRec(*mp,start_settings->menu_button_array[0].bounds))){
                        MouseHoverButton(&start_settings->menu_button_array[0]);
                        start_settings->button_hover=1;
                    }
                    else{
                        MouseHoverButton(&start_settings->menu_button_array[1]);
                        start_settings->button_hover=2;
                    }
                }
                break;
            case(STATE_GAME):
                // TODO: Add a draw game function
                break;
            case(STATE_SETTINGS):
                DrawSettings(settings,screen_width,screen_height);
                if(CheckCollisionPointRec(*mp,settings->menu_button_array[0].bounds)||CheckCollisionPointRec(*mp,settings->menu_button_array[1].bounds)){
                    if((CheckCollisionPointRec(*mp,settings->menu_button_array[0].bounds))){
                        MouseHoverButton(&settings->menu_button_array[0]);
                        settings->button_hover=1;
                    }
                    else{
                        MouseHoverButton(&settings->menu_button_array[1]);
                        settings->button_hover=2;
                    }
                }
                break;
            case(STATE_STATISTICS):
                DrawStatistics(statistics,screen_width,screen_height);
                if(CheckCollisionPointRec(*mp,statistics->menu_button_array[0].bounds)){
                    MouseHoverButton(&statistics->menu_button_array[0]);
                    statistics->button_hover=1;
                }   
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
