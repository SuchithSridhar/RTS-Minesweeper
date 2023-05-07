#include "board_functions.h"
#include <stdbool.h>
#include <stdlib.h>

#define TILES_AROUND 8

/**
 * Update all necessary tiles as a certain tile has been clicked.
 * @param board the Board struct to update.
 * @param index the index at which the update is to start.
 */
void _updateNeighborTiles(Board *board, int index);

struct positionFromIndex calcPositionFromIndex(int index, int width) {
    struct positionFromIndex return_val;
    return_val.row = index / width;
    return_val.col = index % width;
    return return_val;
}

int calcIndexFromPosition(int row, int col, int width) {
    return (row * width) + col;
}

Tile *createTile() {
    Tile *new_tile = malloc(sizeof(Tile));
    return new_tile;
}

void initilizeTile(Tile *tile, int row, int col, bool is_bomb) {
    tile->row = row;
    tile->col = col;

    // -1 represents bombs around
    tile->bombs_around = -1;
    tile->is_bomb = is_bomb;
    tile->is_flagged = false;
    tile->is_open = false;
}

void destroyTile(Tile *tile) { free(tile); }

Tile *createTileArray(int size) {
    Tile *new_array = malloc(sizeof(Tile) * size);
    return new_array;
}

void initilizeTileArray(Tile *tile_array, int size, int width) {
    struct positionFromIndex calc_pos;
    for (int i = 0; i < size; i++) {
        calc_pos = calcPositionFromIndex(i, width);
        initilizeTile(tile_array + i, calc_pos.row, calc_pos.col, false);
    }
}

void destroyTileArray(Tile *tile_array) { free(tile_array); }

void _updateNeighborTiles(Board *board, int index) {
    // Tile Index out of bounds
    if (index < 0 || index >= board->array_size)
        return;

    Tile *tile = board->tile_array + index;

    // Tile has already been clicked
    if (tile->is_open)
        return;

    tile->is_open = true;

    // Offsets for each of the 8 tiles around
    int c = board->cols;
    int surround_offsets[TILES_AROUND] = {-c - 1, -c,    -c + 1, -1,
                                          1,      c - 1, c,      c + 1};

    // If no bombs around
    if (tile->bombs_around == 0) {
        for (int i = 0; i < TILES_AROUND; i++) {
            _updateNeighborTiles(board, index + surround_offsets[i]);
        }
    }
}

bool handleBoardClick(Board *board, int row, int col) {
    int index = calcIndexFromPosition(row, col, board->cols);

    // Tile Index out of bounds
    if (index < 0 || index >= board->array_size)
        return false;

    // Get the pointer to the tile at that index
    Tile *tile = board->tile_array + index;

    _updateNeighborTiles(board, index);

    return tile->is_bomb;
}

Board *createBoard(int width, int height) {
    Board *new_board = malloc(sizeof(Board));
    int size = width * height;
    new_board->array_size = size;
    new_board->cols = height;
    new_board->rows = width;

    new_board->tile_array = createTileArray(size);
    initilizeTileArray(new_board->tile_array, size, width);
    new_board->click = handleBoardClick;

    return new_board;
}

void destroyBoard(Board *board) {
    destroyTileArray(board->tile_array);
    free(board);
}
