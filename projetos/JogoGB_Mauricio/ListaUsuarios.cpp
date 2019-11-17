#include "ListaUsuarios.h"

ListaUsuarios::ListaUsuarios()
{
	cabeca = NULL;
	cauda = NULL;
}

ListaUsuarios::ListaUsuarios(Usuario *p_usuario)
{
	cabeca = new NoUsuarios(p_usuario);
	cauda = cabeca;
}


ListaUsuarios::~ListaUsuarios()
{
	delete cabeca;
}

void ListaUsuarios::mostrarPontos()
{
	NoUsuarios* c = cabeca;

	if (cabeca == NULL)
	{
		//sem dados na lista
	}
	else
	{
		while (c)
		{
			c->obterInfo()->getPoints();
			c = c->obterProx();
		}
	}
}

void ListaUsuarios::inserirFinal(Usuario * p_usuario)
{
	NoUsuarios* novoNo = new NoUsuarios(p_usuario);

	if (cabeca == NULL)
	{
		cabeca = novoNo;
		cauda = novoNo;
	}
	else
	{
		cauda->setProx(novoNo);
		cauda = novoNo;
	}
}

bool ListaUsuarios::existe(Usuario * p_usuario)
{
	NoUsuarios* c = cabeca;

	while (c)
	{
		if (c->obterInfo()->getName() == p_usuario->getName())
			return true;
		c = c->obterProx();
	}
	return false;
}

Usuario* ListaUsuarios::obtemElemento(Usuario * p_usuario)
{
	if (cabeca == NULL)
	{
		return NULL;
	}

	NoUsuarios* c = cabeca;

	while (c->obterInfo()->getName() != p_usuario->getName())
	{
		c = c->obterProx();
	}

	return c->obterInfo();
}

void ListaUsuarios::saveUsuarios()
{	
	NoUsuarios* c = cabeca;
	Usuario *_user[5];

	int tam = 0;

	if (cabeca != NULL)
	{
		while (tam < 5 && c)
		{
			_user[tam] = c->obterInfo();
			c = c->obterProx();
			tam++;
		}
	}

	ofstream archive;
	archive.open("usuarios.bin", ios::binary);

	if (archive.is_open())
	{
		archive.write(reinterpret_cast<char *>(&_user), sizeof(Usuario));
	}
	archive.close();
}

void ListaUsuarios::loadUsuarios()
{

}