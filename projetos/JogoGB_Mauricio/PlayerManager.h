#pragma once
#include <string>

using namespace std;

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();

	string GetLogin();
	string GetPassword();
	int getPoints();

private:
	string login, password;
	int points;
};

