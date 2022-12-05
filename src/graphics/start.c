#include <stdlib.h>
#include "../../include/raylib.h"
#include "../../include/raymath.h"

#include "tmp_structs.h"
#include "start.h"
#include "constants.h"

void initStartMenu(Menu *menu, int screen_width, int screen_height){
    menu->menu_button_array= (MenuButton*)malloc(sizeof(MenuButton)*NUM_MENU_BUTTONS);
    menu->title = GAME_TITLE;
    menu->menu_button_array[0].text=START_BUTTON_TITLE;
    menu->menu_button_array[1].text=SETTINGS_BUTTON_TITLE;
    menu->menu_button_array[2].text=STATS_BUTTON_TITLE;
    menu->menu_button_array[3].text=QUIT_BUTTON_TITLE;
    for(int i=0; i<NUM_MENU_BUTTONS;i++){
        menu->menu_button_array[i].button_width =((float)screen_width/5);
        menu->menu_button_array[i].button_height = ((float)screen_height/10);
    }
    menu->button_mouse_over=0;
    setMenuBounds(menu,screen_width,screen_height);
}

void initStartGameSettings(StartSettings *start_settings, int screen_width, int screen_height){
    start_settings->menu_button_array= (MenuButton*)malloc(sizeof(MenuButton)*NUM_SETTINGS_BUTTONS);
    start_settings->menu_button_array[0].text=BACK_BUTTON_TITLE;
    start_settings->menu_button_array[1].text=START_BUTTON_TITLE;
    for(int i=0; i<NUM_SETTINGS_BUTTONS;i++){
        start_settings->menu_button_array[i].button_width =((float)screen_width/5);
        start_settings->menu_button_array[i].button_height = ((float)screen_height/10);
    }
    start_settings->button_mouse_over=0;
    setStartGameBounds(start_settings,screen_width,screen_height);
}

void initSettings(Settings *settings, int screen_width, int screen_height){
    settings->menu_button_array= (MenuButton*)malloc(sizeof(MenuButton)*NUM_SETTINGS_BUTTONS);
    settings->menu_button_array[0].text=BACK_BUTTON_TITLE;
    settings->menu_button_array[1].text="APPLY";
    for(int i=0; i<NUM_SETTINGS_BUTTONS;i++){
        settings->menu_button_array[i].button_width =((float)screen_width/5);
        settings->menu_button_array[i].button_height = ((float)screen_height/10);
    }
    settings->button_mouse_over=0;
    setSettingsBounds(settings,screen_width,screen_height);
}

void initStatistics(Statistics *statistics, int screen_width, int screen_height){
    statistics->menu_button_array= (MenuButton*)malloc(sizeof(MenuButton));
    statistics->menu_button_array[0].text=BACK_BUTTON_TITLE;
    statistics->menu_button_array[0].button_width =((float)screen_width/5);
    statistics->menu_button_array[0].button_height = ((float)screen_height/10);
    statistics->button_mouse_over=0;
    setStatsBounds(statistics,screen_width,screen_height);
}


void setMenuBounds(Menu *menu,double width,double height){
    Rectangle start_bounds = {(width/2.0f-menu->menu_button_array[0].button_width/2.0f),height/4.0f,menu->menu_button_array[0].button_width,
    menu->menu_button_array[0].button_height};
    Rectangle settings_bounds = {(width/2.0f-menu->menu_button_array[1].button_width/2.0f),(height/2.0f - menu->menu_button_array[1].button_height/2.0f)/NUM_MENU_BUTTONS 
    +height/4.0f, menu->menu_button_array[1].button_width,menu->menu_button_array[1].button_height};
    Rectangle statistics_bounds = {(width/2.0f-menu->menu_button_array[2].button_width/2.0f),2*(height/2.0f-menu->menu_button_array[2].button_height/2.0f)/NUM_MENU_BUTTONS +height/4.0f,
    menu->menu_button_array[2].button_width,menu->menu_button_array[2].button_height};
    Rectangle exit_bounds = {(width/2.0f-menu->menu_button_array[3].button_width/2.0f),
    3*(height/2.0f - menu->menu_button_array[3].button_height/2.0f)/NUM_MENU_BUTTONS + height/4.0f,menu->menu_button_array[3].button_width,menu->menu_button_array[3].button_height};
    
    menu->menu_button_array[0].bounds=start_bounds;
    menu->menu_button_array[1].bounds=settings_bounds;
    menu->menu_button_array[2].bounds=statistics_bounds;
    menu->menu_button_array[3].bounds=exit_bounds;
}
void setStartGameBounds(StartSettings *start_settings,double width,double height){
    Vector2 position;
    position.x = (width/2.0f-width/4.0f);
    position.y = (height/2.0f-height/3.5f);
    //Assumes button width and height are the same
    float button_width= start_settings->menu_button_array[0].button_width;
    float button_height= start_settings->menu_button_array[0].button_height;

    Rectangle back_bounds={position.x+button_width/7.0f,(position.y+height/1.5f)-button_height-button_height/7.0f,button_width,button_height};
    Rectangle start_game_bounds= {(position.x+width/2.0f)-button_width-button_width/7.0f,(position.y+height/1.5f)-button_height-button_height/7.0f,button_width,button_height};

    start_settings->menu_button_array[0].bounds=back_bounds;
    start_settings->menu_button_array[1].bounds=start_game_bounds;
}

void setSettingsBounds(Settings *settings,double width,double height){
    
    Vector2 position;
    position.x = (width/2.0f-width/4.0f);
    position.y = (height/2.0f-height/3.5f);
    //Assumes button width and height are the same
    float button_width= settings->menu_button_array[0].button_width;
    float button_height= settings->menu_button_array[0].button_height;

    Rectangle back_bounds={position.x+button_width/7.0f,(position.y+height/1.5f)-button_height-button_height/7.0f,button_width,button_height};
    Rectangle apply_bounds= {(position.x+width/2.0f)-button_width-button_width/7.0f,(position.y+height/1.5f)-button_height-button_height/7.0f,button_width,button_height};

    settings->menu_button_array[0].bounds=back_bounds;
    settings->menu_button_array[1].bounds=apply_bounds;
}

void setStatsBounds(Statistics *stats,double width,double height){
    Vector2 position;
    position.x = (width/2.0f-width/4.0f);
    position.y = (height/2.0f-height/3.5f);
    Rectangle back_bounds={position.x+width/4.0f -stats->menu_button_array[0].button_width/2.0f,
    (position.y+height/1.5f)-stats->menu_button_array[0].button_height-stats->menu_button_array[0].button_height/7.0f,
    stats->menu_button_array[0].button_width,stats->menu_button_array[0].button_height};
    stats->menu_button_array[0].bounds=back_bounds;
}
void drawStartMenu(Menu *menu,double width, double height){
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
void drawStartGameSettings(StartSettings *start_settings,double width, double height){
    Vector2 position;
    position.x = (width/2.0f-width/4.0f);
    position.y = (height/2.0f-height/3.5f);
    DrawRectangle(position.x,position.y,width/2.0f,height/1.5f,BLACK);
    DrawRectangleRec(start_settings->menu_button_array[0].bounds,BLACK);
    DrawRectangleRec(start_settings->menu_button_array[1].bounds,BLACK);

    DrawText(start_settings->menu_button_array[0].text,
    start_settings->menu_button_array[0].bounds.x+start_settings->menu_button_array[0].bounds.width/2.0f-MeasureText(start_settings->menu_button_array[0].text,FONT_SIZE_BUT)/2.0f,
    start_settings->menu_button_array[0].bounds.y+start_settings->menu_button_array[0].bounds.height/2.0f,FONT_SIZE_BUT,RAYWHITE);
    
    DrawText(start_settings->menu_button_array[1].text,
    start_settings->menu_button_array[1].bounds.x+start_settings->menu_button_array[1].bounds.width/2.0f-MeasureText(start_settings->menu_button_array[1].text,FONT_SIZE_BUT)/2.0f,
    start_settings->menu_button_array[1].bounds.y+start_settings->menu_button_array[1].bounds.height/2.0f,FONT_SIZE_BUT,RAYWHITE);
}

void drawSettings(Settings *settings,double width, double height){
    Vector2 position;
    position.x = (width/2.0f-width/4.0f);
    position.y = (height/2.0f-height/3.5f);
    DrawRectangle(position.x,position.y,width/2.0f,height/1.5f,BLACK);
    DrawRectangleRec(settings->menu_button_array[0].bounds,BLACK);
    DrawRectangleRec(settings->menu_button_array[1].bounds,BLACK);
    DrawText(settings->menu_button_array[0].text,
    settings->menu_button_array[0].bounds.x+settings->menu_button_array[0].bounds.width/2.0f-MeasureText(settings->menu_button_array[0].text,FONT_SIZE_BUT)/2.0f,
    settings->menu_button_array[0].bounds.y+settings->menu_button_array[0].bounds.height/2.0f,FONT_SIZE_BUT,RAYWHITE);
    
    DrawText(settings->menu_button_array[1].text,
    settings->menu_button_array[1].bounds.x+settings->menu_button_array[1].bounds.width/2.0f-MeasureText(settings->menu_button_array[1].text,FONT_SIZE_BUT)/2.0f,
    settings->menu_button_array[1].bounds.y+settings->menu_button_array[1].bounds.height/2.0f,FONT_SIZE_BUT,RAYWHITE);
}

void drawStatistics(Statistics *stats,double width, double height){
    Vector2 position;
    position.x = (width/2.0f-width/4.0f);
    position.y = (height/2.0f-height/3.5f);
    DrawRectangle(position.x,position.y,width/2.0f,height/1.5f,BLACK);
    DrawRectangleRec(stats->menu_button_array[0].bounds,BLACK);
    DrawText(stats->menu_button_array[0].text,stats->menu_button_array[0].bounds.x+stats->menu_button_array[0].bounds.width/2.0f-MeasureText(stats->menu_button_array[0].text,FONT_SIZE_BUT)/2.0f,
    stats->menu_button_array[0].bounds.y+stats->menu_button_array[0].bounds.height/2.0f,FONT_SIZE_BUT,WHITE);

}
void exitGame(){
    EndDrawing();
    CloseWindow();
    exit(0);
}
void mouseHoverButton(MenuButton *button){
    DrawRectangleRec(button->bounds,DARKGRAY);
    Vector2 text_position;
    text_position.x = button->bounds.x
    +(button->bounds.width/2)-((float)MeasureText(button->text,FONT_SIZE_BUT))/2.0f;
    text_position.y = button->bounds.y+(button->bounds.height/2.0f);
    DrawText(button->text,text_position.x,text_position.y,FONT_SIZE_BUT,YELLOW);
}
void startHover(Vector2 *mp,Menu *menu){
    if((CheckCollisionPointRec(*mp,menu->menu_button_array[0].bounds)
    ||CheckCollisionPointRec(*mp,menu->menu_button_array[1].bounds)
    ||CheckCollisionPointRec(*mp,menu->menu_button_array[2].bounds)
    ||CheckCollisionPointRec(*mp,menu->menu_button_array[3].bounds))){
        if((CheckCollisionPointRec(*mp,menu->menu_button_array[0].bounds))){
            mouseHoverButton(&menu->menu_button_array[0]);
            menu->button_mouse_over=1;
        }
        else if(CheckCollisionPointRec(*mp,menu->menu_button_array[1].bounds)){
            mouseHoverButton(&menu->menu_button_array[1]);
            menu->button_mouse_over=2;
        }
        else if(CheckCollisionPointRec(*mp,menu->menu_button_array[2].bounds)){
            mouseHoverButton(&menu->menu_button_array[2]);
            menu->button_mouse_over=3;
        }
        else{
            mouseHoverButton(&menu->menu_button_array[3]);
            menu->button_mouse_over=4;
        }
    }
}

void startSettingsHover(Vector2 *mp,StartSettings *start_settings){
    if(CheckCollisionPointRec(*mp,start_settings->menu_button_array[0].bounds)||CheckCollisionPointRec(*mp,start_settings->menu_button_array[1].bounds)){
        if((CheckCollisionPointRec(*mp,start_settings->menu_button_array[0].bounds))){
            mouseHoverButton(&start_settings->menu_button_array[0]);
            start_settings->button_mouse_over=1;
        }
        else{
            mouseHoverButton(&start_settings->menu_button_array[1]);
            start_settings->button_mouse_over=2;
        }
    }
}

void settingsHover(Vector2 *mp,Settings *settings){
    if(CheckCollisionPointRec(*mp,settings->menu_button_array[0].bounds)||CheckCollisionPointRec(*mp,settings->menu_button_array[1].bounds)){
        if((CheckCollisionPointRec(*mp,settings->menu_button_array[0].bounds))){
            mouseHoverButton(&settings->menu_button_array[0]);
            settings->button_mouse_over=1;
        }
        else{
            mouseHoverButton(&settings->menu_button_array[1]);
            settings->button_mouse_over=2;
        }
    }
}

void statisticsHover(Vector2 *mp, Statistics *statistics){
    if(CheckCollisionPointRec(*mp,statistics->menu_button_array[0].bounds)){
        mouseHoverButton(&statistics->menu_button_array[0]);
        statistics->button_mouse_over=1;
    }   
}
void menuClick(Menu *menu,int *state){
    switch (menu->button_mouse_over){
        case(1):
            *state=1;
            break;
        case(2):
            *state=3;
            break;
        case(3):
            *state=4;
            break;
        case(4):
            *state=5;
            break;
        default:
            break;
    }
}
void startGameClick(StartSettings *start_settings, int *state){
    switch (start_settings->button_mouse_over){
        case(1):
            *state=0;
            break;
        case(2):
            *state=2;
            break;
        default:
            break;
    }
}

void settingsClick(Settings *settings,int *state){
    switch (settings->button_mouse_over){
        case(1):
            *state=0;
            break;
        case(2):
            *state=3;
            break;
        default:
            break;
    }
}

void statsClick(int *state){
    *state=0;
}