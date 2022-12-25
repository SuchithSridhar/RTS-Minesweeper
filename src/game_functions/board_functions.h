#ifndef BOARD_FUNCTIONS_H
#define BOARD_FUNCTIONS_H

#include <stdlib.h>
#include <stdbool.h>
#include "game_structs.h"


/* struct used to return position given an index. */
struct positionFromIndex {
    int x;
    int y;
};


/**
 * A utility function to calculate position given an index.
 * @index the index in the 1D array.
 * @width the width of the grid.
 * @return a struct that contains the x and y positions.
 */
struct positionFromIndex calcPositionFromIndex (int index, int width);


/**
 * Calculate index from a given x y position.
 * @param x the x position on the grid.
 * @param y the y position on the grid.
 * @param width the width of the grid.
 * @return the index that corresponds to the position.
 */
int calcIndexFromPosition (int x, int y, int width);


/**
 * Malloc space for a Tile struct.
 * @return a pointer to allocated space on the heap.
 */
Tile* createTile ();


/**
 * Initilize a Tile struct with the given values and some defaults.
 * @param tile A pointer to the tile to initilize.
 * @param x The x position of the tile.
 * @param y The y position of the tile.
 * @param is_bomb true if tile is a bomb.
 */
void initilizeTile (Tile *tile, int x, int y, bool is_bomb);


/**
 * Destroy the Tile that has been allocated on the heap.
 * @param tile A pointer to the tile to be destroyed.
 */
void destroyTile (Tile *tile);


/**
 * Allocate space for a tile array on the heap.
 * @param size The size of the tile array to allocate.
 * @return a pointer to the start of the tile array.
 */
Tile* createTileArray (int size);


/**
 * Initilize all the tiles in a tile array with
 * some default values.
 * @param tile_array a pointer to the start of the tile array.
 * @param size The size of the array.
 * @param width The width of the board the tile array represents.
 */
void initilizeTileArray (Tile *tile_array, int size, int width);


/**
 * Free memory associated with the tile array.
 * @param tile_array The array to be freed.
 */
void destroyTileArray (Tile *tile_array);


/**
 * Create and initilize a board with some tiles.
 * @param width the width of the board to create.
 * @param height the height of the board to create.
 * @return a pointer to the board allocated on the heap.
 */
Board* createBoard (int width, int height);


/**
 * Destroy a board struct that's been allocated on the heap.
 * @param board A pointer to the board to destroy.
 */
void destroyBoard (Board *board);


#endif
