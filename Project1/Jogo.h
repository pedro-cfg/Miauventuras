#ifndef _JOGO_H_
#define _JOGO_H_

#include "stdafx.h"
#include "Jogador.h"
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "Menu.h"

class Jogo 
{
private:
	Jogador j1;
	Gerenciador_Grafico gerenciador_grafico;

	Menu menu_principal;
	FasePrimeira primeira_fase;

public:
	Jogo();
	~Jogo();

	void Executar();

};

#endif 