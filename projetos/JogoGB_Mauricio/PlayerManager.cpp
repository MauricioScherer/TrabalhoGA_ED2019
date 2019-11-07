#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

string PlayerManager::GetLogin()
{
	return login;
}

string PlayerManager::GetPassword()
{
	return password;
}

int PlayerManager::getPoints()
{
	return points;
}
