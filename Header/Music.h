#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <thread>

using namespace std;
#define accident "_AccidentSound.wav"
#define ambulance "_AmbulanceSound.wav"
#define gameover "_GameoverSound.wav"
#define menu "_MenuSound.wav"
#define wingame "_WingameSound.wav"
#define game "_GameSound.wav"

class Music
{
private:
	string nameFile;
	static inline Music* intance = NULL;
	bool isRunning;
	bool isMute;
	bool changed;
	Music()
	{
		this->nameFile = "";
		this->intance = NULL;
		isRunning = false;
		isMute = false;
		changed = false;
	}
public:
	bool getIsRunning()
	{
		return isRunning;
	}

	void setIsRunning(bool _running)
	{
		isRunning = _running;
	}

	static Music* getInstance()
	{
		if (intance == NULL)
		{
			intance = new Music();
		}
		return intance;

	}

	void runningMusic(string name)
	{
		if (isMute == true && this->nameFile == name)
		{
			PlaySound(NULL, NULL, SND_LOOP | SND_ASYNC);
			return;
		}

		wstring temp = wstring(nameFile.begin(), nameFile.end());
		PlaySound(temp.c_str(), NULL, SND_LOOP | SND_ASYNC);
		isRunning = true;

	}
	void Mute()
	{
		isMute = !isMute;
	}
	void Changed()
	{
		changed = true;

	}
	bool getChanged()
	{
		return changed;
	}
	void Unchanged()
	{
		changed = false;
	}
	void stopMusic()
	{
		if (isRunning == true || isMute == false || this->nameFile != " ")
		{
			isRunning = false;
			PlaySound(NULL, NULL, SND_LOOP | SND_ASYNC);

		}
	}
	void setMusic(string name)
	{
		isRunning = false;
		this->nameFile = name;
	}
	~Music()
	{
		delete this->intance;
	}

	static void PlayingSound1time(string name);
};



