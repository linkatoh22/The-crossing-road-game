#pragma once
#include<iostream>
#include<ctime>
#include<thread>
#include<stdio.h>
#include<windows.h>
#include"Console.h"
using namespace std;

//DEFINE COLOR
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define REDDARK 4
#define PINK 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_BLUE 11
#define LIGHT_RED 12
#define	LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15
//DEFINE CONTROL KEY
#define UPkey 72
#define DOWNkey 80
#define ENTERkey 13
#define LEFTkey 75
#define RIGHTkey 77

class CGUI
{
public:
	void printRoad();
	static void textcolor(int);
	static void setcolor(int);
	static void loser();
	static void winner();
};

void deleteOldPos(int x, int y, int width_of_object, int height_of_object);
