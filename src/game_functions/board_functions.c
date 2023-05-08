#include "board_functions.h"
#include "constants.h"
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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
    new_board->game_start = false;

    new_board->tile_array = createTileArray(size);
    initilizeTileArray(new_board->tile_array, size, width);
    new_board->click = handleBoardClick;

    return new_board;
}

void destroyBoard(Board *board) {
    destroyTileArray(board->tile_array);
    free(board);
}


void generateBoard(BoardGui *bg, int selected_tile_index){
    openInitialTiles(bg->board, selected_tile_index);
    placeBombs(bg,bg->size * DEFAULT_CLUSTER_FACTOR);
    bg->board->game_start = true;
}


void openInitialTiles(Board *board, int selected_tile_index){

    struct positionFromIndex position = calcPositionFromIndex(selected_tile_index, board->rows);
    board->click(board, position.row, position.col);

    if(position.row < board->rows - 1)
        board->click(board, position.row + 1, position.col);

    if(position.row > 0)
        board->click(board, position.row-1, position.col);

    if(position.col < board->cols - 1)
        board->click(board, position.row, position.col + 1);
        

    if(position.col > 0)
        board->click(board, position.row, position.col - 1);

}


void placeBombs(BoardGui *bg, double clusterVarSD){
    double average_x = (double) bg->size / 2 + bg->x_offset;
    double average_y = (double) bg->size / 2 + bg->y_offset;
    int size = 1;
    int num_bombs = DEFAULT_NUM_BOMBS;
    double x_cord;
    double y_cord;
    double U1;
    double U2;
    int tile_width = (bg->size) / bg->board->cols;
    int row;
    int col;
    int index;
    srand(time(NULL));
    while(num_bombs != 0){
        U1 = (double) rand() / (double) RAND_MAX;
        U2 = (double) rand() / (double) RAND_MAX;
        x_cord = sqrt(-2 * log(U1)) * cos(2 * PI * U2);
        y_cord = sqrt(-2 * log(U1)) * sin(2 * PI * U2);
        
        x_cord = x_cord * clusterVarSD + average_x;
        y_cord = y_cord * clusterVarSD + average_x;
        if(x_cord <= bg->x_offset || x_cord > bg->size + bg->x_offset || y_cord <= bg->y_offset || y_cord > bg->size + bg->y_offset)
            continue;  
        row = x_cord / tile_width;
        col = y_cord / tile_width;
        index = calcIndexFromPosition(row, col, bg->board->cols);
        if(bg->board->tile_array[index].is_open || bg->board->tile_array[index].is_bomb){
            continue;
        }
        bg->board->tile_array[index].is_bomb = true;
        num_bombs--;
    }
}
