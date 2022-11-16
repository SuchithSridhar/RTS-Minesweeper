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
    Vector2 mousePos= {0.0f, 0.0f};
    Vector2 *mp =&mousePos;
    while (!WindowShouldClose()) {
        mousePos = GetMousePosition();
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
