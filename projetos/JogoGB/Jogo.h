#pragma once
#include "libUnicornio.h"
#include "Menu.h"
#include "TelaJogar.h"
#include "TelaCreditos.h"
#include "Player.h"
#include "GameManager.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();	

	GameManager gameManager;
	Player *player;

	stack<Tela*> pilha;
	Menu menu;
	TelaJogar jogar;
	TelaCreditos creditos;
};

