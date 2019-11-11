#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	pilha.push(&menu);
	//pilha.push(&jogar); 
	//pilha.pop();

	player = new Player();

	gameManager.Load();
}

void Jogo::finalizar()
{
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		pilha.top()->desenhar();

		string txt = "";
		gGraficos.desenharTexto(txt, 25, 25, 255, 255, 255, 255, 0, 0);

				
		uniTerminarFrame();
	}
}