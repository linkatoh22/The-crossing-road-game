#include"CANIMAL.h"
#include"CGUI.h"

void CANIMAL::Move(int xAnimal, int yAnimal)
{
	mX = xAnimal;
	mY = yAnimal;
}

void CDINOSOUR::Move(int x, int y)
{
	CGUI::textcolor(252);
	GotoXY(x, y);	  wcout << "{x'x}\\       ,";
	GotoXY(x, y + 1); wcout << " `-'\\ `--.__~'";
	GotoXY(x, y + 2); wcout << "   ~'\\( ,_.-' ";
	GotoXY(x, y + 3); wcout << "       \\     ";
	GotoXY(x, y + 4); wcout << "       ^'     ";
}

void CBIRD::Move(int x, int y)
{
	CGUI::textcolor(246);
	GotoXY(x, y);     wcout << "    /\\_/\\     ";
	GotoXY(x, y + 1); wcout << "   ((@v@))    ";
	GotoXY(x, y + 2); wcout << "   ():::()    ";
	GotoXY(x, y + 3); wcout << "   ((:::))    ";
	GotoXY(x, y + 4); wcout << "/---VV-VV---/~";
}

