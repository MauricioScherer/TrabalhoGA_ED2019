#include "NoUsuarios.h"

NoUsuarios::NoUsuarios(Usuario * p_usuario)
{
	usuario = p_usuario;
	prox = nullptr;
}

NoUsuarios::~NoUsuarios()
{
}

Usuario * NoUsuarios::obterInfo()
{
	return usuario;
}

NoUsuarios * NoUsuarios::obterProx()
{
	return prox;
}

void NoUsuarios::setProx(NoUsuarios * p_usuario)
{
	prox = p_usuario;
}
