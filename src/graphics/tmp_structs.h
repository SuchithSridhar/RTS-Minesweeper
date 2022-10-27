#ifndef TMP_STRUCTS_H
#define TMP_STRUCTS_H

#include "../include/raylib.h"

typedef struct Tile {
    int bombs_around; // [0, 8]
    bool is_bomb;
    bool is_flagged;
    bool is_open;
} Tile;

// TODO: Declare in a separate file
typedef struct Board {
    Tile *tile_array;
    int cols;
    int rows;
    void (*click) (struct Board*, int, int);
    // There should be a function called "clicked"
    // which would be called when a tile has been clicked.
} Board;

// Declaring this on the heap would be a good idea.
typedef struct AssetManager {

    Texture2D tile_closed;
    Texture2D tile_opened;
    Texture2D tile_bomb;
    Texture2D tile_flag;
    Texture2D tile_1;
    Texture2D tile_2;
    Texture2D tile_3;
    Texture2D tile_4;
    Texture2D tile_5;

} AssetManager;

#endif
