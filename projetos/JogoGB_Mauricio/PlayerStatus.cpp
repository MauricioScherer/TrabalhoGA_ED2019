#include "PlayerStatus.h"



PlayerStatus::PlayerStatus()
{
	nome_senha = "";
	pontos = 0;
}


PlayerStatus::~PlayerStatus()
{
}

void PlayerStatus::setPontos(int p_pontos)
{
	pontos = p_pontos;
}

int PlayerStatus::getPontos()
{
	return pontos;
}

void PlayerStatus::setNomeSenha(string p_nome)
{
	nome_senha = p_nome;
}

string PlayerStatus::getNomeSenha()
{
	return nome_senha;
}
