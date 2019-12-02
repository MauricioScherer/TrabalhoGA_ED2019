#pragma once
#include <iostream>
#include <stack>
#include "Tela.h"

using namespace std;

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
	
private:
	int statusGame;
	bool debug = false;

<<<<<<< HEAD
	Tela tela;
	stack<Tela> pilhaTela;
=======
	void startNewItem();
	void resetItem();
	void GameStart(int p_status);
	void collisionTest(int p_obj);
	void save();
	int load();
	
	Player player;
	Asteroid asteroid[4];
	Item *item;
	Usuario *_usuarioTemp;
	ListaUsuarios *listaUsuarios;

	Som music, damage, damageShip, powerUp, buttonEffect;
	Sprite sprTitle;
	Sprite background;
	BotaoSprite buttonStart;
	BotaoSprite buttonContinuar;
	BotaoSprite buttonGameOver;

>>>>>>> 3f09458483352b6dafd88691668698306e8bf3f9
};

