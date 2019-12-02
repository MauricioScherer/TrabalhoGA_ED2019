#pragma once
#include <iostream>
#include <stack>
#include "Tela.h"

using namespace std;

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
	
private:
	int statusGame;
	bool debug = false;

	Tela tela;
	stack<Tela> pilhaTela;
};

