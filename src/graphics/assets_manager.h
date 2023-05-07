#ifndef ASSETS_MANAGER_H
#define ASSETS_MANAGER_H

#include "../../include/raylib.h"

#include <stdbool.h>

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
    Texture2D tile_6;
    Texture2D tile_7;
    Texture2D tile_8;
    char *theme;
    bool textures_loaded;
} AssetManager;

/**
 * Create and initialize the AssetManager struct on the heap.
 * @return A pointer to the allocated AssetManager.
 */
AssetManager *initAssetManager();

/**
 * Load textures for a particular theme into the asset manager.
 * @param asset_manager the AssetManager to load the textures into.
 * @param theme the theme that is to be loaded.
 */
void loadAllAssets(AssetManager *asset_manager, char *theme);

/**
 * Destroy the asset manager and unload all the themes.
 * @param assets the AssetManager to destory.
 */
void destroyAssetManager(AssetManager *assets);

#endif
