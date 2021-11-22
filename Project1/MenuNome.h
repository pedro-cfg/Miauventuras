#pragma once
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

