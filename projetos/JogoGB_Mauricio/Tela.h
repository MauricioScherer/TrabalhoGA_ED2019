#pragma once
#include <string>
class Tela
{
public:
	Tela();
	Tela(std::string tto);
	virtual ~Tela();
	virtual void inicializar();
	virtual void finalizar();
	virtual void atualizar();
	virtual void desenhar();
	virtual Tela * obtemProximaTela();
	std::string obtemTitulo();
	void defineTitulo(std::string tto);
private:
	std::string titulo;

};

