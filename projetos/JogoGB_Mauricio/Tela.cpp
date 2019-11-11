#include "Tela.h"

Tela::Tela()
{
}

Tela::Tela(std::string tto)
{
}

Tela::~Tela()
{
}

void Tela::inicializar()
{
}

void Tela::finalizar()
{
}

void Tela::atualizar()
{
}

void Tela::desenhar()
{
}

Tela * Tela::obtemProximaTela()
{
	return nullptr;
}

std::string Tela::obtemTitulo()
{
	return this->titulo;
}

void Tela::defineTitulo(std::string tto)
{
	this->titulo = tto;
}
