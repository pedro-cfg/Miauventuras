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
#include "Gerenciador_Grafico.h"

class Fase: public Ente 
{
protected:
	Gerenciador_Colisoes gerenciador_colisoes;
	ListaEntidades lista_entidades;

	Jogador* pJ1;
public:    
	Fase();
	~Fase();

	virtual void Executar(float dT);

	void Inserir_Entidade(Entidade* pE);

	void setJogador(Jogador* pJ);

	ListaEntidades& getLista();
};

#endif