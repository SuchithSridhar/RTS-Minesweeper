#ifndef BOARD_H
#define BOARD_H

#include "raylib.h"

#include "../../game_functions/game_structs.h"
#include "../tmp_structs.h"

/**
 * Draw the board within the specified dimensions.
 * @param board the board to be drawn.
 * @param x_offset the x offset for the start of the board.
 * @param y_offset the y offset for the start of the board.
 * @param width the width of the board.
 * @param height the height of the board.
 * @return an exit code if necessary else returns EXIT_SUCCESS.
 */
int drawBoard(Board *board, AssetManager *assets, double x_offset,
              double y_offset, double width, double height);

/**
 * Handle mouse and keyboard events over the board.
 * @param board is the board to handle the action on.
 * @param mouse_position is the current mouse position, must start at 0 and end
 * at board width.
 * @param width is width of the board.
 * @return an exit code if necessary, else returns EXIT_SUCCESS.
 */
int handleBoardActionEvents(Board *board, Vector2 mouse_position, double width);

#endif
