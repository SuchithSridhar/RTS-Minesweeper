#include <stdlib.h>

#include "../include/raylib.h"
#include "../include/raymath.h"

#include "gui.h"
#include "state.h"
#include "tmp_structs.h"
#include "constants.h"
#include "start.h"
int screenWidth = 800;
int screenHeight = 800;
char title[] = "Minesweeper RTS";

int state = STATE_START;

void runGameGui() {
    Menu *menu =(Menu*) malloc(sizeof(menu));
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

    InitWindow(screenWidth, screenHeight, title);
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Example Window!", screenWidth/2 - MeasureText("Example Window!", 32) / 2, screenHeight / 2 - 32 / 2, 32, DARKGRAY);
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
