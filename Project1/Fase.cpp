#include "stdafx.h"
#include "Fase.h"

Fase::Fase() :
	Ente(),
	gerenciador_colisoes(&lista_entidades),
	pJ1(NULL)
{
	Entidade::setGerenciadorColisoes(&gerenciador_colisoes);
	Entidade::setPonteiroLista(&lista_entidades);
}

Fase::~Fase() {

}

void Fase::Executar(float dT)
{

}

void Fase::Inserir_Entidade(Entidade* pE)
{
	lista_entidades.Inserir(pE);
}

void Fase::setJogador(Jogador* pJ)
{
	pJ1 = pJ;
}

ListaEntidades& Fase::getLista()
{
	return lista_entidades;
}
