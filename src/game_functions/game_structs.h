#ifndef GAME_STRUCTS_H
#define GAME_STRUCTS_H

#include <stdbool.h>

/* Holds data for single tile on the board. */
typedef struct {
    /* row position of tile. */
    int row;
    /* col position of tile. */
    int col;

    int bombs_around;
    bool is_bomb;
    bool is_flagged;
    bool is_open;

} Tile;

/* Hold data about the minesweeper board. */
typedef struct Board {
    /* Holds the array of tiles. Represents a 2D grid. */
    Tile *tile_array;

    /*
     * function to be called when tile clicked.
     * Returns true if game ends.
     */
    bool (*click)(struct Board *, int, int);

    int rows;
    int cols;

    /* Size of tile array. */
    int array_size;
} Board;

#endif
