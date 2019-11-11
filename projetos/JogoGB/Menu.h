#pragma once
#include "libUnicornio.h"
#include "Tela.h"

class Menu : public Tela
{
public:
	Menu();
	~Menu();
	
	void desenhar() override;
};

