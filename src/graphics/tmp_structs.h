#ifndef TMP_STRUCTS_H
#define TMP_STRUCTS_H

#include "../../include/raylib.h"
typedef struct MenuButton{
    char *text;
    float button_width;
    float button_height;
    Rectangle bounds;
} MenuButton;

typedef struct Menu{
    Font (*TitleFont)(char*);
    char *title;
    MenuButton *menu_button_array;
    int button_hover;
} Menu;
typedef struct Statistics{
    MenuButton *menu_button_array;
    int button_hover;
} Statistics;
typedef struct Settings{
    MenuButton *menu_button_array;
    int button_hover;
} Settings;
typedef struct StartSettings{
    MenuButton *menu_button_array;
    int button_hover;
} StartSettings;
#endif
