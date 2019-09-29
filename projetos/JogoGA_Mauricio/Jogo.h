#pragma once
#include "Player.h"
#include "Asteroid.h"
#include "Item.h"

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
	bool isItemActive = false;
	int points;
	int statusGame;
	void collisionTest(int p_obj);

	Player player;
	Asteroid asteroid[2];
	Item *item;

	Sprite sprTitle;
	BotaoSprite buttonStart;
	BotaoSprite buttonGameOver;

	void startNewItem();
	void resetItem();
	void setColorBackground();
	void GameStart();
	void save();
	int load();
};

