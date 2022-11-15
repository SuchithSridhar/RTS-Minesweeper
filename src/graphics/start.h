#ifndef START_H
#define START_H

#include "../../include/raylib.h"

#include "tmp_structs.h"


void DrawStartMenu(Menu *menu,double width,double height);

void DrawStartGameSettings(StartSettings *start_settings,double width, double height);

void DrawSettings(Settings *settings, double width, double height);

void DrawStatistics(Statistics *statistics, double width, double height);


void SetMenuBounds(Menu *menu,double width,double height);

void SetStartGameBounds(StartSettings *start_settings,double width,double height);

void SetSettingsBounds(Settings *settings,double width,double height);

void SetStatsBounds(Statistics *stats,double width,double height);


void MouseHoverButton(MenuButton *button);

void MenuClick(Menu *menu,int *state);

void StartGameClick(StartSettings *start_settings,int *state);

void SettingsClick(Settings *settings,int *state);

void StatsClick(int *state);

void ExitGame();

#endif