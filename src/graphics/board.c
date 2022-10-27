#include <stdlib.h>
#include <stdbool.h>

#include "../include/raylib.h"
#include "../include/raymath.h"

#include "tmp_structs.h"

#include "board.h"

int TILE_SIZE = 50;

int drawBoard (Board *board, AssetManager *assets, double x_offset, double y_offset, double width) {

    float tile_width = ((float) width) / board->cols ;
    float scale = tile_width / TILE_SIZE;
    Vector2 position;
    
    for (int i = 0; i < board->rows; ++i) {
        for (int j =0; j < board->cols; ++j) {
            position.x = x_offset + j * (tile_width);
            position.y = y_offset + i * (tile_width);
            DrawTextureEx(assets->tile, position, 0.0f, scale, RAYWHITE);
        }
    }
    
    return EXIT_SUCCESS;
}
