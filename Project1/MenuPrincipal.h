#ifndef _MENU_PRINCIPAL_H_
#define _MENU_PRINCIPAL_H_

#include "Menu.h"

class MenuPrincipal : public Menu
{
public:
	MenuPrincipal();
	~MenuPrincipal();

	void InicializaTexto();
	void Escolher_Opcao();
};

#endif