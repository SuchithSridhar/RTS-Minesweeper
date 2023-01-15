#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "raylib.h"

#include "../game_functions/game_structs.h"
#include "tmp_structs.h"


typedef struct {
    Board *board;
    AssetManager *assets;
} GameplayData;


/**
 * Initialize the minesweeper game and return a pointer to
 * the GameplayData. This allocates memory on the heap for
 * the struct. Ensure that endGameplay is called.
 * @param asserts AssetManager struct to access loaded assets.
 * @return a pointer to the GameplayData struct on heap.
 */
GameplayData* initGameplay(AssetManager *assets);


/**
 * End the current game and free all allocated memory for game.
 * @param gameplay_data GameplayData struct to store gameplay data.
 */
void endGameplay(GameplayData *gameplay_data);


/**
 * Handle all drawing related to STATE_GAMEPLAY.
 * @param gameplay_data GameplayData struct to store gameplay data.
 * @param screen_width represents the current width of the window.
 * @param screen_height represents the current height of the window.
 * @return An exit code for the function if necessary, returns 0 otherwise.
 */
int handleGameplayDraw(GameplayData *gameplay_data, double screen_width, double screen_height);


/**
 * Handle all mouse clicks related to STATE_GAMEPLAY.
 * @param gameplay_data GameplayData struct to store gameplay data.
 * @param screen_width represents the current width of the window.
 * @param screen_height represents the current height of the window.
 * @return An exit code for the function if necessary, returns 0 otherwise.
 */
int handleGameplayActions(GameplayData *gameplay_data, Vector2 *mouse_position, double screen_width, double screen_height);


#endif
