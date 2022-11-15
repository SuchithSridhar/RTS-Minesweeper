#include <stdlib.h>

#include "../include/raylib.h"
#include "../include/raymath.h"

#include "gui.h"
#include "state.h"
#include "tmp_structs.h"
#include "constants.h"
#include "start.h"
int screen_width = 800;
int screen_height = 800;
char title[] = "Minesweeper RTS";

int state = STATE_START;

void runGameGui() {
    Menu *menu =(Menu*) malloc(sizeof(menu));
    StartSettings *start_settings =(StartSettings*) malloc(sizeof(start_settings));
    Settings *settings =(Settings*) malloc(sizeof(settings));
    Statistics *statistics =(Statistics*) malloc(sizeof(statistics));
    // Init Menu
    menu->menu_button_array= (MenuButton*)malloc(sizeof(MenuButton)*NUM_MENU_BUTTONS);
    menu->title = "RTS Minesweeper";
    menu->menu_button_array[0].text="START";
    menu->menu_button_array[1].text="SETTINGS";
    menu->menu_button_array[2].text="STATISTICS";
    menu->menu_button_array[3].text="QUIT";
    for(int i=0; i<NUM_MENU_BUTTONS;i++){
        menu->menu_button_array[i].button_width =((float)screen_width/5);
        menu->menu_button_array[i].button_height = ((float)screen_height/10);
    }
    menu->button_hover=0;
    SetMenuBounds(menu,screen_width,screen_height);

    // Init Start Settings
    start_settings->menu_button_array= (MenuButton*)malloc(sizeof(MenuButton)*NUM_SETTINGS_BUTTONS);
    start_settings->menu_button_array[0].text="BACK";
    start_settings->menu_button_array[1].text="PLAY";
    for(int i=0; i<NUM_SETTINGS_BUTTONS;i++){
        start_settings->menu_button_array[i].button_width =((float)screen_width/5);
        start_settings->menu_button_array[i].button_height = ((float)screen_height/10);
    }
    start_settings->button_hover=0;
    SetStartGameBounds(start_settings,screen_width,screen_height);

    // Init Settings
    settings->menu_button_array= (MenuButton*)malloc(sizeof(MenuButton)*NUM_SETTINGS_BUTTONS);
    settings->menu_button_array[0].text="BACK";
    settings->menu_button_array[1].text="APPLY";
    for(int i=0; i<NUM_SETTINGS_BUTTONS;i++){
        settings->menu_button_array[i].button_width =((float)screen_width/5);
        settings->menu_button_array[i].button_height = ((float)screen_height/10);
    }
    settings->button_hover=0;
    SetSettingsBounds(settings,screen_width,screen_height);

    // Init Stats 
    statistics->menu_button_array= (MenuButton*)malloc(sizeof(MenuButton));
    statistics->menu_button_array[0].text="BACK";
    statistics->menu_button_array[0].button_width =((float)screen_width/5);
    statistics->menu_button_array[0].button_height = ((float)screen_height/10);
    statistics->button_hover=0;
    SetStatsBounds(statistics,screen_width,screen_height);

    InitWindow(screen_width, screen_height, title);
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (state){
            case(STATE_START):
                break;
            case(STATE_START_SETTINGS):
                break;
            case(STATE_GAME):
                break;
            case(STATE_SETTINGS):
                break;
            case(STATE_STATISTICS):
                break;
            case(STATE_EXIT):
                break;
            default:
                // TODO: Add an error message.
                break;
        }
        EndDrawing();
    }

    CloseWindow();
}
