#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <mmsystem.h>
#include "CVEHICLE.h"
#include "CANIMAL.h"
using namespace std;

class CPEOPLE
{
	int mX, mY;
	int length, width;
	bool mState; //Trạng thái sống chết

public:
	CPEOPLE();
	~CPEOPLE();

	void Up(int);
	void Left(int);
	void Right(int);
	void Down(int);

	bool isFinish();
	bool isDead();
	bool isImpact(const CVEHICLE*, int);
	bool isImpact(const CANIMAL*, int);
	void setMState(bool isLive);
	bool getMState();
	void setmX(int x);
	void setmY(int y);
	void setXY(int x, int y);
	int getmX();
	int getmY();
	void printpeople(int x, int y);
	void printpeopledie(int x, int y);
};

