#include "board.h"

#include <stdlib.h>
#include <stdbool.h>

#include "../include/raylib.h"
#include "../include/raymath.h"

#include "../tmp_structs.h"
#include "../../game_functions/board_functions.h"
#include "constants.h"

int handleBoardActionEvents (Board *board, Vector2 mouse_position, double width) {
    float tile_width = ((float) width) / board->cols;

    int selected_tile_row = (int) (mouse_position.y / tile_width);
    int selected_tile_col = (int) (mouse_position.x / tile_width);

    int selected_tile_index = calcIndexFromPosition(selected_tile_row,  selected_tile_col, board->cols);
    bool gameEnd = false;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        gameEnd = board->click(board, selected_tile_row, selected_tile_col);
    } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        Tile *tile = board->tile_array + selected_tile_index;
        tile->is_flagged = !tile->is_flagged;
    }

    return EXIT_SUCCESS;
}


int drawBoard (Board *board, AssetManager *assets, double x_offset, double y_offset, double width, double height) {

    float tile_width = ((float) width) / board->cols ;
    float scale = tile_width / TILE_IMAGE_SIZE;
    Vector2 position;
    Tile cur_tile;
    Texture2D asset_to_draw;
    
    for (int i = 0; i < board->rows; ++i) {
        for (int j =0; j < board->cols; ++j) {
            position.x = x_offset + j * (tile_width);
            position.y = y_offset + i * (tile_width);

            cur_tile = board->tile_array[ (i * board->cols) + j ];

            if (cur_tile.is_bomb) {
                asset_to_draw = assets->tile_bomb;
            } else if (cur_tile.is_open) {
                switch (cur_tile.bombs_around) {
                    case 1:
                        asset_to_draw = assets->tile_1;
                        break;
                    case 2:
                        asset_to_draw = assets->tile_2;
                        break;
                    case 3:
                        asset_to_draw = assets->tile_3;
                        break;
                    case 4:
                        asset_to_draw = assets->tile_4;
                        break;
                    case 5:
                        asset_to_draw = assets->tile_5;
                        break;
                    default:
                        asset_to_draw = assets->tile_opened;
                }
            } else if (cur_tile.is_flagged) {
                asset_to_draw = assets->tile_flag;
            } else {
                asset_to_draw = assets->tile_closed;
            }

            DrawTextureEx(asset_to_draw, position, 0.0f, scale, RAYWHITE);
        }
    }
    
    return EXIT_SUCCESS;
}
