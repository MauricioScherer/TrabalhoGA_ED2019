#pragma once
#include <fstream>
#include "Usuario.h"

class Arquivos
{
public:
	Arquivos();
	~Arquivos();

	void OpenArquivo(string p_name);
	void CloseArquivo();
	bool arquivoIsOpen();
	void save(Usuario *p_usuarios);
	void load();

private:
	Usuario * usuarios;
	fstream arquivoLocal;
};

