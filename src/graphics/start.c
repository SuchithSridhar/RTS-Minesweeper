#include <stdlib.h>
#include "../../include/raylib.h"
#include "../../include/raymath.h"

#include "tmp_structs.h"
#include "start.h"
#include "constants.h"

void DrawStartMenu(Menu *menu,double width, double height){
    for(int i=0; i<NUM_MENU_BUTTONS;i++){
        Vector2 position;
        position.x =menu->menu_button_array[i].bounds.x;
        position.y =menu->menu_button_array[i].bounds.y;
        Vector2 text_position;
        text_position.x = position.x+(menu->menu_button_array[i].button_width/2.0f)-((float)MeasureText(menu->menu_button_array[i].text,FONT_SIZE_BUT))/2.0f;
        text_position.y= position.y+(menu->menu_button_array[i].button_height/2.0f);
        DrawRectangleRec(menu->menu_button_array[i].bounds,BLACK);
        DrawText(menu->menu_button_array[i].text,text_position.x,text_position.y,FONT_SIZE_BUT,RAYWHITE);
        
    }
    Vector2 title_position;
    title_position.x = width/2-((float)MeasureText(menu->title,FONT_SIZE_TITLE))/2;
    title_position.y = height/10;
    DrawText(menu->title,title_position.x,title_position.y,FONT_SIZE_TITLE,BLACK);
}