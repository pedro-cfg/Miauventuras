#ifndef GERENCIADOR_COLISOES_H_
#define GERENCIADOR_COLISOES_H_

#include "ListaEntidades.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Entidade.h"
#include "Jogador.h"
#include "Lista.h"
#include "Gerenciador_Grafico.h"

class Gerenciador_Colisoes 
{
private:
	list<Inimigo*> LIs;
	list<Obstaculo*> LOs;

	Lista<Entidade>* pLista;
	Gerenciador_Grafico* pGerenciador_Grafico;
public:
	Gerenciador_Colisoes(Lista<Entidade>* pL, Gerenciador_Grafico* pG);
	~Gerenciador_Colisoes();

	void InserirInimigo(Inimigo* pI);
	void InserirObstaculo(Obstaculo* pO);

	void ExcluirInimigo(Inimigo* pI);
	void ExcluirObstaculo(Obstaculo* pO);

	void Checa_Colisao(Jogador* pJ);
	void Checa_Colisao_Individual(Jogador* pJ, Entidade* outro, bool& esq, bool& dir, bool& cima, bool& baixo);

	/*
	void Executa_Colisao(Jogador* pJ, Inimigo* inimigo);
	void Executa_Colisao(Jogador* pJ, Obstaculo* obstaculo);*/
};

#endif 

