#include "board_functions.h"
#include <stdbool.h>
#include <stdlib.h>

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

bool handleBoardClick(Board *board, int row, int col) {
    int index = calcIndexFromPosition(row, col, board->cols);
    // Get the pointer to the tile at that index
    Tile *tile = board->tile_array + index;

    tile->is_open = true;
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
