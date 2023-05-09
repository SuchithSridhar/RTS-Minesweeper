#ifndef BOARD_FUNCTIONS_H
#define BOARD_FUNCTIONS_H

#include "game_structs.h"
#include "../graphics/gameplay/board.h"
#include <stdbool.h>
#include <stdlib.h>

/* struct used to return position given an index. */
struct positionFromIndex {
    int row;
    int col;
};

/**
 * A utility function to calculate position given an index.
 * @index the index in the 1D array.
 * @width the width of the grid.
 * @return a struct that contains the x and y positions.
 */
struct positionFromIndex calcPositionFromIndex(int index, int width);

/**
 * Calculate index from a given x y position.
 * @param row the row position on the grid.
 * @param col the column position on the grid.
 * @param width the width of the grid.
 * @return the index that corresponds to the position.
 */
int calcIndexFromPosition(int row, int col, int width);

/**
 * Malloc space for a Tile struct.
 * @return a pointer to allocated space on the heap.
 */
Tile *createTile();

/**
 * Initialize a Tile struct with the given values and some defaults.
 * @param tile A pointer to the tile to initialize.
 * @param row The row position of the tile.
 * @param col The column position of the tile.
 * @param is_bomb true if tile is a bomb.
 */
void initilizeTile(Tile *tile, int row, int column, bool is_bomb);

/**
 * Destroy the Tile that has been allocated on the heap.
 * @param tile A pointer to the tile to be destroyed.
 */
void destroyTile(Tile *tile);

/**
 * Allocate space for a tile array on the heap.
 * @param size The size of the tile array to allocate.
 * @return a pointer to the start of the tile array.
 */
Tile *createTileArray(int size);

/**
 * Initialize all the tiles in a tile array with
 * some default values.
 * @param tile_array a pointer to the start of the tile array.
 * @param size The size of the array.
 * @param width The width of the board the tile array represents.
 */
void initilizeTileArray(Tile *tile_array, int size, int width);

/**
 * Free memory associated with the tile array.
 * @param tile_array The array to be freed.
 */
void destroyTileArray(Tile *tile_array);

/**
 * Create and initialize a board with some tiles.
 * @param width the width of the board to create.
 * @param height the height of the board to create.
 * @return a pointer to the board allocated on the heap.
 */
Board *createBoard(int width, int height);

/**
 * Destroy a board struct that's been allocated on the heap.
 * @param board A pointer to the board to destroy.
 */
void destroyBoard(Board *board);

/**
 * Upon first clicking the board, the generate board function clears an area for the player, 
 * generates a certain number of bombs and updates the tiles around the bombs
 * @param bg A BoardGui struct, which is used to start the game
 * @param selected_tile_index an int representing the index of the tile which has been clicked
*/
void generateBoard(BoardGui *bg, int selected_tile_index);

/**
 * The openInitialTiles function opens the initial space for the player
 * @param board A Board struct which is used to access the tile array to determine which tiles to open
 * @param selected_tile_index an int representing the index of the tile which has been clicked
*/
void openInitialTiles(Board *board, int selected_tile_index);
/**
 * The placeBombs function generates a certain number of bombs for the board to use. The function achieves this by using the Box-Muller transformation
 * to achieve a gaussian distribution. This distribution can be altered by increasing or decreasing the clusterVarSD double variable
 * @param bg A BoardGui struct, which is for the positioning and size of the board
 * @param cluster_var_SD A double value representing the standard deviation of the gaussian distribution. Can be used as a sort of "cluster variable"
 * where lower values are more clustered (Does not work for extremely low values)
*/
void placeBombs(BoardGui *bg, double cluster_var_SD);
/**
 * Updates the tile values around a specific bomb index
 * @param board A Board struct which is used to access the tile array to determine which tiles to update
 * @param bomb_index an int representing the index of the tile which holds a bomb
 * 
*/
void updateTileValues(Board *board, int bomb_index); 


#endif
