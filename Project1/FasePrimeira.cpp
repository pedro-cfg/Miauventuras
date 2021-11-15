#include "stdafx.h"
#include "FasePrimeira.h"

FasePrimeira::FasePrimeira(Jogador* j1) :Fase(j1) {
	Inserir_Inimigos();
}

FasePrimeira::~FasePrimeira() {

}

void FasePrimeira::Inserir_Inimigos()
{
	int instancias, posicao;

	instancias = rand() % 5;
	for (int i = 0; i < instancias; i++) {
		posicao = rand() % 9000;
		Aranha* pA = new Aranha(posicao, -49);
		lista_entidades.Inserir(static_cast<Entidade*>(pA));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pA));
	}

	instancias = rand() % 5;
	for (int i = 0; i < instancias; i++) {
		posicao = rand() % 9000;
		Lagartixa* pL = new Lagartixa(posicao, -20);
		lista_entidades.Inserir(static_cast<Entidade*>(pL));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pL));
	}
}
