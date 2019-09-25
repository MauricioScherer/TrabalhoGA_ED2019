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
	asteroid[0].setSpriteSheet("asteroid");
	asteroid[1].setSpriteSheet("asteroid");
	asteroid[0].asteroidStart();
	asteroid[1].asteroidStart();

#pragma endregion

}

void Jogo::finalizar()
{
	gRecursos.descarregarSpriteSheet("player");
	gRecursos.descarregarSpriteSheet("asteroid");

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		
		player.move();
		player.draw();
		
		for (int i = 0; i < 2; i++)
		{
			asteroid[i].update();
			asteroid[i].draw();
			collisionTest(i);
		}

		uniTerminarFrame();
	}
}

void Jogo::collisionTest(int p_obj)
{
	if (uniTestarColisao(asteroid[p_obj].getSprite(), asteroid[p_obj].getPosX(), asteroid[p_obj].getPosY(), 0,
		player.getSprite(), player.getPosX(), player.getPosY(), player.getRot()))
	{
		asteroid[p_obj].asteroidStart();
	}
}
