#ifndef _JOGO_H_
#define _JOGO_H_

#include "stdafx.h"
#include "Jogador1.h"
#include "Jogador2.h"
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "FaseSegunda.h"
#include "Menu.h"
#include "Aranha.h"
#include "Lagartixa.h"

class Jogo 
{
private:
	int estado_de_jogo; /* fechar janela = -1, menu = 0, fase 1 = 1, fase 2 = 2, carregar = 3, salvar = 4 */
	bool reinicio;

	Jogador1* pJ1;
	Jogador2* pJ2;
	Gerenciador_Grafico gerenciador_grafico;

	Menu menu_principal;
	FasePrimeira primeira_fase;

	FaseSegunda segunda_fase;
public:
	Jogo();
	~Jogo();

	void Executar();

	void Inicializar();

	void Gravar();
	void Ler();
	void GravarJogador(fstream& arquivo);
	void LerJogador(fstream& arquivo);
};

#endif 