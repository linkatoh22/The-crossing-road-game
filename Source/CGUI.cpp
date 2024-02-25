#include "CGUI.h"

void CGUI::printRoad()
{
	for (int i = 1; i < 6; i++)
	{
		for (int j = 31; j < 152; j++)
		{
			GotoXY(j, 2 + 7 * i);
			cout << "-";
		}
	}
	GotoXY(30, 2);
	cout << char(220);
	for (int i = 31; i < 152; i++)
	{
		GotoXY(i, 2);
		cout << char(223);
		GotoXY(i, 44);
		cout << char(220);
	}
	GotoXY(30, 44);

	cout << char(223);
	GotoXY(152, 2);

	cout << char(220);
	for (int i = 3; i < 44; i++)
	{
		GotoXY(152, i);
		cout << char(222);
		GotoXY(30, i);
		cout << char(221);
	}
	GotoXY(152, 44);
	cout << char(223);
};

void CGUI::textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void deleteOldPos(int x, int y, int width_of_object, int height_of_object)
{
	for (int i = 0; i < height_of_object; i++) {

		for (int j = x; j <= x + width_of_object; j++) {
			GotoXY(j, y);
			wcout << " ";
		};
		y++;

	};
};

void CGUI::setcolor(int code) // code = a*16+b, a: background, b: text;
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}

void CGUI::loser()
{
	setcolor(244);
	GotoXY(22, 3);
	cout << "        GGGGGGGGGGGGG                                                                                                                                                ";
	GotoXY(22, 4);
	cout << "     GGG::::::::::::G                                                                                                                                                ";
	GotoXY(22, 5);
	cout << "   GG:::::::::::::::G                                                                                                                                                ";
	GotoXY(22, 6);
	cout << "  G:::::GGGGGGGG::::G                                                                                                                                                ";
	GotoXY(22, 7);
	cout << " G:::::G       GGGGGG  aaaaaaaaaaaaa      mmmmmmm    mmmmmmm       eeeeeeeeeeee            ooooooooooo vvvvvvv           vvvvvvv eeeeeeeeeeee    rrrrr   rrrrrrrrr   ";
	GotoXY(22, 8);
	cout << "G:::::G                a::::::::::::a   mm:::::::m  m:::::::mm   ee::::::::::::ee        oo:::::::::::oov:::::v         v:::::vee::::::::::::ee  r::::rrr:::::::::r  ";
	GotoXY(22, 9);
	cout << "G:::::G                aaaaaaaaa:::::a m::::::::::mm::::::::::m e::::::eeeee:::::ee     o:::::::::::::::ov:::::v       v:::::ve::::::eeeee:::::eer:::::::::::::::::r ";
	GotoXY(22, 10);
	cout << "G:::::G    GGGGGGGGGG           a::::a m::::::::::::::::::::::me::::::e     e:::::e     o:::::ooooo:::::o v:::::v     v:::::ve::::::e     e:::::err::::::rrrrr::::::r";
	GotoXY(22, 11);
	cout << "G:::::G    G::::::::G    aaaaaaa:::::a m:::::mmm::::::mmm:::::me:::::::eeeee::::::e     o::::o     o::::o  v:::::v   v:::::v e:::::::eeeee::::::e r:::::r     r:::::r";
	GotoXY(22, 12);
	cout << "G:::::G    GGGGG::::G  aa::::::::::::a m::::m   m::::m   m::::me:::::::::::::::::e      o::::o     o::::o   v:::::v v:::::v  e:::::::::::::::::e  r:::::r     rrrrrrr";
	GotoXY(22, 13);
	cout << "G:::::G        G::::G a::::aaaa::::::a m::::m   m::::m   m::::me::::::eeeeeeeeeee       o::::o     o::::o    v:::::v:::::v   e::::::eeeeeeeeeee   r:::::r            ";
	GotoXY(22, 14);
	cout << " G:::::G       G::::Ga::::a    a:::::a m::::m   m::::m   m::::me:::::::e                o::::o     o::::o     v:::::::::v    e:::::::e            r:::::r            ";
	GotoXY(22, 15);
	cout << "  G:::::GGGGGGGG::::Ga::::a    a:::::a m::::m   m::::m   m::::me::::::::e               o:::::ooooo:::::o      v:::::::v     e::::::::e           r:::::r            ";
	GotoXY(22, 16);
	cout << "   GG:::::::::::::::Ga:::::aaaa::::::a m::::m   m::::m   m::::m e::::::::eeeeeeee       o:::::::::::::::o       v:::::v       e::::::::eeeeeeee   r:::::r            ";
	GotoXY(22, 17);
	cout << "     GGG::::::GGG:::G a::::::::::aa:::am::::m   m::::m   m::::m  ee:::::::::::::e        oo:::::::::::oo         v:::v         ee:::::::::::::e   r:::::r            ";
	GotoXY(22, 18);
	cout << "        GGGGGG   GGGG  aaaaaaaaaa  aaaammmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee          ooooooooooo            vvv            eeeeeeeeeeeeee   rrrrrrr            ";
}

void CGUI::winner()
{
	setcolor(246);
	GotoXY(22, 3);
	cout << "WWWWWWWW                           WWWWWWWW iiii                                                                                                          !!! ";
	GotoXY(22, 4);
	cout << "W::::::W                           W::::::Wi::::i                                                                                                        !!:!!";
	GotoXY(22, 5);
	cout << "W::::::W                           W::::::W iiii                                                                                                         !:::!";
	GotoXY(22, 6);
	cout << "W::::::W                           W::::::W                                                                                                              !:::!";
	GotoXY(22, 7);
	cout << " W:::::W           WWWWW           W:::::Wiiiiiiinnnn  nnnnnnnn            ggggggggg   ggggg aaaaaaaaaaaaa      mmmmmmm    mmmmmmm       eeeeeeeeeeee    !:::!";
	GotoXY(22, 8);
	cout << "  W:::::W         W:::::W         W:::::W i:::::in:::nn::::::::nn         g:::::::::ggg::::g a::::::::::::a   mm:::::::m  m:::::::mm   ee::::::::::::ee  !:::!";
	GotoXY(22, 9);
	cout << "   W:::::W       W:::::::W       W:::::W   i::::in::::::::::::::nn       g:::::::::::::::::g aaaaaaaaa:::::a m::::::::::mm::::::::::m e::::::eeeee:::::ee!:::!";
	GotoXY(22, 10);
	cout << "    W:::::W     W:::::::::W     W:::::W    i::::inn:::::::::::::::n     g::::::ggggg::::::gg          a::::a m::::::::::::::::::::::me::::::e     e:::::e!:::!";
	GotoXY(22, 11);
	cout << "     W:::::W   W:::::W:::::W   W:::::W     i::::i  n:::::nnnn:::::n     g:::::g     g:::::g    aaaaaaa:::::a m:::::mmm::::::mmm:::::me:::::::eeeee::::::e!:::!";
	GotoXY(22, 12);
	cout << "      W:::::W W:::::W W:::::W W:::::W      i::::i  n::::n    n::::n     g:::::g     g:::::g  aa::::::::::::a m::::m   m::::m   m::::me:::::::::::::::::e !:::!";
	GotoXY(22, 13);
	cout << "       W:::::W:::::W   W:::::W:::::W       i::::i  n::::n    n::::n     g:::::g     g:::::g a::::aaaa::::::a m::::m   m::::m   m::::me::::::eeeeeeeeeee  !!:!!";
	GotoXY(22, 14);
	cout << "        W:::::::::W     W:::::::::W        i::::i  n::::n    n::::n     g::::::g    g:::::ga::::a    a:::::a m::::m   m::::m   m::::me:::::::e            !!! ";
	GotoXY(22, 15);
	cout << "         W:::::::W       W:::::::W        i::::::i n::::n    n::::n     g:::::::ggggg:::::ga::::a    a:::::a m::::m   m::::m   m::::me::::::::e               ";
	GotoXY(22, 16);
	cout << "          W:::::W         W:::::W         i::::::i n::::n    n::::n      g::::::::::::::::ga:::::aaaa::::::a m::::m   m::::m   m::::m e::::::::eeeeeeee   !!! ";
	GotoXY(22, 17);
	cout << "           W:::W           W:::W          i::::::i n::::n    n::::n       gg::::::::::::::g a::::::::::aa:::am::::m   m::::m   m::::m  ee:::::::::::::e  !!:!!";
	GotoXY(22, 18);
	cout << "            WWW             WWW           iiiiiiii nnnnnn    nnnnnn         gggggggg::::::g  aaaaaaaaaa  aaaammmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee   !!! ";
	GotoXY(22, 19);
	cout << "                                                                                    g:::::g                                                                   ";
	GotoXY(22, 20);
	cout << "                                                                        gggggg      g:::::g                                                                   ";
	GotoXY(22, 21);
	cout << "                                                                        g:::::gg   gg:::::g                                                                   ";
	GotoXY(22, 22);
	cout << "                                                                         g::::::ggg:::::::g                                                                   ";
	GotoXY(22, 23);
	cout << "                                                                          gg:::::::::::::g                                                                    ";
	GotoXY(22, 24);
	cout << "                                                                            ggg::::::ggg                                                                      ";
	GotoXY(22, 25);
	cout << "                                                                               gggggg                                                                         ";
}

