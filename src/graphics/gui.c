#include <stdlib.h>

#include "raylib.h"
#include "raymath.h"

#include "gameplay.h"
#include "tmp_structs.h"

#include "constants.h"
#include "gui.h"
#include "menu.h"
#include "start.h"
#include "state.h"

int screen_width = INITIAL_SCREEN_WIDTH;
int screen_height = INITIAL_SCREEN_HEIGHT;
char title[] = GAME_TITLE;
int state = STATE_START;

void runGameGui() {

    MenusBundle *menu_bundle = initMenusBundle(&screen_width, &screen_height);
    GameplayData *gameplay_data = NULL;

    InitWindow(screen_width, screen_height, title);
    Vector2 mouse_position = {0.0f, 0.0f};
    SetTargetFPS(60);

    // TODO: Move to a different file.
    AssetManager *assets = (AssetManager *)malloc(sizeof(AssetManager));
    assets->tile_1 = LoadTexture("assets/themes/playful/tile-1.png");
    assets->tile_2 = LoadTexture("assets/themes/playful/tile-2.png");
    assets->tile_3 = LoadTexture("assets/themes/playful/tile-3.png");
    assets->tile_4 = LoadTexture("assets/themes/playful/tile-4.png");
    assets->tile_5 = LoadTexture("assets/themes/playful/tile-5.png");
    assets->tile_opened = LoadTexture("assets/themes/playful/tile-opened.png");
    assets->tile_closed = LoadTexture("assets/themes/playful/tile-closed.png");
    assets->tile_flag = LoadTexture("assets/themes/playful/tile-flag.png");
    assets->tile_bomb = LoadTexture("assets/themes/playful/tile-bomb.png");

    while (!WindowShouldClose() && state != STATE_EXIT) {

        handleStateClicks(menu_bundle, &mouse_position, &state);

        // Pre-drawing operations based on current state.
        switch (state) {
        case STATE_GAMEPLAY:
            handleGameplayActions(gameplay_data, &mouse_position, screen_width,
                                  screen_height);
            break;
        case STATE_TRANSITION_GAMEPLAY:
            gameplay_data = initGameplay(assets);
            state = STATE_GAMEPLAY;
        default:
            // TODO: Add an error message.
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        handleGUIDraw(menu_bundle, &mouse_position, &state, &screen_width,
                      &screen_height);

        // Handles drawing based on current state.
        switch (state) {
        case STATE_GAMEPLAY:
            handleGameplayDraw(gameplay_data, screen_width, screen_height);
        default:
            // TODO: Add an error message.
            break;
        }
        EndDrawing();
    }
    freeMenusBundle(menu_bundle);

    // TODO: Move to a different file.
    free(assets);
    CloseWindow();
}
