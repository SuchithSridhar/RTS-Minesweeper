#include <stdlib.h>

#include "../include/raylib.h"
#include "../include/raymath.h"

#include "gui.h"

int screenWidth = 800;
int screenHeight = 480;
char title[] = "Raylib Template";

void runGameGui() {
    InitWindow(screenWidth, screenHeight, title);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Example Window!", screenWidth/2 - MeasureText("Example Window!", 32) / 2, screenHeight / 2 - 32 / 2, 32, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
}
