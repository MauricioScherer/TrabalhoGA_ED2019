#pragma once
#include <fstream>
#include "NoUsuarios.h"

class ListaUsuarios
{
public:
	ListaUsuarios();
	ListaUsuarios(Usuario *p_usuario);
	~ListaUsuarios();

	void mostrarPontos();
	void inserirFinal(Usuario *p_usuario);
	bool existe(Usuario *p_usuario);
	Usuario* obtemElemento(Usuario *p_usuario);

	void saveUsuarios();
	void loadUsuarios();

private:
	NoUsuarios *cabeca;
	NoUsuarios *cauda;
};

