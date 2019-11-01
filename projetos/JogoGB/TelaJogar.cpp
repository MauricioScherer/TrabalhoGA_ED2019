#include "TelaJogar.h"

TelaJogar::TelaJogar()
{
}

TelaJogar::~TelaJogar()
{
}

void TelaJogar::desenhar()
{
	gGraficos.desenharTexto("TELA JOGAR", gJanela.getLargura() / 2, gJanela.getAltura() / 2, 255, 255, 255, 255, 0.5f, 0.5f);
}
