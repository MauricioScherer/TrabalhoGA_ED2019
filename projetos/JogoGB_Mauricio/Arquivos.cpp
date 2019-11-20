#include "Arquivos.h"

Arquivos::Arquivos()
{
}


Arquivos::~Arquivos()
{
}

void Arquivos::OpenArquivo(string p_name)
{
	arquivoLocal.open(p_name, ios::binary);
}

void Arquivos::CloseArquivo()
{
	arquivoLocal.close();
}

bool Arquivos::arquivoIsOpen()
{
	return arquivoLocal.is_open();
}

void Arquivos::save(Usuario *p_usuarios)
{
	arquivoLocal.write(reinterpret_cast<char *>(&p_usuarios), sizeof(Usuario));
}

void Arquivos::load()
{
	arquivoLocal.read(reinterpret_cast<char *>(&usuarios), sizeof(Usuario));
}
