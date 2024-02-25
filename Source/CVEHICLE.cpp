#include"CVEHICLE.h"

void CVEHICLE::Move(int xVehicle, int yVehicle)
{
	mX = xVehicle;
	mY = yVehicle;
}

void CCAR::Move(int x, int y)
{
	CGUI::textcolor(241);
	GotoXY(x, y);     wcout << "  ______      ";
	GotoXY(x, y + 1); wcout << " /|_||_\\`.__  ";
	GotoXY(x, y + 2); wcout << "(   _    _ _\\";
	GotoXY(x, y + 3); wcout << "=`-(_)--(_)-' ";
}

void CTRUCK::Move(int x, int y)
{
	CGUI::textcolor(244);
	GotoXY(x, y);     wcout << L"____          ";
	GotoXY(x, y + 1); wcout << L"||DD|____T__  ";
	GotoXY(x, y + 2); wcout << L"||_ |_____|<\\>";
	GotoXY(x, y + 3); wcout << L" @--@-@-oo\\  ";
}

void CAMBULANCE::Move(int x, int y) {
	GotoXY(x, y);     wcout << " _____[]";
	GotoXY(x, y + 1); wcout << "|  |  \\__  ";
	GotoXY(x, y + 2); wcout << "|   |       |";
	GotoXY(x, y + 3); wcout << "|           |";
	GotoXY(x, y + 4); wcout << "`-O------O--'";
}
