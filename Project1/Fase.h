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
#include "Jogador1.h"
#include "Jogador2.h"
#include "Estado.h"
#include "MenuFim.h"

class Fase: public Ente, public Estado
{
protected:
	Gerenciador_Colisoes gerenciador_colisoes;
	ListaEntidades lista_entidades;

	Jogador1* pJ1;
	Jogador2* pJ2;
public:    
	Fase();
	~Fase();

	void ExecutaEstado(float dT);
	void Executar(float dT);

	void Gerar_Objetos();
	void Gerar_Inimigos();
	void Gerar_Obstaculos();

	virtual void Gerar_Plataformas();
	virtual void Gerar_Chefao();

	void Inserir_Entidade(Entidade* pE);

	void reseta_fase(Jogador1* p1, Jogador2* p2, bool reinicio = false);

	virtual void Passou_Fase();
	void MorteJogadores();

	void Limpar();

	void GravarLista(fstream& arquivo);
	void LerLista(fstream& arquivo, Jogador1* p1, Jogador2* p2);
	void LerLista_Individual(fstream& arquivo);
};

#endif