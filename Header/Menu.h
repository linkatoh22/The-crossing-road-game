#pragma once
#ifndef MENU_H
#define MENU_H
#include"CGUI.h"
#include<iostream>
#include<Windows.h>
#include"Console.h"
#include"CGAME.h"
#include"Music.h"
#include<fstream>
using namespace std;
class Menu
{
private:
  
    bool playmusic;
    inline static Menu* instance = NULL;
public:
    Menu()
    {
        playmusic = true;
    }
    static Menu* intance()
    {
        if (instance == NULL)
        {
            instance = new Menu();
        }
        return instance;
    }
    void setPlaymusic(bool a)
    {
        playmusic = a;
    }
    bool getPlaymusic()
    {
        return playmusic;
    }
    void drawbox(int x, int y, int height, int width, int color, string but);
    void move1();
    void DrawMenu();
    void Drawload();
    void Drawkey(string stateMu);
    void drawlevel(int level);
    void Settings();
    void drawsettings();
};
#endif