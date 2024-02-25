#include "CPeople.h"
#include  "Console.h"

CPEOPLE::CPEOPLE()
{
	this->mX = 87;
	this->mY = 39;
	this->mState = true;
}

CPEOPLE::~CPEOPLE()
{
	this->mX = 0;
	this->mY = 0;
	this->mState = false;
}

void CPEOPLE::setMState(bool isLive)
{
	this->mState = isLive;
}

bool CPEOPLE::getMState()
{
	return this->mState;
}

void CPEOPLE::setmX(int x)
{
	this->mX = x;
}

void CPEOPLE::setmY(int y)
{
	this->mY = y;
}

void CPEOPLE::setXY(int x, int y)
{
	setmX(x);
	setmY(y);
}

int CPEOPLE::getmX()
{
	return this->mX;
}

int CPEOPLE::getmY()
{
	return this->mY;
}

void CPEOPLE::Up(int y)
{
	if (this->mY > 6)
		this->mY = this->mY - y;
}

void CPEOPLE::Left(int x)
{
	if (this->mX > 34)
		this->mX = this->mX - x;
}

void CPEOPLE::Right(int x)
{
	if (this->mX < 142)
		this->mX = this->mX + x;
}

void CPEOPLE::Down(int y)
{
	if (this->mY < 38)
		this->mY = this->mY + y;
}

bool CPEOPLE::isImpact(const CVEHICLE* v, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (this->mX >= v[i].getX() - 6 && this->mX <= (v[i].getX() + 8) && (this->mY - 1) == v[0].getY())
		{
			this->mState = false;
			return true;
		}
	}
}

bool CPEOPLE::isImpact(const CANIMAL* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (this->mX >= a[i].getX() - 2 && this->mX <= (a[i].getX() + 14) && (this->mY - 1) == a[0].getY())
		{
			this->mState = false;
			return true;
		}
	}
}

bool CPEOPLE::isDead()
{
	if (this->mState == false)
		return true;
	return false;
}

bool CPEOPLE::isFinish()
{
	if (this->mX >= 0 && this->mY <= 6)
		return true;
	return false;
}

void CPEOPLE::printpeople(int x, int y)
{
	CGUI::textcolor(240);
	GotoXY(this->mX + 2, this->mY); cout << "/" << char(92) << char(92);
	GotoXY(this->mX, this->mY + 1);     cout << " ('_') ";
	GotoXY(this->mX, this->mY + 2);  cout << "/|   |\\";
	GotoXY(this->mX, this->mY + 3);  cout << " ||||| ";
	GotoXY(this->mX, this->mY + 4); cout << " |_  |_";
}

void CPEOPLE::printpeopledie(int x, int y)
{
	CGUI::textcolor(244);
	GotoXY(this->mX + 2, this->mY); cout << "/" << char(92) << char(92);
	GotoXY(this->mX, this->mY + 1);     cout << " (x_x) ";
	GotoXY(this->mX, this->mY + 2);  cout << "/|   |\\";
	GotoXY(this->mX, this->mY + 3);  cout << " ||||| ";
	GotoXY(this->mX, this->mY + 4); cout << " |_  |_";
}
