#ifndef START_H
#define START_H

#include "../../include/raylib.h"

#include "tmp_structs.h"
#include "constants.h"

void initStartMenu(Menu *menu, int screen_width, int screen_height);

void initStartGameSettings(StartSettings *start_settings, int screen_width, int screen_height);

void initSettings(Settings *settings, int screen_width, int screen_height);

void initStatistics(Statistics *statistics, int screen_width, int screen_height);


void drawStartMenu(Menu *menu,double width,double height);

void drawStartGameSettings(StartSettings *start_settings,double width, double height);

void drawSettings(Settings *settings, double width, double height);

void drawStatistics(Statistics *statistics, double width, double height);


void setMenuBounds(Menu *menu,double width,double height);

void setStartGameBounds(StartSettings *start_settings,double width,double height);

void setSettingsBounds(Settings *settings,double width,double height);

void setStatsBounds(Statistics *stats,double width,double height);


void mouseHoverButton(MenuButton *button);

void startHover(Vector2 *mp,Menu *menu);

void startSettingsHover(Vector2 *mp,StartSettings *start_settings);

void settingsHover(Vector2 *mp,Settings *settings);

void statisticsHover(Vector2 *mp, Statistics *statistics);


void menuClick(Menu *menu,int *state);

void startGameClick(StartSettings *start_settings,int *state);

void settingsClick(Settings *settings,int *state);

void statsClick(int *state);

void exitGame();

#endif