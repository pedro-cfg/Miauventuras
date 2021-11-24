#ifndef _MENU_FIM_H_
#define _MENU_FIM_H_

#include "Menu.h"

class MenuFim : public Menu
{
private:
	bool vitoria;
public:
	MenuFim();
	~MenuFim();

	void Executar(float dT);
	void setVitoria(const bool v);

	void InicializaTexto();
	void Escolher_Opcao();
};

#endif