#ifndef TMP_STRUCTS_H
#define TMP_STRUCTS_H

#include "../include/raylib.h"

typedef struct Tile {
    int pos_x;
    int pos_y;
    int bombs_around; // [0, 8]
    bool is_bomb;
    bool is_flagged;
} Tile;

// TODO: Declare in a separate file
typedef struct Board {
    Tile *tile_array;
    int cols;
    int rows;
    // There should be a function called "clicked"
    // which would be called when a tile has been clicked.
} Board;

// Declaring this on the heap would be a good idea.
typedef struct AssetManager {
    Texture2D tile;
} AssetManager;

#endif
