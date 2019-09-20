#pragma once
#include "Player.h"
#include "Asteroid.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();

private:
	void asteroidStart();
	void collisionTest();

	Player player;
	Asteroid asteroid;
};

