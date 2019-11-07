#include "UserManager.h"

UserManager::UserManager()
{
}

UserManager::~UserManager()
{
}

void UserManager::Save()
{
	ofstream archive;
	archive.open("dados.bin", ios::binary);

	if (archive.is_open())
	{
		archive.write(reinterpret_cast<char *>(&points), sizeof(int));
	}
	archive.close();
}

void UserManager::Load()
{
	ifstream archive;
	archive.open("dados.bin", ios::binary);

	int __points;

	if (!archive.is_open())
	{
		return 0;
	}
	else
	{
		archive.read(reinterpret_cast<char *>(&__points), sizeof(int));
		return __points;
	}
}
