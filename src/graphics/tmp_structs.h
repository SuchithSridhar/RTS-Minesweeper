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
#endif
