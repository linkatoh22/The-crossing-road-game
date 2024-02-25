#include "Music.h"
using namespace std;

void Music::PlayingSound1time(string name)
{
	wstring temp = wstring(name.begin(), name.end());
	PlaySound(temp.c_str(), NULL, SND_SYNC);

	return;
}

