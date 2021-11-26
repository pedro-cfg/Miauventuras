#ifndef _MENU_FASES_H_
#define _MENU_FASES_H_

#include "Menu.h"

namespace Menus {

	class MenuFases : public Menu
	{
	public:
		MenuFases();
		~MenuFases();

		void InicializaTexto();
		void Escolher_Opcao();
	};

}

#endif