#pragma once
#include "Usuario.h"

class NoUsuarios
{
public:
	NoUsuarios(Usuario *p_usuario);
	~NoUsuarios();

	Usuario* obterInfo();
	NoUsuarios* obterProx();
	void setProx(NoUsuarios* p_usuario);

private:
	Usuario *usuario;
	NoUsuarios *prox;
};