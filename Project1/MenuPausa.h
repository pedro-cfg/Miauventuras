#ifndef _MENU_PAUSA_H_
#define _MENU_PAUSA_H_

#include "Menu.h"

namespace Menus {

	class MenuPausa : public Menu
	{
	public:
		MenuPausa();
		~MenuPausa();

		void InicializaTexto();
		void Escolher_Opcao();
	};

}

#endif