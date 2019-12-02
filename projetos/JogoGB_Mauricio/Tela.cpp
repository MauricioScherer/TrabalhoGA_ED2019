#include "Tela.h"



Tela::Tela()
{
	telaAtual = INICIO;
}


Tela::~Tela()
{
}

void Tela::inicializar()
{
	gRecursos.carregarSpriteSheet("title", "assets/sprite/title.png", 1, 1);
	sprTitle.setSpriteSheet("title");
	sprTitle.setEscala(0.75f, 0.75f);

	player.inicializar();
	asteroid->inicializar();
	asteroid[0].setSpriteSheet("asteroid");
	asteroid[1].setSpriteSheet("asteroid");
	asteroid[2].setSpriteSheet("asteroid");
	asteroid[3].setSpriteSheet("asteroid");

	item = new Item();
	item->itemInicializar();

	maxCounter = uniRandEntre(100, 500);
	counterItem = 0;
	player.playerStatus = new PlayerStatus();

#pragma region TELAINCIO
	gRecursos.carregarSpriteSheet("btnLogin", "assets/sprite/BtnLogar.png", 3, 1);
	btnLogin.setSpriteSheet("btnLogin");
	btnLogin.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 100);

	gRecursos.carregarSpriteSheet("btnCadastro", "assets/sprite/BtnCadastrar.png", 3, 1);
	btnCadastro.setSpriteSheet("btnCadastro");
	btnCadastro.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 175);

	gRecursos.carregarSpriteSheet("btnSair", "assets/sprite/BtnSair.png", 3, 1);
	btnSair.setSpriteSheet("btnSair");
	btnSair.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 250);
#pragma endregion

#pragma region TELALOGIN
	gRecursos.carregarFonte("fonte", "assets/fonte/arial.ttf", 24);
	inputNome.setFonte("fonte");
	inputNome.setString("");

	gRecursos.carregarSpriteSheet("txtNome", "assets/sprite/TexNome.png", 1, 1);
	txtNome.setSpriteSheet("txtNome");

	gRecursos.carregarSpriteSheet("btnConfirmar", "assets/sprite/BtnConfirmar.png", 3, 1);
	btnConfirmar.setSpriteSheet("btnConfirmar");
	btnConfirmar.setPos(gJanela.getLargura() - 100, gJanela.getAltura() - 50);

	gRecursos.carregarSpriteSheet("btnVoltar", "assets/sprite/btnVoltar.png", 3, 1);
	btnVoltar.setSpriteSheet("btnVoltar");
	btnVoltar.setPos(100, gJanela.getAltura() - 50);
#pragma endregion

#pragma region TELAMENU
	gRecursos.carregarSpriteSheet("btnJogar", "assets/sprite/ButtonStart2.png", 3, 1);
	btnJogar.setSpriteSheet("btnJogar");
	btnJogar.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 50);

	gRecursos.carregarSpriteSheet("btnContinuar", "assets/sprite/ButtonContinuar.png", 3, 1);
	btnContinuar.setSpriteSheet("btnContinuar");
	btnContinuar.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 25);

	gRecursos.carregarSpriteSheet("btnCreditos", "assets/sprite/BtnCreditos.png", 3, 1);
	btnCreditos.setSpriteSheet("btnCreditos");
	btnCreditos.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 100);

	gRecursos.carregarSpriteSheet("btnRanking", "assets/sprite/BtnRanking.png", 3, 1);
	btnRanking.setSpriteSheet("btnRanking");
	btnRanking.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 175);
#pragma endregion

#pragma region TELACREDITOS
	gRecursos.carregarSpriteSheet("creditos", "assets/sprite/TelaCreditos.png", 1, 1);
	creditos.setSpriteSheet("creditos");
#pragma endregion

#pragma region SONS
	gRecursos.carregarAudio("music", "assets/audio/music2.wav");
	music.setAudio("music");
	music.tocar(true);

	gRecursos.carregarSpriteSheet("background", "assets/sprite/backGround2.png", 1, 1);
	background.setSpriteSheet("background");

	gRecursos.carregarAudio("ButtonEffect", "assets/audio/buttonEffect.wav");
	buttonEffect.setAudio("ButtonEffect");

	gRecursos.carregarAudio("error", "assets/audio/error.wav");
	error.setAudio("error");

	gRecursos.carregarAudio("damage", "assets/audio/damage.mp3");
	damage.setAudio("damage");

	gRecursos.carregarAudio("damageShip", "assets/audio/naveColider.wav");
	damageShip.setAudio("damageShip");

	gRecursos.carregarAudio("powerUp", "assets/audio/powerUp.wav");
	powerUp.setAudio("powerUp"); 
#pragma endregion

}

void Tela::finalizar()
{
	gRecursos.descarregarTudo();
}

void Tela::executar()
{
	background.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	switch (telaAtual)
	{
	case INICIO:
		sprTitle.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 200);

		btnLogin.atualizar();
		btnLogin.desenhar();
		btnCadastro.atualizar();
		btnCadastro.desenhar();
		btnSair.atualizar();
		btnSair.desenhar();

		if (btnLogin.estaClicado())
		{
			telaAtual = LOGIN;
			buttonEffect.tocar();
			gTeclado.inputTexto.habilitar();
		}
		else if (btnCadastro.estaClicado())
		{
			telaAtual = CADASTRO;
			buttonEffect.tocar();
			gTeclado.inputTexto.habilitar();
		}
		else if (btnSair.estaClicado())
		{
			buttonEffect.tocar();
			gEventos.sair = true;
		}
		break;
	case LOGIN:
		sprTitle.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 200);
		txtNome.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 100);

		btnConfirmar.atualizar();
		btnConfirmar.desenhar();
		btnVoltar.atualizar();
		btnVoltar.desenhar();
		atualizarInput();
		desenharInput();

		if (btnConfirmar.estaClicado())
		{
			//irá fazer a verificação se o usuario com esse nome e esta cadastrado
			PlayerStatus *p = new PlayerStatus();
			if (save.LoadStatus() != nullptr)
			{
				p->setNomeSenha(save.LoadStatus()->getNomeSenha());
				p->setPontos(save.LoadStatus()->getPontos());

				if (inputNome.getString() == p->getNomeSenha())
				{
					player.playerStatus = p;
					gTeclado.inputTexto.desabilitar();
					telaAtual = MENU;
					buttonEffect.tocar();
				}
				else
				{
					error.tocar();
				}
			}
			else
			{
				error.tocar();
			}
		}
		else if (btnVoltar.estaClicado())
		{
			inputNome.setString("");
			gTeclado.inputTexto.desabilitar();
			telaAtual = INICIO;
			buttonEffect.tocar();
		}
		break;
	case CADASTRO:
		sprTitle.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 200);
		txtNome.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 100);

		btnConfirmar.atualizar();
		btnConfirmar.desenhar();
		btnVoltar.atualizar();
		btnVoltar.desenhar();
		atualizarInput();
		desenharInput();

		if (btnConfirmar.estaClicado())
		{
			//irá fazer a verificação se tem algum usuario com esse nome e caso nao tenha adiciona
			PlayerStatus *p = new PlayerStatus();
			if (save.LoadStatus() != nullptr)
			{
				p->setNomeSenha(save.LoadStatus()->getNomeSenha());
				p->setPontos(save.LoadStatus()->getPontos());

				if (inputNome.getString() == p->getNomeSenha())
				{
					error.tocar();
				}
				else
				{
					p->setNomeSenha(inputNome.getString());
					p->setPontos(0);
					player.playerStatus = p;
					save.SaveStatus(player.playerStatus);
					gTeclado.inputTexto.desabilitar();
					telaAtual = INICIO;
					buttonEffect.tocar();
				}
			}
			else
			{
				p->setNomeSenha(inputNome.getString());
				p->setPontos(0);
				player.playerStatus = p;
				save.SaveStatus(player.playerStatus);
				gTeclado.inputTexto.desabilitar();
				telaAtual = INICIO;
				buttonEffect.tocar();
			}
		}
		else if (btnVoltar.estaClicado())
		{
			inputNome.setString("");
			gTeclado.inputTexto.desabilitar();
			telaAtual = INICIO;
			buttonEffect.tocar();
		}
		break;
	case MENU:
		sprTitle.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 200);

		btnJogar.atualizar();
		btnJogar.desenhar();
		btnContinuar.atualizar();
		btnContinuar.desenhar();
		btnCreditos.atualizar();
		btnCreditos.desenhar();
		btnRanking.atualizar();
		btnRanking.desenhar();
		btnSair.atualizar();
		btnSair.desenhar();

		if (btnJogar.estaClicado())
		{
			GameStart();
			buttonEffect.tocar();
			telaAtual = JOGO;
		}
		else if (btnContinuar.estaClicado())
		{
			//carrega os dados do jogador logado
			GameStart();
			buttonEffect.tocar();
			telaAtual = JOGO;
		}
		else if (btnCreditos.estaClicado())
		{
			buttonEffect.tocar();
			telaAtual = CREDITOS;
		}
		else if (btnRanking.estaClicado())
		{
			buttonEffect.tocar();
			telaAtual = RANKING;
		}
		else if (btnSair.estaClicado())
		{
			buttonEffect.tocar();
			gEventos.sair = true;
		}
		break;
	case JOGO:
		player.update();

		for (int i = 0; i < 4; i++)
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
	case CREDITOS:
		creditos.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

		btnVoltar.atualizar();
		btnVoltar.desenhar();

		if (btnVoltar.estaClicado())
		{
			telaAtual = MENU;
			buttonEffect.tocar();
		}
		break;
	case RANKING:
		sprTitle.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 200);

		btnVoltar.atualizar();
		btnVoltar.desenhar();

		if (btnVoltar.estaClicado())
		{
			telaAtual = MENU;
			buttonEffect.tocar();
		}
		break;
	default:
		break;
	}
}

bool Tela::getJogo()
{
	return telaAtual == JOGO;
}

void Tela::GameStart()
{
	player.playerInicializar();

	asteroid[0].asteroidStart();
	asteroid[1].asteroidStart();
	asteroid[2].asteroidStart();
	asteroid[3].asteroidStart();
}

void Tela::collisionTest(int p_obj)
{
#pragma region COLISAO_NAVE_X_INIMIGO

	if (uniTestarColisao(asteroid[p_obj].getSprite(), asteroid[p_obj].getPosX(), asteroid[p_obj].getPosY(), 0,
		player.getSprite(), player.getPosX(), player.getPosY(), player.getRot()))
	{
		asteroid[p_obj].asteroidStart();

		//criar nova condicao de ganho de pontos e perda de powerup via pilha
		//if (points > 30)
		//	points -= 30;
		//else
		//	statusGame = 2;
		player.playerStatus->setPontos(player.playerStatus->getPontos() - 10);
		damageShip.tocar(false);
	}

#pragma endregion

#pragma region COLISAO_INIMIGO_X_TIRO

	if (uniTestarColisao(asteroid[p_obj].getSprite(), asteroid[p_obj].getPosX(), asteroid[p_obj].getPosY(), 0,
		player.Tiro::getSprite(), player.Tiro::getPosX(), player.Tiro::getPosY(), 0))
	{
		asteroid[p_obj].asteroidStart();
		player.Tiro::setPosition(0, 0);
		player.setIsShoot(false);
		//a nova pontuação deve ser atribuida ao player
		//points += 10;
		player.playerStatus->setPontos(player.playerStatus->getPontos() + 10);
		damage.tocar(false);
	}

#pragma endregion

#pragma region COLISAO_ITEM_X_NAVE

	if (item)
	{
		if (uniTestarColisao(item->getSprite(), item->getPosX(), item->getPosY(), 0,
			player.getSprite(), player.getPosX(), player.getPosY(), 0))
		{
			powerUp.tocar(false);

			if (item->getPowerUp() == 0)
			{
				player.setSpeed(item->getSpeed());
				player.setIsPowerUp(true);
			}
			else if (item->getPowerUp() == 1)
			{
				player.Tiro::setSpeed(item->getSpeed());
				player.Tiro::setIsPowerUp(true);
			}

			resetItem();
		}
	}

#pragma endregion

}

void Tela::startNewItem()
{
	int posX = uniRandEntre(10, gJanela.getLargura() - 10);
	int posY = uniRandEntre(10, gJanela.getAltura() - 10);
	int type = uniRandEntre(0, 1);

	item->startNewItem(posX, posY, type);
}

void Tela::resetItem()
{
	counterItem = 0;
	maxCounter = uniRandEntre(500, 1000);
	isItemActive = false;
}

void Tela::atualizarInput()
{
	//	2) Controlar a edição do texto.
	//		Apagar o texto com tecla voltar ou delete
	if (gTeclado.pressionou[TECLA_VOLTAR])
	{
		gTeclado.inputTexto.apagar();
	}
	if (gTeclado.pressionou[TECLA_DELETE])
	{
		if (gTeclado.inputTexto.getTamanhoSelecao() != 0)
			gTeclado.inputTexto.apagar();
		else if (gTeclado.inputTexto.getPosCursor() < gTeclado.inputTexto.getString().size())
		{
			gTeclado.inputTexto.moverPosCursorParaDir();
			gTeclado.inputTexto.apagar();
		}
	}

	//		Mover a seleção do texto
	if (gTeclado.segurando[TECLA_SHIFT_ESQ])
	{
		if (gTeclado.pressionou[TECLA_ESQ])
		{
			gTeclado.inputTexto.moverSelecaoParaEsq();
		}
		if (gTeclado.pressionou[TECLA_DIR])
		{
			gTeclado.inputTexto.moverSelecaoParaDir();
		}
		if (gTeclado.pressionou[TECLA_HOME])
		{
			gTeclado.inputTexto.moverSelecaoParaInicio();
		}
		if (gTeclado.pressionou[TECLA_END])
		{
			gTeclado.inputTexto.moverSelecaoParaFim();
		}
	}
	//		Mover o cursor do texto
	else
	{
		if (gTeclado.pressionou[TECLA_ESQ])
		{
			gTeclado.inputTexto.moverPosCursorParaEsq();
		}
		if (gTeclado.pressionou[TECLA_DIR])
		{
			gTeclado.inputTexto.moverPosCursorParaDir();
		}
		if (gTeclado.pressionou[TECLA_HOME])
		{
			gTeclado.inputTexto.moverPosCursorParaInicio();
		}
		if (gTeclado.pressionou[TECLA_END])
		{
			gTeclado.inputTexto.moverPosCursorParaFim();
		}
	}

	//	3) Passar a string do input para o texto
	inputNome.setString(gTeclado.inputTexto.getString());
}

void Tela::desenharInput()
{
	//	4) Mostrar o texto na tela
	inputNome.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 + 150);


	//	Desenhar seleção
	int tamSelecao = gTeclado.inputTexto.getTamanhoSelecao();
	if (tamSelecao != 0)
	{
		Quad retan;
		retan.larg = 0;
		retan.alt = inputNome.getFonte()->getAlturaGlifos();

		retan.x = (gJanela.getLargura() / 2) - inputNome.getLargura() / 2;
		retan.y = (gJanela.getAltura() / 2) - retan.alt / 2 + 150;

		int posCursor = gTeclado.inputTexto.getPosCursor();
		int inicio = min(posCursor, posCursor + tamSelecao);
		int fim = max(posCursor, posCursor + tamSelecao);

		for (int i = inicio; i < fim; ++i)
			retan.larg += inputNome.getLetra(i)->glifo->avanco*inputNome.getEscalaX();

		for (int i = 0; i < inicio; ++i)
			retan.x += inputNome.getLetra(i)->glifo->avanco*inputNome.getEscalaX();

		gGraficos.desenharRetangulo(retan, 30, 200, 230);
	}

	//	Desenhar o cursor do texto
	int altCursor = inputNome.getFonte()->getAlturaGlifos();
	int xCursor = (gJanela.getLargura() / 2) - inputNome.getLargura() / 2;
	int yCursor = (gJanela.getAltura() / 2 + 150) - altCursor / 2;
	int pos = gTeclado.inputTexto.getPosCursor();
	for (int i = 0; i < pos; ++i)
		xCursor += inputNome.getLetra(i)->glifo->avanco*inputNome.getEscalaX();

	gGraficos.desenharLinha(xCursor, yCursor, xCursor, yCursor + altCursor);
}
