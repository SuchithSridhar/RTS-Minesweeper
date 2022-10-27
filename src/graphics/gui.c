#include <stdlib.h>
#include <stdio.h>
#include "../include/raylib.h"
#include "../include/raymath.h"

#include "board.h"
#include "tmp_structs.h"

#include "gui.h"
#include "state.h"
#include "constants.h"
#include "start.h"
#include "menu.h"

int screen_width = INITIAL_SCREEN_WIDTH;
int screen_height = INITIAL_SCREEN_HEIGHT;
char title[] = GAME_TITLE;

int state = STATE_START;
// TODO: Move to const file
char *TILE_IMAGE = "assets/tile.png";

void runGameGui() {

    // TODO: Move to main and initialize in game functions.
    Board *board = (Board*) malloc(sizeof(Board));
    AssetManager *assets = (AssetManager*) malloc(sizeof(AssetManager));
    MenusBundle *menu_bundle = initMenusBundle(&screen_width, &screen_height);

    // Init Board
    board->cols = 8;
    board->rows = 8;
    board->tile_array = (Tile*)malloc(sizeof(Tile) * board->cols * board->rows);

    InitWindow(screen_width, screen_height, title);

    Vector2 mousePos = {0.0f, 0.0f};
    Vector2 *mp = &mousePos;
    
    SetTargetFPS(60);

    // Init Assets
    assets->tile = LoadTexture(TILE_IMAGE);

    SetTargetFPS(60);

    while (!WindowShouldClose() && state != STATE_EXIT) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        handleStateClicks(menu_bundle, mp, &state);
        handleGUIDraw(menu_bundle, mp, &state, &screen_width, &screen_height);
        switch (state){
            case STATE_GAMEPLAY:
                drawBoard(board, assets, 10, 10, screen_width-20);
            default:
                // TODO: Add an error message.
                break;
        }
        EndDrawing();
    }
    freeMenusBundle(menu_bundle);
    CloseWindow();

}
