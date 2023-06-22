#include "gameplay.h"

#include "raylib.h"
#include <stdlib.h>

#include "../game_functions/board_functions.h"
#include "../game_functions/game_structs.h"
#include "gameplay/board.h"
#include "gameplay/constants.h"

GameplayData *initGameplay(AssetManager *assets) {
    GameplayData *gpd = malloc(sizeof(GameplayData));
    gpd->assets = assets;

    Board *board = createBoard(DEFAULT_BOARD_WIDTH, DEFAULT_BOARD_HEIGHT);
    gpd->boardGui = createBoardGui(board);
    return gpd;
}

void endGameplay(GameplayData *gameplay_data) {
    destroyBoardGui(gameplay_data->boardGui);
    free(gameplay_data);
}

int handleGameplayDraw(GameplayData *gameplay_data, int screen_width,
                       int screen_height) {
    // Padding for the window edges.
    int size = screen_width < screen_height ? screen_width : screen_height;
    int x_offset = ((screen_width - size) / 2) + BOARD_PADDING;
    int y_offset = ((screen_height - size) / 2) + BOARD_PADDING;

    size -= 2 * BOARD_PADDING;

    gameplay_data->boardGui->size = size;
    gameplay_data->boardGui->x_offset = x_offset;
    gameplay_data->boardGui->y_offset = y_offset;

    drawBoard(gameplay_data->boardGui, gameplay_data->assets);

    return EXIT_SUCCESS;
}

int handleGameplayActions(GameplayData *gameplay_data,
                          Vector2 *mouse_position) {
    int x_offset = gameplay_data->boardGui->x_offset;
    int y_offset = gameplay_data->boardGui->y_offset;
    int size = gameplay_data->boardGui->size;

    bool mousex_within_bounds = (mouse_position->x >= x_offset) &&
                                (mouse_position->x < x_offset + size);
    bool mousey_within_bounds = (mouse_position->y >= y_offset) &&
                                (mouse_position->y < y_offset + size);

    if (mousex_within_bounds && mousey_within_bounds) {
        Vector2 in_board_mouse = {mouse_position->x - x_offset,
                                  mouse_position->y - y_offset};
        handleBoardActionEvents(gameplay_data->boardGui, in_board_mouse);
    }
    return EXIT_SUCCESS;
}
