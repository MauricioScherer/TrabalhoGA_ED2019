#pragma once
#include "libUnicornio.h"
#include "Menu.h"
#include "TelaJogar.h"
#include "TelaCreditos.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();	

	stack<Tela*> pilha;

	Menu menu;
	TelaJogar jogar;
	TelaCreditos creditos;
};

