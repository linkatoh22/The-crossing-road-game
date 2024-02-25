#include"Menu.h"
bool IS_RUNNING = 1;
char MOVING;
CGAME* cg;
CGUI draw;
Music* MusicBox1 = Music::getInstance();
Music* MusicBox = Music::getInstance();
string state = "  TURN ON MUSIC";
string stateMu;
using namespace std;

void Menu::drawbox(int x, int y, int height, int width, int color, string but)
{
	draw.textcolor(color);
	int j = 0;
	for (int iy = y + 1; iy <= y + height - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + width - 1; ix++)
		{
			GotoXY(ix, iy);
			cout << " ";
		}
	}
	GotoXY(x + 7, y + 2);
	cout << but;
	draw.textcolor(240);//doi chu
	for (int ix = x; ix <= x + width; ix++)
	{
		GotoXY(ix, y);
		cout << char(223);

		GotoXY(ix, y + height);
		cout << char(220);
	}
	for (int iy = y; iy <= y + height; iy++)
	{
		GotoXY(x, iy);
		cout << char(221);

		GotoXY(x + width, iy);
		cout << char(222);

		j++;
	}
	GotoXY(x, y);

	cout << char(220);
	GotoXY(x + width, y);

	cout << char(220);
	GotoXY(x, y + height);

	cout << char(223);
	GotoXY(x + width, y + height);
	cout << char(223);

}

void Menu::move1()
{
	MusicBox1->setMusic(menu);
	MusicBox1->runningMusic(menu);
	ScreenColor();
	DrawMenu();
	char c;
	int counter = 1;
	int index = 4;
	int color[4] = { 244,244,244,244 };
	cg = new CGAME();
	drawbox(88, 20, 4, 30, 95,  "   START GAME");
	drawbox(88, 26, 4, 30, 244, "    LOAD GAME");
	drawbox(88, 32, 4, 30, 244, "    SETTINGS");
	drawbox(88, 38, 4, 30, 244, "    EXIT GAME");

	CAMBULANCE* act = new CAMBULANCE();

	for (int i = 0;;)
	{
		c = toupper(_getch());

		if (((c == 72 || c == 'W') && (counter >= 2 && counter <= 4)))
		{
			counter--;
		}
		else if ((c == 80 || c == 'S') && (counter >= 1 && counter <= 3))
		{
			if (counter == 0)
			{
				counter += 2;
			}
			else
			{
				counter++;
			}
		}
		else if (c == '\r')//carriage return
		{
			draw.setcolor(246);
			GotoXY(0, 48);
			if (counter == 1)
			{
				system("cls");

				if (getPlaymusic() == true || state == "  TURN ON MUSIC")
				{
					MusicBox->setMusic(game);
					MusicBox->runningMusic(game);
					stateMu = "ON MUSIC";
				}
				else if (getPlaymusic() == false || state == "  TURN OFF MUSIC")
				{
					MusicBox->stopMusic();
					stateMu = "OFF MUSIC";
				}
				cg->control();
			}
			if (counter == 2)
			{

				bool run;
				drawbox(73, 22, 15, 60, 241, "   ");
				Drawload();
				run = cg->loadgame();
				if (run == true)
				{
					system("cls");
					MusicBox1->stopMusic();
					if (getPlaymusic() == true || state == "  TURN ON MUSIC")
					{
						MusicBox->setMusic(game);
						MusicBox->runningMusic(game);
						stateMu = "ON MUSIC";
					}
					else if (getPlaymusic() == false || state == "  TURN OFF MUSIC")
					{
						MusicBox->stopMusic();
						stateMu = "OFF MUSIC";
					}
					cg->control();
				}
				else
				{
					char a;
					drawbox(68, 22, 4, 70, 241, "This file is not existed! Press enter or esc to continue.");
					a = _getch();
					system("cls");
					DrawMenu();

				}
			}
			if (counter == 3)
			{
				system("cls");
				MusicBox1->setMusic(menu);
				Settings();
				DrawMenu();
			}
			if (counter == 4)
			{
				char a;
				drawbox(68, 22, 5, 70, 241, "Do you wish to exit?(Press Y to exit anykey to continue)");
				a = toupper(_getch());
				if (a == 'Y')
					break;
				else
				{
					system("cls");
					DrawMenu();
				}

			}
		}
		else
		{
			continue;
		}
		color[0] = 244;
		color[1] = 244;
		color[2] = 244;
		color[3] = 244;
		if (counter == 1)
		{
			color[0] = 95;
		}
		if (counter == 2)
		{
			color[1] = 95;
		}
		if (counter == 3)
		{
			color[2] = 95;
		}
		if (counter == 4)
		{
			color[3] = 95;
		}

		DrawMenu();
		drawbox(88, 20, 4, 30, color[0], "   START GAME");
		drawbox(88, 26, 4, 30, color[1], "    LOAD GAME");
		drawbox(88, 32, 4, 30, color[2], "    SETTINGS");
		drawbox(88, 38, 4, 30, color[3], "    EXIT GAME");
	}

}

void Menu::DrawMenu()
{
	draw.setcolor(249);
	GotoXY(7, 5);
	cout << "       _  _  _     _  _  _  _       _  _  _  _      _  _  _  _      _  _  _  _   _  _  _  _           _     _  _  _              _  _  _  _       _  _  _  _          _        _  _  _  _      "; GotoXY(7, 6);
	cout << "    _ (_)(_)(_) _ (_)(_)(_)(_) _  _(_)(_)(_)(_)_  _(_)(_)(_)(_)_  _(_)(_)(_)(_)_(_)(_)(_)(_) _       (_) _ (_)(_)(_) _          (_)(_)(_)(_) _  _(_)(_)(_)(_)_      _(_)_     (_)(_)(_)(_)     "; GotoXY(7, 7);
	cout << "   (_)         (_)(_)         (_)(_)          (_)(_)          (_)(_)          (_)  (_)   (_)(_)_     (_)(_)         (_)         (_)         (_)(_)          (_)   _(_) (_)_    (_)      (_)_   ";  GotoXY(7, 8);
	cout << "   (_)            (_) _  _  _ (_)(_)          (_)(_)_  _  _  _   (_)_  _  _  _     (_)   (_)  (_)_   (_)(_)    _  _  _          (_) _  _  _ (_)(_)          (_) _(_)     (_)_  (_)        (_)  ";  GotoXY(7, 9);
	cout << "   (_)            (_)(_)(_)(_)   (_)          (_)  (_)(_)(_)(_)_   (_)(_)(_)(_)_   (_)   (_)    (_)_ (_)(_)   (_)(_)(_)         (_)(_)(_)(_)   (_)          (_)(_) _  _  _ (_) (_)        (_)  ";  GotoXY(7, 10);
	cout << "   (_)          _ (_)   (_) _    (_)          (_) _           (_) _           (_)  (_)   (_)      (_)(_)(_)         (_)         (_)   (_) _    (_)          (_)(_)(_)(_)(_)(_) (_)       _(_)  ";  GotoXY(7, 11);
	cout << "   (_) _  _  _ (_)(_)      (_) _ (_)_  _  _  _(_)(_)_  _  _  _(_)(_)_  _  _  _(_)_ (_) _ (_)         (_)(_) _  _  _ (_)         (_)      (_) _ (_)_  _  _  _(_)(_)         (_) (_)_  _  (_)    ";  GotoXY(7, 12);
	cout << "      (_)(_)(_)   (_)         (_)  (_)(_)(_)(_)    (_)(_)(_)(_)    (_)(_)(_)(_) (_)(_)(_)(_)         (_)   (_)(_)(_)(_)         (_)         (_)  (_)(_)(_)(_)  (_)         (_)(_)(_)(_)(_)     ";  GotoXY(7, 13);

}

void Menu::Drawload()
{
	draw.setcolor(191);
	GotoXY(74 + 9, 24);
	cout << " __              _                      \n";
	GotoXY(74 + 9, 25);
	cout << "|  |   ___ ___ _| |   ___ ___ _____ ___ \n";
	GotoXY(74 + 9, 26);
	cout << "|  |__| . | .'| . |  | . | .'|     | -_|\n";
	GotoXY(74 + 9, 27);
	cout << "|_____|___|__,|___|  |_  |__,|_|_|_|___|\n";
	GotoXY(74 + 9, 28);
	cout << "                     |___|              \n";
	GotoXY(78, 31);
	draw.setcolor(248);
	cout << "Enter your name: ";
	draw.setcolor(240);
}

void Menu::Drawkey(string stateMu)
{
	drawbox(164, 16, 20, 38, 252, " ");
	GotoXY(165, 17);
	cout << "===========KeyBoard Control==========";
	draw.setcolor(244);
	GotoXY(168, 19);
	cout << "[ P ]    TO PAUSE";
	GotoXY(168, 22);
	cout << "[ M ]    TO TURN " << stateMu;
	GotoXY(168, 25);
	cout << "[ R ]    TO RESUME";
	GotoXY(168, 28);
	cout << "[ T ]    TO SAVE AND EXIT";
	GotoXY(168, 31);
	cout << "[ K ]    TO SAVE AND CONTINUE";
	GotoXY(168, 34);
	cout << "[ Q ]    TO RETURN TO THE MENU";
}

void Menu::drawlevel(int level)
{
	drawbox(173, 4, 9, 21, 252, " ");
	draw.setcolor(223);
	if (level == 1)
	{
		GotoXY(177, 5);
		cout << "    ____     ";
		GotoXY(177, 6);
		cout << "   /  \" \\    ";
		GotoXY(177, 7);
		cout << "  /__|| |    ";
		GotoXY(177, 8);
		cout << "     |: |    ";
		GotoXY(177, 9);
		cout << "    _\\  |    ";
		GotoXY(177, 10);
		cout << "   /\" \\_|\\   ";
		GotoXY(177, 11);
		cout << "  (_______)  ";
		GotoXY(177, 12);
		cout << "             ";
	}
	else if (level == 2)
	{
		GotoXY(178, 5);
		cout << "   ______    ";
		GotoXY(178, 6);
		cout << "  /\"    \"\\   ";
		GotoXY(178, 7);
		cout << " (__/\\   :)  ";
		GotoXY(178, 8);
		cout << "     /  \"/   ";
		GotoXY(178, 9);
		cout << "  __/   /    ";
		GotoXY(178, 10);
		cout << " (: \"  /___  ";
		GotoXY(178, 11);
		cout << "  \\________) ";
		GotoXY(178, 12);
		cout << "             ";

	}
	else if (level == 3)
	{
		GotoXY(177, 5);
		cout << "   _______   ";
		GotoXY(177, 6);
		cout << "  /\" __   )  ";
		GotoXY(177, 7);
		cout << " (__/ _) ./  ";
		GotoXY(177, 8);
		cout << "     /   /   ";
		GotoXY(177, 9);
		cout << "  __ \\_  \\   ";
		GotoXY(177, 10);
		cout << " (: \\__) :\\  ";
		GotoXY(177, 11);
		cout << "  \\________) ";
		GotoXY(177, 12);
		cout << "             ";



	}
	else if (level == 4)
	{
		GotoXY(177, 5);
		cout << "  ___  ___    ";
		GotoXY(177, 6);
		cout << " (: \"||_  |   ";
		GotoXY(177, 7);
		cout << " |  (__) :|   ";
		GotoXY(177, 8);
		cout << "  \\____  ||   ";
		GotoXY(177, 9);
		cout << "      _\\ '|   ";
		GotoXY(177, 10);
		cout << "     /\" \\_|\\  ";
		GotoXY(177, 11);
		cout << "    (_______) ";
		GotoXY(177, 12);
		cout << "              ";
	}
	else if (level == 5)
	{
		GotoXY(179, 5);
		cout << "   ________  ";
		GotoXY(179, 6);
		cout << "  /"      ") ";
		GotoXY(179, 7);
		cout << " (:    /\\_/  ";
		GotoXY(179, 8);
		cout << "  \\___ \\     ";
		GotoXY(179, 9);
		cout << "  __  ) \\    ";
		GotoXY(179, 10);
		cout << " /\" \\/  :)   ";
		GotoXY(179, 11);
		cout << "(_______/    ";


	}
}

void Menu::Settings()
{
	DrawMenu();
	char c;
	
	int counter = 1;
	int index = 4;
	int color[2] = { 244,244 };
	drawbox(88, 20, 4, 30, 95, state);
	drawbox(88, 26, 4, 30, 244, "      BACK");
	for (int i = 0;;)
	{
		c = toupper(_getch());

		if (((c == 72 || c == 'W') && (counter >= 2 && counter <= 2)))
		{
			counter--;
		}
		else if ((c == 80 || c == 'S') && (counter >= 1 && counter <= 1))
		{
			counter++;
		}
		else if (c == '\r')//carriage return
		{
			draw.setcolor(246);
			GotoXY(0, 48);
			if (counter == 1)
			{
				if (state == "  TURN OFF MUSIC")
				{
					state = "  TURN ON MUSIC";
					MusicBox1->runningMusic(menu);
					setPlaymusic(true);
				}
				else if (state == "  TURN ON MUSIC")
				{
					state = "  TURN OFF MUSIC";
					MusicBox1->stopMusic();
					setPlaymusic(false);
				}
			}
			if (counter == 2)
			{
				system("cls");
				break;
			}
		}
		else
		{
			continue;
		}
		color[0] = 244;
		color[1] = 244;
		if (counter == 1)
		{
			color[0] = 95;
		}
		if (counter == 2)
		{
			color[1] = 95;
		}
		drawbox(88, 20, 4, 30, color[0], state);
		drawbox(88, 26, 4, 30, color[1], "      BACK");
	}
}

void Menu::drawsettings()
{
	GotoXY(22, 4);
	cout << "                      ___       ___                                            ";
	GotoXY(22, 5);
	cout << "                     (   )     (   )      .-.                                  ";
	GotoXY(22, 6);
	cout << "    .--.      .--.    | |_      | |_     ( __)  ___ .-.     .--.       .--.    ";
	GotoXY(22, 7);
	cout << "  /  _  \\    /    \\  (   __)   (   __)   (''\") (   )   \\   /    \\    /  _  \\   ";
	GotoXY(22, 8);
	cout << " . .' `. ;  |  .-. ;  | |       | |       | |   |  .-. .  ;  ,-. '  . .' `. ;  ";
	GotoXY(22, 9);
	cout << " | '   | |  |  | | |  | | ___   | | ___   | |   | |  | |  | |  | |  | '   | |  ";
	GotoXY(22, 10);
	cout << " _\\_`.(___) |  |/  |  | |(   )  | |(   )  | |   | |  | |  | |  | |  _\\_`.(___) ";
	GotoXY(22, 11);
	cout << "(   ). '.   |  ' _.'  | | | |   | | | |   | |   | |  | |  | |  | | (   ). '.   ";
	GotoXY(22, 12);
	cout << " | |  `\\ |  |  .'.-.  | ' | |   | ' | |   | |   | |  | |  | '  | |  | |  `\\ |  ";
	GotoXY(22, 13);
	cout << " ; '._,' '  '  `-' /  ' `-' ;   ' `-' ;   | |   | |  | |  '  `-' |  ; '._,' '  ";
	GotoXY(22, 14);
	cout << "  '.___.'    `.__.'    `.__.     `.__.   (___) (___)(___)  `.__. |   '.___.'   ";
	GotoXY(22, 15);
	cout << "                                                           ( `-' ;             ";
	GotoXY(22, 3);
	cout << "                                                            `.__.              ";

}










