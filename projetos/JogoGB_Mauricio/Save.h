#pragma once
#include <iostream>
#include <fstream>
#include "PlayerStatus.h"

using namespace std;

class Save
{
public:
	Save();
	~Save();

	void SaveStatus(PlayerStatus *p_player);
	PlayerStatus *LoadStatus();

private:
	PlayerStatus *_playerStatus;
};

