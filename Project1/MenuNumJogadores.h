#ifndef _MENU_NUM_JOGADORES_H_
#define _MENU_NUM_JOGADORES_H_

#include "Menu.h"

class MenuNumJogadores : public Menu
{
public:
	MenuNumJogadores();
	~MenuNumJogadores();

	void InicializaTexto();
	void Escolher_Opcao();
};

#endif