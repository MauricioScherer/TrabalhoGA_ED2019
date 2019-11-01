#include "TelaCreditos.h"



TelaCreditos::TelaCreditos()
{
}


TelaCreditos::~TelaCreditos()
{
}

void TelaCreditos::desenhar()
{
	gGraficos.desenharTexto("TELA CREDITOS", gJanela.getLargura() / 2, gJanela.getAltura() / 2, 255, 255, 255, 255, 0.5f, 0.5f);
}
