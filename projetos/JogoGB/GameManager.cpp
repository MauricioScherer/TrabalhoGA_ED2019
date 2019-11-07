#include "GameManager.h"

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::SaveSlot(int p_slot)
{
	Load();
}

void GameManager::Save()
{
	ofstream archive;
	archive.open("dados.bin", ios::binary);

	if (archive.is_open())
	{
		archive.write(reinterpret_cast<char *>(&playerSlot), sizeof(Player));
	}
	archive.close();
}

void GameManager::Load()
{
	ifstream archive;
	archive.open("dados.bin", ios::binary);

	if (archive.is_open())
	{
		archive.read(reinterpret_cast<char *>(&playerSlot), sizeof(Player));
	}

	archive.close();
}
