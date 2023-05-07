#include "assets_manager.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 200

/**
 * Unload all existing textures
 */
void _unload_textures(AssetManager *am);

/**
 * Duplicate a string onto the heap.
 */
char *_duplicate_string(char *string);

AssetManager *initAssetManager() {
    AssetManager *am = malloc(sizeof(AssetManager));
    am->textures_loaded = false;
    am->theme = NULL;
    return am;
}

char *_duplicate_string(char *string) {
    if (string == NULL)
        return NULL;

    int length = strlen(string);
    char *new = malloc(sizeof(char) * (length + 1));
    if (new == NULL)
        return NULL;

    for (int i = 0; i < length; i++) {
        new[i] = string[i];
    }

    new[length] = '\0';
    return new;
}

void loadAllAssets(AssetManager *assets, char *theme) {
    if (assets->textures_loaded) {
        // if the current theme is loaded, do nothing
        if (strcmp(theme, assets->theme) == 0) {
            return;
        }

        _unload_textures(assets);
    }

    char *theme_cpy = _duplicate_string(theme);
    assets->theme = theme_cpy;

    char buffer[BUF_SIZE];

    snprintf(buffer, BUF_SIZE, "assets/themes/%s/%s.png", theme, "tile-1");
    assets->tile_1 = LoadTexture(buffer);

    snprintf(buffer, BUF_SIZE, "assets/themes/%s/%s.png", theme, "tile-2");
    assets->tile_2 = LoadTexture(buffer);

    snprintf(buffer, BUF_SIZE, "assets/themes/%s/%s.png", theme, "tile-3");
    assets->tile_3 = LoadTexture(buffer);

    snprintf(buffer, BUF_SIZE, "assets/themes/%s/%s.png", theme, "tile-4");
    assets->tile_4 = LoadTexture(buffer);

    snprintf(buffer, BUF_SIZE, "assets/themes/%s/%s.png", theme, "tile-5");
    assets->tile_5 = LoadTexture(buffer);

    snprintf(buffer, BUF_SIZE, "assets/themes/%s/%s.png", theme, "tile-6");
    assets->tile_6 = LoadTexture(buffer);

    snprintf(buffer, BUF_SIZE, "assets/themes/%s/%s.png", theme, "tile-7");
    assets->tile_7 = LoadTexture(buffer);

    snprintf(buffer, BUF_SIZE, "assets/themes/%s/%s.png", theme, "tile-8");
    assets->tile_8 = LoadTexture(buffer);

    snprintf(buffer, BUF_SIZE, "assets/themes/%s/%s.png", theme, "tile-opened");
    assets->tile_opened = LoadTexture(buffer);

    snprintf(buffer, BUF_SIZE, "assets/themes/%s/%s.png", theme, "tile-closed");
    assets->tile_closed = LoadTexture(buffer);

    snprintf(buffer, BUF_SIZE, "assets/themes/%s/%s.png", theme, "tile-flag");
    assets->tile_flag = LoadTexture(buffer);

    snprintf(buffer, BUF_SIZE, "assets/themes/%s/%s.png", theme, "tile-bomb");
    assets->tile_bomb = LoadTexture(buffer);

    assets->textures_loaded = true;
}

void _unload_textures(AssetManager *am) {
    if (!am->textures_loaded)
        return;

    UnloadTexture(am->tile_closed);
    UnloadTexture(am->tile_opened);
    UnloadTexture(am->tile_bomb);
    UnloadTexture(am->tile_flag);
    UnloadTexture(am->tile_1);
    UnloadTexture(am->tile_2);
    UnloadTexture(am->tile_3);
    UnloadTexture(am->tile_4);
    UnloadTexture(am->tile_5);
    UnloadTexture(am->tile_6);
    UnloadTexture(am->tile_7);
    UnloadTexture(am->tile_8);

    am->textures_loaded = true;
}

void destroyAssetManager(AssetManager *assets) {
    _unload_textures(assets);
    free(assets->theme);
    free(assets);
}
