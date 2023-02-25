#include "gameplay.h"

#include "raylib.h"
#include <stdlib.h>

#include "../game_functions/board_functions.h"
#include "../game_functions/game_structs.h"
#include "gameplay/board.h"
#include "gameplay/constants.h"
#include "tmp_structs.h"

GameplayData *initGameplay(AssetManager *assets) {
    GameplayData *gpd = malloc(sizeof(GameplayData));
    gpd->assets = assets;
    gpd->board = createBoard(DEFAULT_BOARD_WIDTH, DEFAULT_BOARD_HEIGHT);
    return gpd;
}

void endGameplay(GameplayData *gameplay_data) {
    destroyBoard(gameplay_data->board);
    free(gameplay_data);
}

int handleGameplayDraw(GameplayData *gameplay_data, int screen_width,
                       int screen_height) {
    // Padding for the window edges.
    int X_OFFSET = BOARD_PADDING;
    int Y_OFFSET = BOARD_PADDING;
    drawBoard(gameplay_data->board, gameplay_data->assets, X_OFFSET, Y_OFFSET,
              screen_width - (2 * X_OFFSET), screen_height - (2 * Y_OFFSET));

    return EXIT_SUCCESS;
}

int handleGameplayActions(GameplayData *gameplay_data, Vector2 *mouse_position,
                          int screen_width, int screen_height) {

    int x_offset = BOARD_PADDING;
    int y_offset = BOARD_PADDING;
    if ((mouse_position->x > x_offset &&
         mouse_position->x < screen_width - (2 * x_offset)) &&
        (mouse_position->y > y_offset &&
         mouse_position->y < screen_width - (2 * y_offset))) {
        Vector2 in_board_mouse = {mouse_position->x - x_offset,
                                  mouse_position->y - y_offset};
        handleBoardActionEvents(gameplay_data->board, in_board_mouse,
                                screen_width - (2 * x_offset),
                                screen_height - (2 * y_offset));
    }
    return EXIT_SUCCESS;
}
