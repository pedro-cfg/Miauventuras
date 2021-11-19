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

	int* estado_jogo;
public:    
	Fase();
	~Fase();

	void Executar(float dT);

	void Gerar_Objetos();
	void Gerar_Inimigos();
	void Gerar_Obstaculos();

	virtual void Gerar_Plataformas();
	virtual void Gerar_Chefao();

	void Inserir_Entidade(Entidade* pE);

	void reseta_fase();

	virtual void Passou_Fase();

	void setJogador(Jogador* pJ);

	ListaEntidades& getLista();
};

#endif