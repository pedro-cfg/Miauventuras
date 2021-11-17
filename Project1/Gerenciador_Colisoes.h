#ifndef GERENCIADOR_COLISOES_H_
#define GERENCIADOR_COLISOES_H_

#include "stdafx.h"
#include "ListaEntidades.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Jogador.h"
#include "Projetil.h"
#include "Entidade.h"
#include "Personagem.h"
//#include "Gerenciador_Grafico.h"

class FasePrimeira;
//class Entidade;

class Gerenciador_Colisoes 
{
private:
	list<Inimigo*> LIs;
	list<Obstaculo*> LOs;
	list<Projetil*> LPs;

	list<Inimigo*>::const_iterator iteInim;
	list<Obstaculo*>::const_iterator iteObs;
	list<Projetil*>::const_iterator iteProj;

	ListaEntidades* pLista;

	FasePrimeira* pF1;
	//Gerenciador_Grafico* pGerenciador_Grafico;
public:
	//Gerenciador_Colisoes(ListaEntidades* pL, Gerenciador_Grafico* pG);
	Gerenciador_Colisoes(ListaEntidades* pL);
	~Gerenciador_Colisoes();

	void Inserir(Inimigo* pI);
	void Inserir(Obstaculo* pO);
	void Inserir(Projetil* pP);

	void Excluir(Inimigo* pI);
	void Excluir(Projetil* pP);
	void Excluir(Jogador* pJ);

	void Fim_de_Fase(Jogador* pJ);
	void LimpaListas();

	void Checa_Colisao(Jogador* pJ);
	void Checa_Colisao_Inimigos();
	void Checa_Colisao_Individual(Personagem* pP, Entidade* outro, bool& esq, bool& dir, bool& cima, bool& baixo);

	void setPrimeiraFase(FasePrimeira* pF);
};

#endif

