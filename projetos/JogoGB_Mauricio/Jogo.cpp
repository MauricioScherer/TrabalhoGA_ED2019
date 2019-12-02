#include "Jogo.h"
#include <time.h>
#include <fstream>

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
	exit(0);
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);
	uniRandSetSemente(time(NULL));

	statusGame = 0;
<<<<<<< HEAD
=======

	//inicializando uma lista
	listaUsuarios = new ListaUsuarios();
	listaUsuarios->loadUsuarios();

	//input logar 
	//nome
	//senha
	_usuarioTemp = new Usuario("Nome", "Senha");

	//apos ser adicionado os dados no login faz a verificação se o usuario existe e pode logar
	if (listaUsuarios->existe(_usuarioTemp))
	{
		//login e senha estão OK, carrega nova tela
	}
	else
	{
		//não pode acessar login e/ou senha errados
	}

	//input cadastrar novo usuario
	//nome
	//senha
	_usuarioTemp = new Usuario("Nome", "Senha");

	//adiciona novo usuario
	if (!listaUsuarios->existe(_usuarioTemp))
	{
		listaUsuarios->inserirFinal(_usuarioTemp);
	}
	else
	{
		//usuario já cadastrado, escolher um novo nome
	}	

#pragma region PLAYER

	gRecursos.carregarSpriteSheet("player", "assets/sprite/nave2.png", 1, 1);
	gRecursos.carregarSpriteSheet("tiro", "assets/sprite/tiro2.png", 1, 1);
	player.setSpriteSheet("player");
	player.Tiro::setSpriteSheet("tiro");

#pragma endregion
>>>>>>> 3f09458483352b6dafd88691668698306e8bf3f9
		
#pragma region SOM
	
	tela.inicializar();
	pilhaTela.push(tela);
}

void Jogo::finalizar()
{
	//save();
	tela.finalizar();
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();		
<<<<<<< HEAD
		pilhaTela.top().executar();
		uniTerminarFrame();
=======
		background.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
		
		switch (statusGame)
		{
		case 0:
			//sprTitle.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 150);
			//buttonStart.atualizar();
			//buttonStart.desenhar();
			//buttonContinuar.atualizar();
			//buttonContinuar.desenhar();

			//if (buttonStart.estaClicado())
			//{
			//	buttonEffect.tocar();
			//	GameStart(0);
			//}
			//else if (buttonContinuar.estaClicado())
			//{
			//	buttonEffect.tocar();
			//	GameStart(1);
			//}

			//INICIO NOVO
			//tela inicial vai ter os comandos 
			//botao-> Logar
				//Nova Tela-> chama a tela de login case 1
			//botao -> Cadastrar
				//Nova Tela-> chama a tela de cadastro case 2
			break;
		case 1:
			//player.update();

			//for (int i = 0; i < 4; i++)
			//{
			//	asteroid[i].update();
			//	asteroid[i].draw();
			//	collisionTest(i);
			//}

			//if (!isItemActive)
			//	counterItem += 1;
			//else
			//	item->draw();

			//if (counterItem >= maxCounter && !isItemActive)
			//{
			//	startNewItem();
			//	isItemActive = true;
			//}

			//INICIO NOVO
			//tela de login
			//Img text login
				//Input login
			//Img text senha
				//input senha

			//botao confirmar
				//Nova tela-> chama a tela de menu case 3
			//botao voltar
				//Nova Tela-> chama a tela inicial case 0
			break;
		case 2:
			//buttonGameOver.atualizar();
			//buttonGameOver.desenhar();

			//if (buttonGameOver.estaClicado())
			//{
			//	statusGame = 0;
			//}

			//INICIO NOVO
			//tela de cadastro

			//Img text login
				//Input login
			//Img text senha
				//input senha

			//botao confirmar
				//se usuario nao existir
					//Nova tela-> chama a tela de menu case 3
			//botao voltar
				//Nova Tela-> chama a tela inicial case 0
			break;
		case 3:
			//MENU PRINCIPAL
			//img titulo
			//botao-> Novo jogo
				//carrega o jogo CASE 4
			//botao-> carregar
				//carrega o jogo com os dados salvos CASE 4
			//botao-> ranking
				//carrega a tela de ranking com os dados dos 5 primeiros melhores pontuados CASE 5
			//botao-> creditos
				// carrega tela creditos CASE 6
			//botao-> sair
			break;
		case 4:
			//tela jogo
			break;
		case 5:
			//tela ranking
			break;
		case 6:
			//tela creditos
			break;
		default:
			break;
		}

#pragma region DebugTela

		if (gTeclado.soltou[TECLA_D])
			debug = !debug;

		if (statusGame == 1)
		{
			if (debug)
			{
				string txt = "pos X: " + to_string(player.getPosX()) + "\n" +
					"pos Y: " + to_string(player.getPosY()) + "\n" +
					"pode atirar: " + to_string(player.getIsShoot()) + "\n" +
					"counterMax: " + to_string(maxCounter) + "\n" +
					"counter: " + to_string(counterItem) + "\n" +
					"tempo de powerUp nave: " + to_string(player.getPowerUpTime()) + "\n" + 
					"tempo de powerUp Tiro: " + to_string(player.Tiro::getPowerUpTime());

				gGraficos.desenharTexto(txt, 25, 25, 255, 255, 255, 255, 0, 0);
			}

			string pointsStr = "PONTOS: " + to_string(points);
			gGraficos.desenharTexto(pointsStr, gJanela.getLargura() / 2, 25, 255, 255, 255, 255, 0.5f, 0.5f);
		}

#pragma endregion

	uniTerminarFrame();
>>>>>>> 3f09458483352b6dafd88691668698306e8bf3f9
	}
}