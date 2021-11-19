#ifndef _JOGO_H_
#define _JOGO_H_

#include "stdafx.h"
#include "Jogador.h"
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "FaseSegunda.h"
#include "Menu.h"

class Jogo 
{
private:
	int estado_de_jogo; /* fechar janela = -1, menu = 0, fase 1 = 1, fase 2 = 2 */

	Jogador* pJ1;
	Gerenciador_Grafico gerenciador_grafico;

	Menu menu_principal;
	FasePrimeira primeira_fase;
	FaseSegunda segunda_fase;
public:
	Jogo();
	~Jogo();

	void Executar();

	void Inicializar();
};

#endif 