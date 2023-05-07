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

AssetManager *initAssetManager();
void loadAllAssets(AssetManager *asset_manager, char *theme);
void destroyAssetManager(AssetManager *assets);

#endif
