#include <stdlib.h>
#include "../../include/raylib.h"
#include "../../include/raymath.h"

#include "start.h"
#include "constants.h"
#include "state.h"

MenusBundle * initMenusBundle(int *screen_width, int *screen_height){
    MenusBundle *menu_bundle =(MenusBundle*) malloc(sizeof(menu_bundle));
    initStartMenu(menu_bundle,screen_width,screen_height);
    initStartGameSettings(menu_bundle,screen_width,screen_height);
    initSettings(menu_bundle,screen_width,screen_height);
    initStatistics(menu_bundle,screen_width,screen_height);
    return menu_bundle;
}

void initStartMenu(MenusBundle *menu_bundle, int *screen_width, int *screen_height){
    StartMenu *menu =(StartMenu*) malloc(sizeof(menu));
    menu_bundle->menu=menu;
    menu->menu_button_array= (MenuButton*)malloc(sizeof(MenuButton)*NUM_MENU_BUTTONS);
    menu->title = GAME_TITLE;
    menu->menu_button_array[START_BUTTON_INTEGER].text=START_BUTTON_TITLE;
    menu->menu_button_array[SETTINGS_BUTTON_INTEGER].text=SETTINGS_BUTTON_TITLE;
    menu->menu_button_array[STATS_BUTTON_INTEGER].text=STATS_BUTTON_TITLE;
    menu->menu_button_array[QUIT_BUTTON_INTEGER].text=QUIT_BUTTON_TITLE;
    for(int i=0; i<NUM_MENU_BUTTONS;i++){
        menu->menu_button_array[i].button_width =((float)*screen_width/5);
        menu->menu_button_array[i].button_height = ((float)*screen_height/10);
    }
    menu->button_mouse_over=0;
    setMenuBounds(menu,screen_width,screen_height);
}

void initStartGameSettings(MenusBundle *menu_bundle, int *screen_width, int *screen_height){
    StartSettings *start_settings =(StartSettings*) malloc(sizeof(start_settings));
    menu_bundle->start_settings=start_settings;
    start_settings->menu_button_array= (MenuButton*)malloc(sizeof(MenuButton)*NUM_SETTINGS_BUTTONS);
    start_settings->menu_button_array[BACK_BUTTON_INTEGER].text=BACK_BUTTON_TITLE;
    start_settings->menu_button_array[START_GAME_BUTTON_INTEGER].text=START_BUTTON_TITLE;
    for(int i=0; i<NUM_SETTINGS_BUTTONS;i++){
        start_settings->menu_button_array[i].button_width =((float)*screen_width/5);
        start_settings->menu_button_array[i].button_height = ((float)*screen_height/10);
    }
    start_settings->button_mouse_over=0;
    setStartGameBounds(start_settings,screen_width,screen_height);
}

void initSettings(MenusBundle *menu_bundle, int *screen_width, int *screen_height){
    Settings *settings =(Settings*) malloc(sizeof(settings));
    menu_bundle->settings=settings;
    settings->menu_button_array= (MenuButton*)malloc(sizeof(MenuButton)*NUM_SETTINGS_BUTTONS);
    settings->menu_button_array[BACK_BUTTON_INTEGER].text=BACK_BUTTON_TITLE;
    settings->menu_button_array[APPLY_BUTTON_INTEGER].text=APPLY_BUTTON_TITLE;
    for(int i=0; i<NUM_SETTINGS_BUTTONS;i++){
        settings->menu_button_array[i].button_width =((float)*screen_width/5);
        settings->menu_button_array[i].button_height = ((float)*screen_height/10);
    }
    settings->button_mouse_over=0;
    setSettingsBounds(settings,screen_width,screen_height);
}

void initStatistics(MenusBundle *menu_bundle, int *screen_width, int *screen_height){
    Statistics *statistics =(Statistics*) malloc(sizeof(statistics));
    menu_bundle->statistics=statistics;

    statistics->menu_button_array= (MenuButton*)malloc(sizeof(MenuButton));
    statistics->menu_button_array[BACK_BUTTON_INTEGER].text=BACK_BUTTON_TITLE;
    statistics->menu_button_array[BACK_BUTTON_INTEGER].button_width =((float)*screen_width/5);
    statistics->menu_button_array[BACK_BUTTON_INTEGER].button_height = ((float)*screen_height/10);
    statistics->button_mouse_over=0;
    setStatsBounds(statistics,screen_width,screen_height);
}
void freeMenusBundle(MenusBundle *menu_bundle){
    free(menu_bundle);
} 
void freeStartMenu(StartMenu *menu){
    free(menu->menu_button_array);
    free(menu);
} 
void freeStartGameSettings(StartSettings *start_settings){
    free(start_settings->menu_button_array);
    free(start_settings);
} 
void freeSettings(Settings *settings){
    free(settings->menu_button_array);
    free(settings);
} 
void freeStatistics(Statistics *statistics){
    free(statistics->menu_button_array);
    free(statistics);
} 

void setMenuBounds(StartMenu *menu,int *screen_width,int *screen_height){
    Rectangle start_bounds = {(*screen_width/2.0f-menu->menu_button_array[START_BUTTON_INTEGER].button_width/2.0f),
    *screen_height/4.0f,menu->menu_button_array[START_BUTTON_INTEGER].button_width,
    menu->menu_button_array[START_BUTTON_INTEGER].button_height};
    
    Rectangle settings_bounds = {(*screen_width/2.0f-menu->menu_button_array[SETTINGS_BUTTON_INTEGER].button_width/2.0f),
    (*screen_height/2.0f - menu->menu_button_array[SETTINGS_BUTTON_INTEGER].button_height/2.0f)/NUM_MENU_BUTTONS 
    +*screen_height/4.0f, menu->menu_button_array[SETTINGS_BUTTON_INTEGER].button_width,menu->menu_button_array[SETTINGS_BUTTON_INTEGER].button_height};
    
    Rectangle statistics_bounds = {(*screen_width/2.0f-menu->menu_button_array[STATS_BUTTON_INTEGER].button_width/2.0f),
    STATS_BUTTON_INTEGER*(*screen_height/2.0f-menu->menu_button_array[STATS_BUTTON_INTEGER].button_height/2.0f)/NUM_MENU_BUTTONS 
    +*screen_height/4.0f,menu->menu_button_array[STATS_BUTTON_INTEGER].button_width,menu->menu_button_array[STATS_BUTTON_INTEGER].button_height};
    
    Rectangle exit_bounds = {(*screen_width/2.0f-menu->menu_button_array[QUIT_BUTTON_INTEGER].button_width/2.0f),
    QUIT_BUTTON_INTEGER*(*screen_height/2.0f - menu->menu_button_array[QUIT_BUTTON_INTEGER].button_height/2.0f)/NUM_MENU_BUTTONS 
    + *screen_height/4.0f,menu->menu_button_array[QUIT_BUTTON_INTEGER].button_width,menu->menu_button_array[QUIT_BUTTON_INTEGER].button_height};
    
    menu->menu_button_array[START_BUTTON_INTEGER].bounds=start_bounds;
    menu->menu_button_array[SETTINGS_BUTTON_INTEGER].bounds=settings_bounds;
    menu->menu_button_array[STATS_BUTTON_INTEGER].bounds=statistics_bounds;
    menu->menu_button_array[QUIT_BUTTON_INTEGER].bounds=exit_bounds;
}
void setStartGameBounds(StartSettings *start_settings,int *screen_width,int *screen_height){
    Vector2 position;
    position.x = (*screen_width/2.0f-*screen_width/4.0f);
    position.y = (*screen_height/2.0f-*screen_height/3.5f);
    //Assumes button width and height are the same
    float button_width= start_settings->menu_button_array[BACK_BUTTON_INTEGER].button_width;
    float button_height= start_settings->menu_button_array[BACK_BUTTON_INTEGER].button_height;

    Rectangle back_bounds={position.x+button_width/7.0f,(position.y+*screen_height/1.5f)-button_height-button_height/7.0f,button_width,button_height};
    Rectangle start_game_bounds= {(position.x+*screen_width/2.0f)-button_width-button_width/7.0f,(position.y+*screen_height/1.5f)
    -button_height-button_height/7.0f,button_width,button_height};

    start_settings->menu_button_array[BACK_BUTTON_INTEGER].bounds=back_bounds;
    start_settings->menu_button_array[START_GAME_BUTTON_INTEGER].bounds=start_game_bounds;
}

void setSettingsBounds(Settings *settings,int *screen_width,int *screen_height){
    
    Vector2 position;
    position.x = (*screen_width/2.0f-*screen_width/4.0f);
    position.y = (*screen_height/2.0f-*screen_height/3.5f);
    //Assumes button *screen_width and *screen_height are the same
    float button_width= settings->menu_button_array[BACK_BUTTON_INTEGER].button_width;
    float button_height= settings->menu_button_array[BACK_BUTTON_INTEGER].button_height;

    Rectangle back_bounds={position.x+button_width/7.0f,(position.y+*screen_height/1.5f)-button_height-button_height/7.0f,button_width,button_height};
    Rectangle apply_bounds= {(position.x+*screen_width/2.0f)-button_width-button_width/7.0f,(position.y+*screen_height/1.5f)
    -button_height-button_height/7.0f,button_width,button_height};

    settings->menu_button_array[BACK_BUTTON_INTEGER].bounds=back_bounds;
    settings->menu_button_array[APPLY_BUTTON_INTEGER].bounds=apply_bounds;
}

void setStatsBounds(Statistics *stats,int *screen_width,int *screen_height){
    Vector2 position;
    position.x = (*screen_width/2.0f-*screen_width/4.0f);
    position.y = (*screen_height/2.0f-*screen_height/3.5f);
    Rectangle back_bounds={position.x+*screen_width/4.0f -stats->menu_button_array[BACK_BUTTON_INTEGER].button_width/2.0f,
    (position.y+*screen_height/1.5f)-stats->menu_button_array[BACK_BUTTON_INTEGER].button_height-
    stats->menu_button_array[BACK_BUTTON_INTEGER].button_height/7.0f,
    stats->menu_button_array[BACK_BUTTON_INTEGER].button_width,stats->menu_button_array[BACK_BUTTON_INTEGER].button_height};
    
    stats->menu_button_array[BACK_BUTTON_INTEGER].bounds=back_bounds;
}
void handleGUIDraw(MenusBundle *menu_bundle,Vector2 *mp,int *state, int *screen_width, int *screen_height){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (*state){
            case(STATE_START):
                drawStartMenu(menu_bundle->menu,screen_width,screen_height);
                startHover(mp,menu_bundle->menu);
                break;
            case(STATE_START_SETTINGS):
                drawStartGameSettings(menu_bundle->start_settings,screen_width,screen_height);
                startSettingsHover(mp,menu_bundle->start_settings);
                break;
            case(STATE_GAME):
                // TODO: Add a draw game function
                break;
            case(STATE_SETTINGS):
                drawSettings(menu_bundle->settings,screen_width,screen_height);
                settingsHover(mp,menu_bundle->settings);
                break;
            case(STATE_STATISTICS):
                drawStatistics(menu_bundle->statistics,screen_width,screen_height);
                statisticsHover(mp,menu_bundle->statistics);
                break;
            default:
                // TODO: Add an error message.
                break;
        }
        EndDrawing();
}
void drawStartMenu(StartMenu *menu,int *screen_width, int *screen_height){
    for(int i=0; i<NUM_MENU_BUTTONS;i++){
        Vector2 position;
        position.x =menu->menu_button_array[i].bounds.x;
        position.y =menu->menu_button_array[i].bounds.y;
        Vector2 text_position;
        text_position.x = position.x+(menu->menu_button_array[i].button_width/2.0f)
        -((float)MeasureText(menu->menu_button_array[i].text,FONT_SIZE_BUT))/2.0f;
        text_position.y= position.y+(menu->menu_button_array[i].button_height/2.0f);
        DrawRectangleRec(menu->menu_button_array[i].bounds,BLACK);
        DrawText(menu->menu_button_array[i].text,text_position.x,text_position.y,FONT_SIZE_BUT,RAYWHITE);
        
    }
    Vector2 title_position;
    title_position.x = *screen_width/2-((float)MeasureText(menu->title,FONT_SIZE_TITLE))/2;
    title_position.y = *screen_height/10;
    DrawText(menu->title,title_position.x,title_position.y,FONT_SIZE_TITLE,BLACK);
}
void drawStartGameSettings(StartSettings *start_settings,int *screen_width, int *screen_height){
    Vector2 position;
    position.x = (*screen_width/2.0f-*screen_width/4.0f);
    position.y = (*screen_height/2.0f-*screen_height/3.5f);
    DrawRectangle(position.x,position.y,*screen_width/2.0f,*screen_height/1.5f,BLACK);
    DrawRectangleRec(start_settings->menu_button_array[BACK_BUTTON_INTEGER].bounds,BLACK);
    DrawRectangleRec(start_settings->menu_button_array[START_GAME_BUTTON_INTEGER].bounds,BLACK);

    Vector2 back_text_position;
    
    back_text_position.x = start_settings->menu_button_array[BACK_BUTTON_INTEGER].bounds.x
    +start_settings->menu_button_array[BACK_BUTTON_INTEGER].bounds.width/2.0f
    -MeasureText(start_settings->menu_button_array[BACK_BUTTON_INTEGER].text,FONT_SIZE_BUT)/2.0f;
    
    back_text_position.y = start_settings->menu_button_array[BACK_BUTTON_INTEGER].bounds.y
    +start_settings->menu_button_array[BACK_BUTTON_INTEGER].bounds.height/2.0f;
    
    DrawText(start_settings->menu_button_array[BACK_BUTTON_INTEGER].text,back_text_position.x,back_text_position.y,FONT_SIZE_BUT,RAYWHITE);
        
    Vector2 start_text_position;
    start_text_position.x = start_settings->menu_button_array[START_GAME_BUTTON_INTEGER].bounds.x
    +start_settings->menu_button_array[START_GAME_BUTTON_INTEGER].bounds.width/2.0f-
    MeasureText(start_settings->menu_button_array[START_GAME_BUTTON_INTEGER].text,FONT_SIZE_BUT)/2.0f;
    start_text_position.y = start_settings->menu_button_array[START_GAME_BUTTON_INTEGER].bounds.y
    +start_settings->menu_button_array[START_GAME_BUTTON_INTEGER].bounds.height/2.0f;
    DrawText(start_settings->menu_button_array[START_GAME_BUTTON_INTEGER].text,start_text_position.x,start_text_position.y,FONT_SIZE_BUT,RAYWHITE);
}

void drawSettings(Settings *settings,int *screen_width, int *screen_height){
    Vector2 position;
    position.x = (*screen_width/2.0f-*screen_width/4.0f);
    position.y = (*screen_height/2.0f-*screen_height/3.5f);
    DrawRectangle(position.x,position.y,*screen_width/2.0f,*screen_height/1.5f,BLACK);
    DrawRectangleRec(settings->menu_button_array[BACK_BUTTON_INTEGER].bounds,BLACK);
    DrawRectangleRec(settings->menu_button_array[APPLY_BUTTON_INTEGER].bounds,BLACK);

    Vector2 back_text_position;
    back_text_position.x =  settings->menu_button_array[BACK_BUTTON_INTEGER].bounds.x
    +settings->menu_button_array[BACK_BUTTON_INTEGER].bounds.width/2.0f
    -MeasureText(settings->menu_button_array[BACK_BUTTON_INTEGER].text,FONT_SIZE_BUT)/2.0f;
    back_text_position.y = settings->menu_button_array[BACK_BUTTON_INTEGER].bounds.y+settings->menu_button_array[BACK_BUTTON_INTEGER].bounds.height/2.0f;
    DrawText(settings->menu_button_array[BACK_BUTTON_INTEGER].text,back_text_position.x,back_text_position.y,FONT_SIZE_BUT,RAYWHITE);
    
    Vector2 apply_text_position;
    apply_text_position.x = settings->menu_button_array[APPLY_BUTTON_INTEGER].bounds.x+settings->menu_button_array[APPLY_BUTTON_INTEGER].bounds.width/2.0f
    -MeasureText(settings->menu_button_array[APPLY_BUTTON_INTEGER].text,FONT_SIZE_BUT)/2.0f;
    apply_text_position.y = settings->menu_button_array[APPLY_BUTTON_INTEGER].bounds.y+settings->menu_button_array[APPLY_BUTTON_INTEGER].bounds.height/2.0f;
    DrawText(settings->menu_button_array[APPLY_BUTTON_INTEGER].text,apply_text_position.x,apply_text_position.y,FONT_SIZE_BUT,RAYWHITE);
}

void drawStatistics(Statistics *stats,int *screen_width, int *screen_height){
    Vector2 position;
    position.x = (*screen_width/2.0f-*screen_width/4.0f);
    position.y = (*screen_height/2.0f-*screen_height/3.5f);
    DrawRectangle(position.x,position.y,*screen_width/2.0f,*screen_height/1.5f,BLACK);
    DrawRectangleRec(stats->menu_button_array[BACK_BUTTON_INTEGER].bounds,BLACK);
    DrawText(stats->menu_button_array[BACK_BUTTON_INTEGER].text,stats->menu_button_array[BACK_BUTTON_INTEGER].bounds.x
    +stats->menu_button_array[BACK_BUTTON_INTEGER].bounds.width/2.0f
    -MeasureText(stats->menu_button_array[BACK_BUTTON_INTEGER].text,FONT_SIZE_BUT)/2.0f,
    stats->menu_button_array[BACK_BUTTON_INTEGER].bounds.y+stats->menu_button_array[BACK_BUTTON_INTEGER].bounds.height/2.0f,FONT_SIZE_BUT,WHITE);

}
void mouseHoverButton(MenuButton *button){
    DrawRectangleRec(button->bounds,DARKGRAY);
    Vector2 text_position;
    text_position.x = button->bounds.x
    +(button->bounds.width/2)-((float)MeasureText(button->text,FONT_SIZE_BUT))/2.0f;
    text_position.y = button->bounds.y+(button->bounds.height/2.0f);
    DrawText(button->text,text_position.x,text_position.y,FONT_SIZE_BUT,YELLOW);
}
void startHover(Vector2 *mp,StartMenu *menu){
    if((CheckCollisionPointRec(*mp,menu->menu_button_array[START_BUTTON_INTEGER].bounds)
    ||CheckCollisionPointRec(*mp,menu->menu_button_array[SETTINGS_BUTTON_INTEGER].bounds)
    ||CheckCollisionPointRec(*mp,menu->menu_button_array[STATS_BUTTON_INTEGER].bounds)
    ||CheckCollisionPointRec(*mp,menu->menu_button_array[QUIT_BUTTON_INTEGER].bounds))){
        if((CheckCollisionPointRec(*mp,menu->menu_button_array[START_BUTTON_INTEGER].bounds))){
            mouseHoverButton(&menu->menu_button_array[START_BUTTON_INTEGER]);
            menu->button_mouse_over=START_BUTTON_INTEGER+1;
        }
        else if(CheckCollisionPointRec(*mp,menu->menu_button_array[SETTINGS_BUTTON_INTEGER].bounds)){
            mouseHoverButton(&menu->menu_button_array[SETTINGS_BUTTON_INTEGER]);
            menu->button_mouse_over=SETTINGS_BUTTON_INTEGER+1;
        }
        else if(CheckCollisionPointRec(*mp,menu->menu_button_array[STATS_BUTTON_INTEGER].bounds)){
            mouseHoverButton(&menu->menu_button_array[STATS_BUTTON_INTEGER]);
            menu->button_mouse_over=STATS_BUTTON_INTEGER+1;
        }
        else{
            mouseHoverButton(&menu->menu_button_array[QUIT_BUTTON_INTEGER]);
            menu->button_mouse_over=QUIT_BUTTON_INTEGER+1;
        }
    }
}

void startSettingsHover(Vector2 *mp,StartSettings *start_settings){
    if(CheckCollisionPointRec(*mp,start_settings->menu_button_array[BACK_BUTTON_INTEGER].bounds)
    ||CheckCollisionPointRec(*mp,start_settings->menu_button_array[START_GAME_BUTTON_INTEGER].bounds)){
        if((CheckCollisionPointRec(*mp,start_settings->menu_button_array[BACK_BUTTON_INTEGER].bounds))){
            mouseHoverButton(&start_settings->menu_button_array[BACK_BUTTON_INTEGER]);
            start_settings->button_mouse_over=BACK_BUTTON_INTEGER+1;
        }
        else{
            mouseHoverButton(&start_settings->menu_button_array[START_GAME_BUTTON_INTEGER]);
            start_settings->button_mouse_over=START_GAME_BUTTON_INTEGER+1;
        }
    }
}

void settingsHover(Vector2 *mp,Settings *settings){
    if(CheckCollisionPointRec(*mp,settings->menu_button_array[BACK_BUTTON_INTEGER].bounds)
    || CheckCollisionPointRec(*mp,settings->menu_button_array[APPLY_BUTTON_INTEGER].bounds)){
        if((CheckCollisionPointRec(*mp,settings->menu_button_array[BACK_BUTTON_INTEGER].bounds))){
            mouseHoverButton(&settings->menu_button_array[BACK_BUTTON_INTEGER]);
            settings->button_mouse_over=BACK_BUTTON_INTEGER+1;
        }
        else{
            mouseHoverButton(&settings->menu_button_array[APPLY_BUTTON_INTEGER]);
            settings->button_mouse_over=APPLY_BUTTON_INTEGER+1;
        }
    }
}

void statisticsHover(Vector2 *mp, Statistics *statistics){
    if(CheckCollisionPointRec(*mp,statistics->menu_button_array[BACK_BUTTON_INTEGER].bounds)){
        mouseHoverButton(&statistics->menu_button_array[BACK_BUTTON_INTEGER]);
        statistics->button_mouse_over=BACK_BUTTON_INTEGER+1;
    }   
}

void handleStartMenuClick(StartMenu *menu,int *state){
    switch (menu->button_mouse_over){
        case(START_BUTTON_INTEGER+1):
            *state=STATE_START_SETTINGS;
            break;
        case(SETTINGS_BUTTON_INTEGER+1):
            *state=STATE_SETTINGS;
            break;
        case(STATS_BUTTON_INTEGER+1):
            *state=STATE_STATISTICS;
            break;
        case(QUIT_BUTTON_INTEGER+1):
            *state=STATE_EXIT;
            break;
        default:
            break;
    }
}
void handleStartGameClick(StartSettings *start_settings, int *state){
    switch (start_settings->button_mouse_over){
        case(BACK_BUTTON_INTEGER+1):
            *state=STATE_START;
            break;
        case(START_GAME_BUTTON_INTEGER+1):
            *state=STATE_GAME;
            break;
        default:
            break;
    }
}

void handleSettingsClick(Settings *settings,int *state){
    switch (settings->button_mouse_over){
        case(BACK_BUTTON_INTEGER+1):
            *state=STATE_START;
            break;
        case(APPLY_BUTTON_INTEGER+1):
            *state=STATE_SETTINGS;
            break;
        default:
            break;
    }
}

void handleStatisticsClick(int *state){
    *state=STATE_START;
}
void handleStateClicks(MenusBundle *menu_bundle,Vector2 *mp,int*state){
        *mp = GetMousePosition();
        switch (*state){
            case(STATE_START):
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)&&menu_bundle->menu->button_mouse_over>NO_CLICKS)
                    handleStartMenuClick(menu_bundle->menu,state);
                break;
            case(STATE_START_SETTINGS):
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)&&menu_bundle->start_settings->button_mouse_over>NO_CLICKS)
                    handleStartGameClick(menu_bundle->start_settings,state);
                break;
            case(STATE_GAME):
                // TODO: Add a click function for in game state
                break;
            case(STATE_SETTINGS):
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)&&menu_bundle->settings->button_mouse_over>NO_CLICKS)
                    handleSettingsClick(menu_bundle->settings,state);
                break;
            case(STATE_STATISTICS):
                if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)&&menu_bundle->statistics->button_mouse_over>NO_CLICKS)
                    handleStatisticsClick(state);
                break;
            default:
                // TODO: Add an error message.
                break;
        }
        menu_bundle->menu->button_mouse_over=NO_CLICKS;
        menu_bundle->settings->button_mouse_over=NO_CLICKS;
        menu_bundle->start_settings->button_mouse_over=NO_CLICKS;
        menu_bundle->statistics->button_mouse_over=NO_CLICKS;
}