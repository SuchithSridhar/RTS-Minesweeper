#include <stdlib.h>
#include <stdio.h>
#include "../../include/raylib.h"

#include "start.h"
#include "resize.h"


void updateBounds(MenusBundle *menu_bundle, int *screen_width, int *screen_height){
    setMenuBounds(menu_bundle->menu, screen_width, screen_height);
    setSettingsBounds(menu_bundle->settings, screen_width, screen_height);
    setStartGameBounds(menu_bundle->start_settings, screen_width, screen_height);
    setStatsBounds(menu_bundle->statistics, screen_width, screen_height);
}