#ifndef BOARD_H
#define BOARD_H

#include "raylib.h"

#include "../../game_functions/game_structs.h"
#include "../tmp_structs.h"

/** A struct to hold data for the GUI of the Board. */
typedef struct {
    /** The minesweeper board. */
    Board *board;
    /** The size of the board (in px). */
    int size;
    /** The x offset for drawing from top left corner (in px). */
    int x_offset;
    /** The y offset for drawing from top left corner (in px). */
    int y_offset;
} BoardGui;

/**
 * Draw the board within the specified dimensions.
 * @param board the board to be drawn.
 * @param x_offset the x offset for the start of the board.
 * @param y_offset the y offset for the start of the board.
 * @param size the size of the board.
 * @return an exit code if necessary else returns EXIT_SUCCESS.
 */
int drawBoard(BoardGui *board_gui, AssetManager *assets);

/**
 * Handle mouse and keyboard events over the board.
 * @param board is the board to handle the action on.
 * @param mouse_position is the current mouse position, must start at 0 and end
 * at board width.
 * @param size is size of the board.
 * @return an exit code if necessary, else returns EXIT_SUCCESS.
 */
int handleBoardActionEvents(BoardGui *board_gui, Vector2 mouse_position);

/**
 * Create the BoardGui struct.
 * @param board the minesweeper board.
 * @return a pointer to the BoardGui.
 */
BoardGui *createBoardGui(Board *board);

/**
 * Destroy BoardGui struct.
 * @param board_gui the BoardGui to destroy.
 */
void destroyBoardGui(BoardGui *board_gui);

#endif
