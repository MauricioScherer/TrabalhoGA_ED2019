#pragma once
#include "PlayerManager.h"
#include <fstream>

using namespace std;

class UserManager : public PlayerManager
{
public:
	UserManager();
	~UserManager();

	void Save();
	void Load();
};

