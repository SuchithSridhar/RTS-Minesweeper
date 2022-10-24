#include <stdlib.h>
#include <time.h>

#include "../include/raylib.h"
#include "../include/raymath.h"


int screenWidth = 800;
int screenHeight = 480;
char title[] = "Raylib Template";

int main() {
    srand(time(0));
    InitWindow(screenWidth, screenHeight, title);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Example Window!", screenWidth/2 - MeasureText("Example Window!", 32) / 2, screenHeight / 2 - 32 / 2, 32, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

