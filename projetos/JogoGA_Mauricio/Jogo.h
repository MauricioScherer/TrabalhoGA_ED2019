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
	void collisionTest(int p_obj);
	Player player;
	Asteroid asteroid[2];
};

