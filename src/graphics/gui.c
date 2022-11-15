#include <stdlib.h>

#include "../include/raylib.h"
#include "../include/raymath.h"

#include "gui.h"
#include "state.h"
#include "constants.h"
int screenWidth = 800;
int screenHeight = 800;
char title[] = "Minesweeper RTS";

int state = STATE_START;

void runGameGui() {
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
