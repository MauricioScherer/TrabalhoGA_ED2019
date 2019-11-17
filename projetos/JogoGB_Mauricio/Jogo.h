#pragma once
#include "Player.h"
#include "Asteroid.h"
#include "Item.h"
#include "ListaUsuarios.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
	
private:
	int counterItem;
	int maxCounter;
	int points;
	int statusGame;
	bool isItemActive = false;
	bool debug = false;

	void startNewItem();
	void resetItem();
	void GameStart(int p_status);
	void collisionTest(int p_obj);
	void save();
	int load();
	
	Player player;
	Asteroid asteroid[4];
	Item *item;
	ListaUsuarios *listaUsuarios;

	Som music, damage, damageShip, powerUp, buttonEffect;
	Sprite sprTitle;
	Sprite background;
	BotaoSprite buttonStart;
	BotaoSprite buttonContinuar;
	BotaoSprite buttonGameOver;

};

