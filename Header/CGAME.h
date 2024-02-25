#pragma once
#include "CGUI.h"
#include "CANIMAL.h"
#include "CVEHICLE.h"
#include "CPEOPLE.h"
#include "Music.h"
#include"Menu.h"
#include<fstream>
#include<string>
#include<thread>
#include<Windows.h>

#define WIDTHLANE 122
#define HEIGHTLANE 42
#define LEFTSIDE 30
#define RIGHTSIDE 152

#define YCAR 10
#define YBIRD 17
#define YTRUCK 24
#define YDINO  31

#define MAX_LEVEL 5

class CGAME
{
private:
	CCAR* axh;
	CTRUCK* axt;
	CDINOSOUR* akl;
	CBIRD* ac;
	CPEOPLE* cn;
	CAMBULANCE* acc;
	Music* MusicBox;

	int level;
	int numberOfObjects;

	bool IS_RUNNING;
	char MOVING;

public:
	CGAME();
	~CGAME();

	void drawGame();
	void setLevel(int);
	int getLevel();
	void setNumberOfObjects();
	void setNumberOfObjects1(int x);
	int getNumberOfObjects();
	int getNumberOfObjects1();
	CVEHICLE* getCars();
	CVEHICLE* getTrucks();
	CANIMAL* getBirds();
	CANIMAL* getDinosours();
	CPEOPLE* getPeople();
	void resetGame(int level);
	void pause();
	void resume();
	void death();
	void playGame();
	void control();
	void savegame();
	bool loadgame();
	void exitgame(thread* t1);

	void updatePosVehicle(CVEHICLE*, int y);
	void updatePosAnimal(CANIMAL*, int y);
	void updatePosPeople(char);
	bool controlTraffic(int x, int y, int mode = 0, int time = 4);
};

void SupportThread();
