#ifndef _JOGO_H_
#define _JOGO_H_

#include "stdafx.h"
#include "Jogador1.h"
#include "Jogador2.h"
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "FaseSegunda.h"
#include "MenuFases.h"
#include "MenuFim.h"
#include "MenuNome.h"
#include "MenuNumJogadores.h"
#include "MenuPausa.h"
#include "MenuPlacar.h"
#include "MenuPrincipal.h"
#include "MaquinaEstados.h"
#include "Estado.h"
using namespace Menus;

/*Classe principal*/
class Jogo 
{
private:
	/*Jogadores serão alocados dinamicamente na inicialização*/
	Jogador1* pJ1;
	Jogador2* pJ2;

	Gerenciador_Grafico gerenciador_grafico;

	MenuPrincipal menu_principal;
	MenuFases menu_fases;
	MenuNome menu_nome;
	MenuNumJogadores menu_num_jogadores;
	MenuPausa menu_pausa;
	MenuPlacar menu_placar;
	MenuFim menu_fim;

	FasePrimeira primeira_fase;
	FaseSegunda segunda_fase;

	MaquinaEstados maquina_de_estados;

public:
	Jogo();
	~Jogo();

	void Executar();

	void Inicializar();
	void InicializarEstados();

	Jogador1* getJogador1() const;
	Jogador2* getJogador2() const;

	FasePrimeira* getPrimeiraFase();
	FaseSegunda* getSegundaFase();

	/*Métodos de salvamento e carregamento*/
	void Gravar();
	void GravarJogadores();
	void GravarFase();

	void Carregar();
	void CarregarJogadores();
	void CarregarFase();

	void MudaFundo(int fase);
};

#endif 