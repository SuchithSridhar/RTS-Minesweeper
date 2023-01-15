#include "gameplay.h"

#include <stdlib.h>
#include "raylib.h"

#include "../game_functions/game_structs.h"
#include "../game_functions/board_functions.h"
#include "gameplay/constants.h"
#include "tmp_structs.h"
#include "gameplay/board.h"


GameplayData* initGameplay(AssetManager *assets) {
    GameplayData *gpd = malloc(sizeof(GameplayData));
    gpd->assets = assets;
    gpd->board = createBoard(DEFAULT_BOARD_WIDTH, DEFAULT_BOARD_HEIGHT);
    return gpd;
}

void endGameplay(GameplayData *gameplay_data) {
    destroyBoard(gameplay_data->board);
    free(gameplay_data);
}

int handleGameplayDraw(GameplayData *gameplay_data, double screen_width, double screen_height) {
    // Padding for the window edges.
    int X_OFFSET = BOARD_PADDING;
    int Y_OFFSET = BOARD_PADDING;
    drawBoard(
        gameplay_data->board,
        gameplay_data->assets,
        X_OFFSET,
        Y_OFFSET,
        screen_width - (2 * X_OFFSET),
        screen_height - (2 * Y_OFFSET)
    );

    return EXIT_SUCCESS;
}

int handleGameplayActions(GameplayData *gameplay_data, Vector2 *mouse_position, double screen_width, double screen_height) {
    int X_OFFSET = BOARD_PADDING;
    int Y_OFFSET = BOARD_PADDING;
    if (
        (mouse_position->x > X_OFFSET && mouse_position->x < screen_width - (2 * X_OFFSET)) &&
        (mouse_position->y > Y_OFFSET && mouse_position->y < screen_width - (2 * Y_OFFSET))
    ) {
        Vector2 in_board_mouse = { mouse_position->x - X_OFFSET, mouse_position->y - Y_OFFSET };
        handleBoardActionEvents(gameplay_data->board, in_board_mouse, screen_width - (2 * X_OFFSET));
    }
    return EXIT_SUCCESS;
}
