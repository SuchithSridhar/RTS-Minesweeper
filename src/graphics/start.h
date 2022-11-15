#ifndef START_H
#define START_H

#include "../../include/raylib.h"

#include "tmp_structs.h"

void DrawStartMenu(Menu *menu,double width,double height);

void SetMenuBounds(Menu *menu,double width,double height);

void MenuClick(Menu *menu,int *state);

#endif