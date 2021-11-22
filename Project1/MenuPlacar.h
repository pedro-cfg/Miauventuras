#pragma once
#include "Menu.h"
class MenuPlacar : public Menu
{
private:
	string placar[5];
public:
	MenuPlacar();
	~MenuPlacar();

	void InicializaTexto();
	void Escolher_Opcao();

	void RecuperarPontuacao();
};

