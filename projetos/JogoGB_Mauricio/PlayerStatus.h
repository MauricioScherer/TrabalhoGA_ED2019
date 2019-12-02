#pragma once
#include <iostream>
#include <string>

using namespace std;

class PlayerStatus
{
public:
	PlayerStatus();
	~PlayerStatus();

	void setPontos(int p_pontos);
	int getPontos();
	void setNomeSenha(string p_nome);
	string getNomeSenha();

private:
	string nome_senha;
	int pontos;
};

