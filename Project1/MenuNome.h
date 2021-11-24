#ifndef _MENU_NOME_H_
#define _MENU_NOME_H_

#include "Menu.h"

class MenuNome : public Menu
{
public:
	MenuNome();
	~MenuNome();

	void InicializaTexto();
	void Escolher_Opcao();

	void incluiTexto(char letra);
	void retiraTexto();
};

#endif