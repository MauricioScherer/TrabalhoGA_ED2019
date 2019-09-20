#include "Jogo.h"
#include <time.h>

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);
	uniRandSetSemente(time(NULL));

#pragma region Player

	gRecursos.carregarSpriteSheet("player", "assets/sprite/nave.png", 1, 1);

	player.setSpriteSheet("player");
	player.setPosition(gJanela.getLargura() / 2, gJanela.getAltura() - 30);
	player.setSpeed(1.0f);

#pragma endregion

#pragma region Asteroid

	gRecursos.carregarSpriteSheet("asteroid", "assets/sprite/asteroid.png", 1, 1);	
	asteroidStart();

#pragma endregion

}

void Jogo::finalizar()
{
	gRecursos.descarregarSpriteSheet("player");

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		
		if (gTeclado.segurando[TECLA_DIR] && player.getPosX() < gJanela.getLargura() - 20)
			player.moveRight();
		else if (gTeclado.segurando[TECLA_ESQ] && player.getPosX() > 20)
			player.moveLeft();

		if (gTeclado.segurando[TECLA_CIMA] && player.getPosY() > 40)
			player.moveUp();
		else if (gTeclado.segurando[TECLA_BAIXO] && player.getPosY() < gJanela.getAltura() - 40)
			player.moveDown();
		
		asteroid.update();

		if (asteroid.getPosY() > gJanela.getAltura() + 20)
			asteroidStart();

		collisionTest();
		asteroid.draw();
		player.draw();

		uniTerminarFrame();
	}
}

void Jogo::asteroidStart()
{
	int x, y;
	x = uniRandEntre(30, gJanela.getLargura() - 30);
	y = -30;
		
	asteroid.setSpriteSheet("asteroid");
	asteroid.setPosition(x, y);

	asteroid.setSpeed(uniRandEntre(1, 3));
	int scaleTemp = uniRandEntre(2, 6);
	asteroid.setScale(scaleTemp, scaleTemp);
}

void Jogo::collisionTest()
{
	if (uniTestarColisao(asteroid.getSprite(), asteroid.getPosX(), asteroid.getPosY(), asteroid.getRot(),
		player.getSprite(), player.getPosX(), player.getPosY(), player.getRot()))
	{
		asteroidStart();
	}
}
