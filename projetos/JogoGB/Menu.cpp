#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::desenhar()
{
	gGraficos.desenharTexto("TELA MENU", gJanela.getLargura() / 2, gJanela.getAltura() / 2, 255, 255, 255, 255, 0.5f, 0.5f);
}
