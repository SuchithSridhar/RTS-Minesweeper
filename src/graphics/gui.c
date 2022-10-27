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

    for (int i=0; i < (board->cols * board->rows); ++i) {
        board->tile_array[i].bombs_around = 0;
        board->tile_array[i].is_bomb = false;
        board->tile_array[i].is_flagged = false;
        board->tile_array[i].is_open = false;
    }

    // Testing tiles
    board->tile_array[0].is_open = true;
    board->tile_array[1].is_flagged = true;
    board->tile_array[2].is_bomb = true;

    board->tile_array[3].is_open = true;
    board->tile_array[3].bombs_around = 1;

    board->tile_array[4].is_open = true;
    board->tile_array[4].bombs_around = 2;

    board->tile_array[5].is_open = true;
    board->tile_array[5].bombs_around = 3;

    board->tile_array[6].is_open = true;
    board->tile_array[6].bombs_around = 4;

    board->tile_array[7].is_open = true;
    board->tile_array[7].bombs_around = 5;

    InitWindow(screen_width, screen_height, title);

    Vector2 mousePos = {0.0f, 0.0f};
    Vector2 *mp = &mousePos;
    
    SetTargetFPS(60);

    // Init Assets
    assets->tile_1 = LoadTexture("assets/tile-1.png");
    assets->tile_2 = LoadTexture("assets/tile-2.png");
    assets->tile_3 = LoadTexture("assets/tile-3.png");
    assets->tile_4 = LoadTexture("assets/tile-4.png");
    assets->tile_5 = LoadTexture("assets/tile-5.png");
    assets->tile_opened = LoadTexture("assets/tile-opened.png");
    assets->tile_closed = LoadTexture("assets/tile-closed.png");
    assets->tile_flag = LoadTexture("assets/tile-flag.png");
    assets->tile_bomb = LoadTexture("assets/tile-bomb.png");

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
