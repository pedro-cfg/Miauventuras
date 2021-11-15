#ifndef _FASE_H_
#define _FASE_H_

#include "stdafx.h"
#include "Ente.h"
#include "Gerenciador_Colisoes.h"
#include "Entidade.h"
#include "Aranha.h"
#include "Lagartixa.h"
#include "Ratao.h"
#include "Plataforma.h"
#include "Teia.h"
#include "Espinho.h"
#include "Projetil.h"
#include "Jogador.h"

class Fase: public Ente 
{
private:
	Gerenciador_Colisoes gerenciador_colisoes;
	ListaEntidades lista_entidades;

	Jogador* pJ1;

	Aranha a1;
	Lagartixa l1;
	Ratao r1;
	Teia t1;
	Espinho e1;
public:    
	Fase(Jogador* pJ);
	~Fase();

	virtual void Executar(float dT);
	void gerenciar_colisoes();

	void Inserir_Entidades_Prontas();
	void Inserir_Colisoes_Prontas();

	void Inserir_Entidade(Entidade* pE);
	void Inserir_Colisao(Inimigo* pI);
	void Inserir_Colisao(Obstaculo* pO);
	void Inserir_Colisao(Projetil* pP);

	ListaEntidades& getLista();
};

#endif