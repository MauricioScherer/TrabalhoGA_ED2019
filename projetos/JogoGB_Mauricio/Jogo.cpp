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
		pilhaTela.top().executar();
		uniTerminarFrame();
	}
}