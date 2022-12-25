#ifndef GAME_STRUCTS_H
#define GAME_STRUCTS_H

/* Holds data for single tile on the board. */
typedef struct {
    /* x position of tile. */
    int x;
    /* y position of tile. */
    int y;

    int bombs_around;
    bool is_bomb;
    bool is_flagged;
    bool is_open;

} Tile;

/* Hold data about the minesweeper board. */
typedef struct Board {
    int height;
    int width;

    /* Size of tile array. */
    int array_size;

    /* Holds the array of tiles. Represents a 2D grid. */
    Tile *tile_array;

    /* 
     * function to be called when tile clicked.
     * Returns true if game ends.
     */
    bool (*click) (struct Board*, int, int);
} Board;

#endif
