#ifndef TMP_STRUCTS_H
#define TMP_STRUCTS_H

#include "../include/raylib.h"

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
