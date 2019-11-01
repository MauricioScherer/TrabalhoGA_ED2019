#pragma once
class Tela
{
public:
	Tela();
	~Tela();

protected:
	virtual void desenhar() = 0;
	virtual void atualizar() = 0;
};