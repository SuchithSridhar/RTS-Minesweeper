#include <stdlib.h>

#include "../include/raylib.h"
#include "../include/raymath.h"

#include "board.h"
#include "tmp_structs.h"

#include "gui.h"
#include "state.h"
int screenWidth = 800;
int screenHeight = 800;
char title[] = "Minesweeper RTS";

int state = STATE_START;

// TODO: Move to const file
char *TILE_IMAGE = "assets/tile.png";

void runGameGui() {

    // TODO: Move to main and initialize in game functions.
    Board *board = (Board*) malloc(sizeof(Board));
    AssetManager *assets = (AssetManager*) malloc(sizeof(AssetManager));

    // Init Board
    board->cols = 8;
    board->rows = 8;
    board->tile_array = (Tile*)malloc(sizeof(Tile) * board->cols * board->rows);

    InitWindow(screenWidth, screenHeight, title);
    
    SetTargetFPS(60);

    // Init Assets
    assets->tile = LoadTexture(TILE_IMAGE);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (state){
            case STATE_GAMEPLAY:
                drawBoard(board, assets, 10, 10, screenWidth-20);
            default:
                // TODO: Add an error message.
                break;
        }
        EndDrawing();
    }

    CloseWindow();

}
