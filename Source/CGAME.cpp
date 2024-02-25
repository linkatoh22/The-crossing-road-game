#include "CGAME.h"
extern bool IS_RUNNING;
extern CGAME* cg;
extern char MOVING;
Menu MENU = *(Menu::intance());
Music* MusicBox2 = Music::getInstance();
extern string stateMu;
bool playmenu;
extern string state;

CGAME::CGAME()
{
	axh = NULL;
	axt = NULL;
	akl = NULL;
	ac = NULL;
	cn = NULL;
	acc = NULL;
	level = 1;
	numberOfObjects = 0;
	IS_RUNNING = 1;
	MusicBox = Music::getInstance();

};

CGAME::~CGAME()
{
	delete[] axh;
	axh = NULL;

	delete[] axt;
	axt = NULL;

	delete[] akl;
	akl = NULL;

	delete[] ac;
	ac = NULL;

	delete acc;
	delete cn;

	level = 1;
	numberOfObjects = 0;
};

void CGAME::drawGame()
{
	CGUI draw;
	FixConsoleWindow();
	ScreenColor();
	ShowCur(0);
	draw.printRoad();
	MENU.drawlevel(level);
	MENU.Drawkey(stateMu);
	// Cái này tui mới vẽ cái đường thôi, hai bạn phụ trách GUI trang trí thêm nhá
};

void CGAME::setLevel(int lv)
{
	this->level = lv;
};

int CGAME::getLevel()
{
	return level;
};

void CGAME::setNumberOfObjects1(int x)
{
	this->numberOfObjects = x;
}

int CGAME::getNumberOfObjects1()
{
	return this->numberOfObjects;
}

void CGAME::setNumberOfObjects()
{
	switch (this->level)
	{
	case 1:
	{
		this->numberOfObjects = 1;
		break;
	};
	case 2:
	{
		this->numberOfObjects = 2;
		break;
	};
	case 3:
	{
		this->numberOfObjects = 3;
		break;
	};
	case 4:
	{
		this->numberOfObjects = 4;
		break;
	};
	case 5:
	{
		this->numberOfObjects = 5;
		break;
	};
	default:
	{
		this->numberOfObjects = 0;
		break;
	};
	};
};

int CGAME::getNumberOfObjects()
{
	if (level == 1)
	{
		this->numberOfObjects = 1;
	}
	else if (level == 2)
	{
		this->numberOfObjects = 2;
	}
	else if (level == 3)
	{
		this->numberOfObjects = 3;
	}
	else if (level == 4)
	{
		this->numberOfObjects = 4;
	}
	return this->numberOfObjects;
};

CVEHICLE* CGAME::getCars()
{
	return axh;
};

CVEHICLE* CGAME::getTrucks()
{
	return axt;
};

CANIMAL* CGAME::getBirds()
{
	return ac;
};

CANIMAL* CGAME::getDinosours()
{
	return akl;
};

void CGAME::resetGame(int level)
{

	cg->setLevel(level);
	int maxObject = cg->getNumberOfObjects();
	drawGame();
	//Khởi tạo danh sách xe hơi
	axh = new CCAR[maxObject];
	for (int i = 0; i < maxObject; i++)
	{
		axh[i].setX(LEFTSIDE + 4);
		axh[i].setY(YCAR);
	}

	//Khởi tạo danh sách xe tải
	axt = new CTRUCK[maxObject];
	for (int i = 0; i < maxObject; i++)
	{
		axt[i].setX(LEFTSIDE + 4);
		axt[i].setY(YTRUCK);
	}


	//Khởi tạo danh sách khủng long
	akl = new CDINOSOUR[maxObject];
	for (int i = 0; i < maxObject; i++)
	{
		akl[i].setX(RIGHTSIDE - 20);
		akl[i].setY(YDINO);
	}

	//Khởi tạo danh sách chim
	ac = new CBIRD[maxObject];
	for (int i = 0; i < maxObject; i++)
	{
		ac[i].setX(RIGHTSIDE - 20);
		ac[i].setY(YBIRD);
	}

	cn = new CPEOPLE();

};

CPEOPLE* CGAME::getPeople()
{
	cn->isImpact(axh, cg->getNumberOfObjects());
	cn->isImpact(axt, cg->getNumberOfObjects());
	cn->isImpact(ac, cg->getNumberOfObjects());
	cn->isImpact(akl, cg->getNumberOfObjects());

	return cn;
}

void CGAME::death()
{
	char choose;
	system("cls");
	cg->drawGame();
	cn->printpeopledie(cn->getmX(), cn->getmY());
	CAMBULANCE* act = new CAMBULANCE();

	act->setX(LEFTSIDE + 4);
	int tmp;
	MusicBox->setMusic(ambulance);
	MusicBox->runningMusic(ambulance);
	while (act->getX() != RIGHTSIDE - 18)
	{
		tmp = act->getX();
		deleteOldPos(tmp - 2, cn->getmY(), 14, 5);
		act->Move(tmp, cn->getmY());
		act->setX(tmp + 2);
		Sleep(50);
	}
	deleteOldPos(tmp - 2, cn->getmY(), 14, 5);
	MusicBox->stopMusic();

	system("cls");

	CGUI::loser();

	MusicBox->setMusic(gameover);
	MusicBox->PlayingSound1time(gameover);

	CGUI::setcolor(249);

	GotoXY(83, 22);
	for (int i = 0; i < 38; i++)
	{
		cout << char(196);
	}
	GotoXY(82, 22);
	cout << char(3);
	for (int i = 0; i < 2; i++)
	{
		GotoXY(82, 23 + i);
		cout << char(179);
	}
	GotoXY(121, 22);
	cout << char(3);
	GotoXY(82, 25);
	cout << char(3);
	GotoXY(84, 23);
	cout << "Restart or not??           \n";
	GotoXY(84, 24);
	cout << "Press G: Restart, N: Return to Menu. ";
	for (int i = 0; i < 2; i++)
	{
		GotoXY(121, 23 + i);
		cout << char(179);
	}
	GotoXY(121, 25);
	cout << char(3);
	GotoXY(83, 25);
	for (int i = 0; i < 38; i++)
		cout << char(196);


}

void CGAME::playGame()
{
	int i;
	if (axh == NULL && axt == NULL && akl == NULL && ac == NULL && cn == NULL && acc == NULL && level == 1 && numberOfObjects == 0)
	{
		cg->resetGame(1);
		i = 1;
	}
	else
	{
		drawGame();
		i = level;
	}

	while (IS_RUNNING)
	{
		if (MusicBox->getChanged())
		{
			if (MusicBox->getChanged()) MusicBox->Unchanged();
			if (!MusicBox->getIsRunning())
			{
				MusicBox->runningMusic(game);
			}
			else
			{
				MusicBox->stopMusic();
			}
		}

		if (!cg->getPeople()->isDead())
		{
			cg->updatePosPeople(MOVING);
		}
		else
		{
			MusicBox->stopMusic();
			MusicBox->setMusic(accident);
			MusicBox->PlayingSound1time(accident);
			cg->setLevel(level);
			cg->death();
			break;
		}
		MOVING = ' ';

		if (cg->getPeople()->isFinish())
		{
			i++;

			if (i < 5)
			{
				system("cls");
				cg->resetGame(i);
			}
			else if (i >= 5)
			{
				system("cls");

				CGUI::winner();

				MusicBox->stopMusic();
				MusicBox->setMusic(wingame);
				MusicBox->PlayingSound1time(wingame);

				CGUI::setcolor(249);

				GotoXY(83, 28);
				for (int i = 0; i < 38; i++)
				{
					cout << char(196);
				}
				GotoXY(82, 28);
				cout << char(3);
				for (int i = 0; i < 2; i++)
				{
					GotoXY(82, 29 + i);
					cout << char(179);
				}
				GotoXY(121, 28);
				cout << char(3);
				GotoXY(82, 31);
				cout << char(3);
				GotoXY(84, 29);
				cout << "Restart or not??           \n";
				GotoXY(84, 30);
				cout << "Press G: Restart, N: Return to Menu. ";
				for (int i = 0; i < 2; i++)
				{
					GotoXY(121, 29 + i);
					cout << char(179);
				}
				GotoXY(121, 31);
				cout << char(3);
				GotoXY(83, 31);
				for (int i = 0; i < 38; i++)
					cout << char(196);
				break;
			}
			if (stateMu == "OFF MUSIC")
			{
				MusicBox->stopMusic();
			}
			else
			{
				MusicBox->setMusic(game);
				MusicBox->runningMusic(game);
			}
			continue;
		}
		if (cg->controlTraffic(160, 12, 0))
		{
			cg->updatePosVehicle(axh, YCAR);
		}
		if (cg->controlTraffic(160, 19, 1))
		{
			cg->updatePosAnimal(ac, YBIRD);
		}
		if (cg->controlTraffic(160, 26, 0))
		{
			cg->updatePosVehicle(axt, YTRUCK);
		}
		if (cg->controlTraffic(160, 34, 1))
		{
			cg->updatePosAnimal(akl, YDINO);
		}
		Sleep(50);
	}
}

void CGAME::control()
{
	thread task(SupportThread);
	char input;

	while (true)
	{
		Sleep(0);
		input = toupper(_getch());

		if (input == 'M' || input == 'm')
		{
			MOVING = input;
			MusicBox->setMusic(game);
			MusicBox->Changed();
		}

		if (cg->getPeople()->isDead() == false)
		{

			if (input == 'W' || input == 'A' || input == 'D' || input == 'S')
				MOVING = input;
			else if (input == 'T') //save and exit
			{
				cg->exitgame(&task);
				cg->savegame();
				system("cls");
				cg = new CGAME();
				if (playmenu == true || stateMu == "ON MUSIC")
				{
					MusicBox2->setMusic(menu);
					MusicBox2->runningMusic(menu);
					state = "  TURN ON MUSIC";
				}
				else if (playmenu == false || stateMu == "OFF MUSIC")
				{
					MusicBox2->stopMusic();
					state = "  TURN OFF MUSIC";
				}
				break;
			}
			else if (input == 'P') //pause
			{
				cg->pause();
			}
			else if (input == 'R') //resume
			{
				if (IS_RUNNING == false)
				{
					cg->resume();
					task.detach();
					task = thread(SupportThread);
				}
			}
			else if (input == 'K')//save and continue
			{
				cg->pause();
				cg->savegame();
				system("cls");
				cg->resume();
				task.detach();
				task = thread(SupportThread);
			}
			else if (input == 'Q') //back to menu
			{
				cg->pause();
				system("cls");
				ScreenColor();
				MENU.drawbox(62, 22, 4, 85, 241, "Do you wish to go back to menu? Press Y to go back or anykey to continue.");
				char a = toupper(_getch());
				system("cls");
				if (a == 'Y')
				{
					cg->exitgame(&task);
					ScreenColor();
					cg = new CGAME();
					if (playmenu == true || stateMu == "ON MUSIC")
					{
						MusicBox2->setMusic(menu);
						MusicBox2->runningMusic(menu);
						state = "  TURN ON MUSIC";
					}
					else if (playmenu == false || stateMu == "OFF MUSIC")
					{
						MusicBox2->stopMusic();
						state = "  TURN OFF MUSIC";
					}
					break;
				}
				else
				{
					cg->resume();
					task.detach();
					task = thread(SupportThread);
				}

			}
			else if (input == 'M' || input == 'm')
			{

				// Tat nhac ba them vo cho tui nha
				if (stateMu == "OFF MUSIC")
				{
					MusicBox->stopMusic();
					GotoXY(185, 22);
					stateMu = "ON MUSIC";
					playmenu = true;
					CGUI::setcolor(244);
					cout << "ON MUSIC     ";
				}
				else if (stateMu == "ON MUSIC")
				{
					MusicBox->runningMusic(game);
					GotoXY(185, 22);
					stateMu = "OFF MUSIC";
					playmenu = false;
					CGUI::setcolor(244);
					cout << "OFF MUSIC ";
				}
			}
		}

		if (input == 'G' || input == 'g')
		{
			system("cls");
			cg->exitgame(&task);
			cg = new CGAME();
			if (stateMu == "OFF MUSIC")
			{
				MusicBox->stopMusic();
			}
			else if (stateMu == "ON MUSIC")
			{
				MusicBox->setMusic(game);
				MusicBox->runningMusic(game);
			}
			cg->control();
			break;
		}
		if (input == 'N' || input == 'n')
		{
			system("cls");
			cg->exitgame(&task);
			ScreenColor();
			cg = new CGAME();
			if (playmenu == true || stateMu == "ON MUSIC")
			{
				MusicBox2->setMusic(menu);
				MusicBox2->runningMusic(menu);
				state = " TURN ON MUSIC";
			}
			else if (playmenu == false || stateMu == "OFF MUSIC")
			{
				MusicBox2->stopMusic();
				state = " TURN OFF MUSIC";
			}
			break;
		}
	}
}

void SupportThread()
{
	cg->playGame();
}

void CGAME::pause()
{
	MusicBox->stopMusic();
	IS_RUNNING = false;
}

void CGAME::resume()
{
	if (stateMu == "OFF MUSIC")
	{
		MusicBox->stopMusic();
	}
	else if (stateMu == "ON MUSIC")
	{
		MusicBox->runningMusic(game);
	}
	IS_RUNNING = true;
}

void CGAME::exitgame(thread* t1)
{
	MusicBox->stopMusic();
	IS_RUNNING = false;
	t1->join();
}

void CGAME::savegame()
{
	char a;
	string headfile;
	MENU.drawbox(158, 38, 5, 45, 241, "   Enter name to save ");
	GotoXY(162, 41);
	CGUI::setcolor(250);
	cout << "Enter:";
	CGUI::setcolor(240);
	GotoXY(169, 41);
	getline(cin, headfile);
	string tailfile = ".txt";
	string file = headfile + tailfile;
	ofstream out;
	out.open("savefile.txt", ios::app);
	out << headfile << "\n";
	out.close();
	out.open(file);
	if (out.fail())
	{
		system("cls");
		MENU.drawbox(62, 22, 4, 70, 241, "Can't open this file! Press enter or esc to continue.");
		a = _getch();
	}
	else
	{
		int object = cg->getNumberOfObjects1();
		out << object << " ";
		for (int i = 0; i < numberOfObjects; i++)
		{
			out << axh[i].getX() << " " << axh[i].getY() << " ";
		}
		for (int i = 0; i < numberOfObjects; i++)
		{
			out << axt[i].getX() << " " << axt[i].getY() << " ";
		}
		for (int i = 0; i < numberOfObjects; i++)
		{
			out << akl[i].getX() << " " << akl[i].getY() << " ";
		}
		for (int i = 0; i < numberOfObjects; i++)
		{
			out << ac[i].getX() << " " << ac[i].getY() << " ";
		}
		out << cn->getmX() << " " << cn->getmY() << " ";
		out << cn->getMState() << " ";
		out << cg->getLevel();
		MENU.drawbox(62, 22, 5, 70, 241, "SAVE SUCCESSFULLY! Press enter or esc to continue.");
		a = _getch();
	}
	out.close();

}

bool CGAME::loadgame()
{
	char a;
	string ten, findname, tailfile = ".txt", filename;
	int find = 0;
	ifstream in;
	in.open("savefile.txt");

	GotoXY(74 + 16 + 5, 31);
	getline(cin, ten);
	while (!in.eof())
	{
		getline(in, findname);
		if (ten == findname) {
			find = 1;
			break;
		}
	}
	in.close();
	if (find == 1)
	{
		filename = ten + tailfile;
		in.open(filename);

		int numobjects;
		in >> numobjects;
		this->setNumberOfObjects1(numobjects);
		axh = new CCAR[numobjects];
		axt = new CTRUCK[numobjects];
		akl = new CDINOSOUR[numobjects];
		ac = new CBIRD[numobjects];
		cn = new CPEOPLE();
		//xe
		int* tempcar = new int[numobjects * 2];
		for (int i = 0; i < numobjects * 2; i += 2)
		{
			in >> tempcar[i];
			in >> tempcar[i + 1];
		}
		int so = 0;
		for (int i = 0; i < numobjects * 2; i += 2)
		{
			axh[so].setX(tempcar[i]);
			axh[so].setY(tempcar[i + 1]);
			so++;
		}
		delete[]tempcar;
		tempcar = NULL;
		//xe tai
		int* temptruck = new int[numobjects * 2];
		so = 0;
		for (int i = 0; i < numobjects * 2; i += 2)
		{
			in >> temptruck[i];
			in >> temptruck[i + 1];
		}
		for (int i = 0; i < numobjects * 2; i += 2)
		{
			axt[so].setX(temptruck[i]);
			axt[so].setY(temptruck[i + 1]);
			so++;
		}
		delete[]temptruck;
		temptruck = NULL;
		//khung long
		int* tempdino = new int[numobjects * 2];
		so = 0;
		for (int i = 0; i < numobjects * 2; i += 2)
		{
			in >> tempdino[i];
			in >> tempdino[i + 1];
		}
		for (int i = 0; i < numobjects * 2; i += 2)
		{
			akl[so].setX(tempdino[i]);
			akl[so].setY(tempdino[i + 1]);
			so++;
		}
		//chim
		int* tempbird = new int[numobjects * 2];
		so = 0;
		for (int i = 0; i < numobjects * 2; i += 2)
		{

			in >> tempbird[i];
			in >> tempbird[i + 1];
		}
		for (int i = 0; i < numobjects * 2; i += 2)
		{
			ac[so].setX(tempbird[i]);
			ac[so].setY(tempbird[i + 1]);
			so++;
		}
		delete[]tempbird;
		tempbird = NULL;
		//nguoi
		int x, y, level;
		bool state;

		in >> x >> y;
		cn->setmX(x);
		cn->setmY(y);

		in >> state;
		cn->setMState(state);

		in >> level;
		cg->setLevel(level);

		IS_RUNNING = true;
		in.close();
		return true;
	}
	return false;
}

void CGAME::updatePosVehicle(CVEHICLE* car, int y)
{
	int xLast;
	int maxObj = cg->getNumberOfObjects(); // Số object tối đa trong 1 level

	for (int i = 0; i < maxObj; i++)
	{
		CGUI::textcolor(240);
		int x = car[i].getX();
		int y = car[i].getY();

		if (i == 0)
		{
			deleteOldPos(x - 3, y, 14, 4);
			car[i].Move(x, y);//Di chuyển xe (in vị trí mới)
			car[i].setX(x + 3); //Cập nhật hoành độ mới
		}
		else if (i != 0)
		{
			if (car[i - 1].getX() >= LEFTSIDE + 25 || x >= LEFTSIDE + 25) // Tạo khoảng cách giữa các xe
			{
				deleteOldPos(x - 3, y, 14, 4); // Xóa vị trí cũ
				car[i].Move(x, y); // In vị trí mới
				car[i].setX(x + 3); // Cập nhật hoành độ mới
			}
		}

		if (car[i].getX() >= RIGHTSIDE - 15) //Xe đã đến biên phải
		{
			xLast = car[i].getX();
			car[i].setX(LEFTSIDE + 4);
			deleteOldPos(xLast - 3, y, 14, 4);//Xóa object cuối cùng
		};
		car[i].setY(y);

	}

};

void CGAME::updatePosAnimal(CANIMAL* animal, int y)
{
	CGUI::textcolor(240);
	int xLast;
	int maxObj = cg->getNumberOfObjects(); // Số object tối đa trong 1 level

	for (int i = 0; i < maxObj; i++)
	{
		int x = animal[i].getX();
		int y = animal[i].getY();

		if (i == 0)
		{
			deleteOldPos(x + 3, y, 15, 5);
			animal[i].Move(x, y);//Di chuyển thú (in vị trí mới)
			animal[i].setX(x - 3); //Cập nhật hoành độ mới
		}
		else if (i != 0)
		{

			if (animal[i - 1].getX() <= RIGHTSIDE - 37 || x <= RIGHTSIDE - 37) // Tạo khoảng cách giữa các con thú
			{
				deleteOldPos(x + 3, y, 15, 5); // Xóa vị trí cũ
				animal[i].Move(x, y); // In vị trí mới
				animal[i].setX(x - 3); // Cập nhật hoành độ mới
			}
		}

		if (animal[i].getX() <= LEFTSIDE) //Thú đã đến biên trái
		{
			xLast = animal[i].getX();
			animal[i].setX(RIGHTSIDE - 30);
			deleteOldPos(xLast + 3, y, 15, 5);//Xóa object cuối cùng
		}
		animal[i].setY(y);
	}
};

void CGAME::updatePosPeople(char MOVING)
{
	CGUI::textcolor(240);
	int xCu = cn->getmX();
	int yCu = cn->getmY();
	deleteOldPos(xCu, yCu, 6, 5);
	if (MOVING == 'W' || MOVING == 'w')
		cn->Up(7);
	else if (MOVING == 'S' || MOVING == 's')
		cn->Down(7);
	else if (MOVING == 'A' || MOVING == 'a')
		cn->Left(7);
	else if (MOVING == 'D' || MOVING == 'd')
		cn->Right(7);
	else if (MOVING == 'M' || MOVING == 'm')
	{

	}

	cn->printpeople(cn->getmX(), cn->getmY());
}

bool CGAME::controlTraffic(int x, int y, int mode, int timeZ)
{
	srand(time(0));
	clock_t TimeZero = clock(); //Start timer
	double deltaTime = 0;
	double secondsToDelay = 2;
	deltaTime = (((clock()) / CLOCKS_PER_SEC / timeZ % 2) + (mode)) % 2;

	int i = deltaTime;
	if (i)
	{

		GotoXY(x, y);
		CGUI::textcolor(170);
		cout << "  ";
		CGUI::textcolor(7);
		return true;
	}
	else
	{

		GotoXY(x, y);
		CGUI::textcolor(68);
		cout << "  ";
		CGUI::textcolor(7);
		return false;
	}

}
