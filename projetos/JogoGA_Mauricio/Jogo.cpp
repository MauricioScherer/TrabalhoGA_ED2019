#include "Jogo.h"
#include <time.h>
#include <fstream>

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

	statusGame = 0;

	gRecursos.carregarSpriteSheet("player", "assets/sprite/nave.png", 1, 1);
	gRecursos.carregarSpriteSheet("tiro", "assets/sprite/tiro.png", 1, 1);	
	player.setSpriteSheet("player");
	player.tiroSetSpriteSheet("tiro");

	item = new Item();
	item->itemInicializar();

	maxCounter = uniRandEntre(100, 500);
	counterItem = 0;
	
	gRecursos.carregarSpriteSheet("title", "assets/sprite/title.png", 1, 1);
	sprTitle.setSpriteSheet("title");


#pragma region Buttons

	gRecursos.carregarSpriteSheet("buttonStart", "assets/sprite/ButtonStart.png", 3, 1);
	buttonStart.setSpriteSheet("buttonStart");
	buttonStart.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 100);

	gRecursos.carregarSpriteSheet("buttonGameOver", "assets/sprite/ButtonGameOver.png", 3, 1);
	buttonGameOver.setSpriteSheet("buttonGameOver");
	buttonGameOver.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

#pragma endregion


#pragma region Asteroid

	gRecursos.carregarSpriteSheet("asteroid", "assets/sprite/asteroid.png", 1, 1);
	asteroid[0].setSpriteSheet("asteroid");
	asteroid[1].setSpriteSheet("asteroid");

#pragma endregion
}

void Jogo::finalizar()
{
	save();
	gRecursos.descarregarSpriteSheet("player");
	gRecursos.descarregarSpriteSheet("asteroid");
	gRecursos.descarregarSpriteSheet("tiro");
	gRecursos.descarregarSpriteSheet("buttonStart");
	gRecursos.descarregarSpriteSheet("buttonGameOver");

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		
		setColorBackground();

		switch (statusGame)
		{
		case 0:
			sprTitle.desenhar(gJanela.getLargura() / 2 , gJanela.getAltura() / 2 - 150);
			buttonStart.atualizar();
			buttonStart.desenhar();

			if (buttonStart.estaClicado())
			{
				GameStart();
			}
			break;
		case 1:
			player.move();
			player.shoot();
			player.draw();

			for (int i = 0; i < 2; i++)
			{
				asteroid[i].update();
				asteroid[i].draw();
				collisionTest(i);
			}

			if (!isItemActive)
				counterItem += 1;
			else
				item->draw();

			if (counterItem >= maxCounter && !isItemActive)
			{
				startNewItem();
				isItemActive = true;
			}
			break;
		case 2:
			buttonGameOver.atualizar();
			buttonGameOver.desenhar();

			if (buttonGameOver.estaClicado())
				statusGame = 0;
			break;
		default:
			break;
		}

		if (statusGame == 1)
		{
			string txt = "pos X: " + to_string(player.getPosX()) + "\n" +
				"pos Y: " + to_string(player.getPosY()) + "\n" +
				"pode atirar: " + to_string(player.getIsShoot()) + "\n" +
				"counterMax: " + to_string(maxCounter) + "\n" +
				"counter: " + to_string(counterItem);

			gGraficos.desenharTexto(txt, 25, 25, 255, 255, 255, 255, 0, 0);

			string pointsStr = "pontos: " + to_string(points);
			gGraficos.desenharTexto(pointsStr, gJanela.getLargura() - 25, 25, 255, 255, 255, 255, 1, 0);
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

		if (points > 0)
			points -= 10;
		else
			statusGame = 2;
	}

	if (uniTestarColisao(asteroid[p_obj].getSprite(), asteroid[p_obj].getPosX(), asteroid[p_obj].getPosY(), 0,
		player.tiroGetSprite(), player.tiroGetPosX(), player.tiroGetPosY(), 0))
	{
		asteroid[p_obj].asteroidStart();
		player.tiroSetPosition(0, 0);
		player.setIsShoot(false);
		points += 10;
	}

	if (item)
	{
		if (uniTestarColisao(item->getSprite(), item->getPosX(), item->getPosY(), 0,
			player.getSprite(), player.getPosX(), player.getPosY(), 0))
		{
			if (item->getPowerUp() == 0)
				player.setSpeed(item->getSpeed());
			else if (item->getPowerUp() == 1)
				player.tiroSetSpeed(item->getSpeed());

			resetItem();
		}
	}
}

void Jogo::startNewItem()
{
	int posX = uniRandEntre(10, gJanela.getLargura() - 10);
	int posY = uniRandEntre(10, gJanela.getAltura() - 10);
	int type = uniRandEntre(0, 1);

	item->startNewItem(posX, posY, type);
}

void Jogo::resetItem()
{
	counterItem = 0;
	maxCounter = uniRandEntre(500, 1500);
	isItemActive = false;
}

void Jogo::setColorBackground()
{
	if(gTeclado.soltou[TECLA_0])
		gJanela.setCorDeFundo(0,0,0);
	else if (gTeclado.soltou[TECLA_1])
		gJanela.setCorDeFundo(255, 255, 255);
	else if (gTeclado.soltou[TECLA_2])
		gJanela.setCorDeFundo(255, 0, 0);
	else if (gTeclado.soltou[TECLA_3])
		gJanela.setCorDeFundo(0, 255, 0);
	else if (gTeclado.soltou[TECLA_4])
		gJanela.setCorDeFundo(0, 0, 255);
}

void Jogo::GameStart()
{
	points = load();
	statusGame = 1;

	player.playerInicializar();

	asteroid[0].asteroidStart();
	asteroid[1].asteroidStart();
}

void Jogo::save()
{
	ofstream archive;
	archive.open("dados.bin", ios::binary);

	if (archive.is_open())
	{
		archive.write(reinterpret_cast<char *>(&points), sizeof(int));
	}
	archive.close();
}

int Jogo::load()
{
	ifstream archive;
	archive.open("dados.bin", ios::binary);

	int __points;

	if (!archive.is_open())
	{
		return 0;
	}
	else
	{
		archive.read(reinterpret_cast<char *>(&__points), sizeof(int));
		return __points;
	}
}
