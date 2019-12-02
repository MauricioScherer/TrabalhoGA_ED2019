#pragma once
#include "libUnicornio.h"
#include "Player.h"
#include "Asteroid.h"
#include "Item.h"
#include "Save.h"

class Tela
{
public:
	Tela();
	~Tela();

	void inicializar();
	void finalizar();
	void executar();

	bool getJogo();

private:
	bool isItemActive = false;
	int counterItem;
	int maxCounter;

	Sprite sprTitle, background, txtNome, creditos;
	BotaoSprite btnLogin, btnCadastro, btnSair, btnConfirmar, btnVoltar, btnJogar, btnContinuar, btnCreditos, btnRanking;
	Som music, buttonEffect, error, damage, damageShip, powerUp;
	Texto inputNome;

	Save save;
	Item *item;
	Player player;
	Asteroid asteroid[4];

	enum TelasJogo
	{
		INICIO,
		LOGIN,
		CADASTRO,
		MENU,
		JOGO,
		CREDITOS,
		RANKING
	};
	TelasJogo telaAtual;

	void GameStart();
	void collisionTest(int p_obj);
	void startNewItem();
	void resetItem();
	void atualizarInput();
	void desenharInput();
};

