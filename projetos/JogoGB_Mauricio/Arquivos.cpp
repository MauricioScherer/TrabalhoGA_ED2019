#include "Arquivos.h"

Arquivos::Arquivos()
{
}


Arquivos::~Arquivos()
{
}

void Arquivos::save(Usuario *p_usuarios)
{
	ofstream archive;
	archive.open("usuarios.bin", ios::binary);

	if (archive.is_open())
	{
		archive.write(reinterpret_cast<char *>(&p_usuarios), sizeof(Usuario));
	}
	archive.close();
}

void Arquivos::load()
{
	ifstream archive;
	archive.open("usuarios.bin", ios::binary);

	if (archive.is_open())
	{
		archive.read(reinterpret_cast<char *>(&usuarios), sizeof(Usuario));
	}
	archive.close();
}
