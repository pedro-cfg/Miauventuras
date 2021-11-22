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

class Jogo 
{
private:
	//int estado_de_jogo; /* fechar janela = -1, menu = 0, fase 1 = 1, fase 2 = 2, carregar = 3, salvar = 4 */
	//bool reinicio;
	//bool dois_jogadores;
	/**/
	bool dois_jogadores;
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

	void Gravar();
	void Ler();
	void GravarJogador(fstream& arquivo);
	void LerJogador(fstream& arquivo);
};

#endif 