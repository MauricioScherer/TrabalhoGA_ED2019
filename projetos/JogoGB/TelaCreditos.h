#pragma once
#include "libUnicornio.h"
#include "Tela.h"

class TelaCreditos : public Tela
{
public:
	TelaCreditos();
	~TelaCreditos();

	void desenhar() override;
};

