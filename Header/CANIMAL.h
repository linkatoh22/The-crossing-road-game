#pragma once
#include"CGUI.h"

class CANIMAL
{
	int mX, mY;

public:
	virtual void Move(int, int);
	int getX() const
	{
		return mX;
	}
	int getY() const
	{
		return mY;
	}
	void setX(int x)
	{
		mX = x;
	}
	void setY(int y)
	{
		mY = y;
	}

};

class CDINOSOUR : public CANIMAL
{
public:
	void Move(int xDino, int yDino);

};

class CBIRD : public CANIMAL
{
public:
	void Move(int xBird, int yBird);

};

