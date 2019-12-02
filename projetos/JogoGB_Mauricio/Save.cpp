#include "Save.h"



Save::Save()
{
}


Save::~Save()
{
}

void Save::SaveStatus(PlayerStatus *p_player)
{
	ofstream archive;
	archive.open("dados.bin", ios::binary);

	if (archive.is_open())
	{
		archive.write(reinterpret_cast<char *>(&p_player), sizeof(PlayerStatus));
	}
	archive.close();
}

PlayerStatus *Save::LoadStatus()
{
	ifstream archive;
	archive.open("dados.bin", ios::binary);

	if (archive.is_open())
	{
		archive.read(reinterpret_cast<char *>(&_playerStatus), sizeof(PlayerStatus));
		return _playerStatus;
	}
	else
	{
		return nullptr;
	}
}
