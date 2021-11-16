#include "stdafx.h"
#include "FasePrimeira.h"

FasePrimeira::FasePrimeira(Jogador* j1) :Fase(j1) {
	Gerar_Objetos();
}

FasePrimeira::~FasePrimeira() {

}

void FasePrimeira::Executar(float dT)
{
	if (executando == true) {
		gerenciador_colisoes.Checa_Colisao(pJ1);
		lista_entidades.Executar(dT);

		pGG->AjustarVista(pJ1);
		pGG->DesenhaTudo(getLista());
	}
}

void FasePrimeira::Gerar_Objetos()
{
	Inserir_Inimigos();
	Inserir_Obstaculos();
}

void FasePrimeira::Inserir_Inimigos()
{
	int instancias, posicao;

	instancias = (rand() % 7) + 1;
	for (int i = 0; i < instancias; i++) {
		posicao = rand() % 9000;
		Aranha* pA = new Aranha(posicao, -49);
		lista_entidades.Inserir(static_cast<Entidade*>(pA));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pA));
	}

	instancias = (rand() % 7) + 1;
	for (int i = 0; i < instancias; i++) {
		posicao = rand() % 9000;
		Lagartixa* pL = new Lagartixa(posicao, -20);
		lista_entidades.Inserir(static_cast<Entidade*>(pL));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pL));
	}
}
