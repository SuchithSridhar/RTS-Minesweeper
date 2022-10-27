#ifndef BOARD_H
#define BOARD_H

#include "../include/raylib.h"

#include "tmp_structs.h"

/**
 * Draw the board based on the tiles.
 * width specifies the width of the whole board.
 * each tile is scaled to fit the width. Make sure you
 * have the same height as the width provided available
 * to be drawn.
 */
int drawBoard (Board *board, AssetManager *assets, double x_offset, double y_offset, double width);

#endif
