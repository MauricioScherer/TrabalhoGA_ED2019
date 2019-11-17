#pragma once
#include <fstream>
#include "Usuario.h"

class Arquivos
{
public:
	Arquivos();
	~Arquivos();

	void save(Usuario *p_usuarios);
	void load();

private:
	Usuario * usuarios;
};

