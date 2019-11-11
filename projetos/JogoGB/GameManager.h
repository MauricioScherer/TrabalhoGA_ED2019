#pragma once
#include <fstream>
#include "Player.h"

using namespace std;

class GameManager
{
public:
	GameManager();
	~GameManager();

	void SaveSlot(int p_slot);	

private:
	Player *playerSlot;
	Player playerCurrent;

	void Save();
	void Load();
};

