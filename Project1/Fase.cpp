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

void Fase::Gerar_Objetos()
{
	srand(time(NULL));
	Gerar_Inimigos();
	Gerar_Obstaculos();
}

void Fase::Gerar_Inimigos()
{
	Gerar_Chefao();
	int instancias, posicao;

	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++)
	{
		posicao = (rand() % 9000) + 300;
		Aranha* pA = new Aranha((float)posicao, -1000);
		lista_entidades.Inserir(static_cast<Entidade*>(pA));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pA));
	}

	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++)
	{
		posicao = (rand() % 9000) + 300;
		Lagartixa* pL = new Lagartixa((float)posicao, -1000);
		lista_entidades.Inserir(static_cast<Entidade*>(pL));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pL));
	}
}

void Fase::Gerar_Obstaculos()
{
	Gerar_Plataformas();
	int instancias, posicao;

	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++) {
		posicao = (rand() % 9000) + 300;
		Espinho* pE = new Espinho((float)posicao, -75);
		lista_entidades.Inserir(static_cast<Entidade*>(pE));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pE));
	}

	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++) {
		posicao = (rand() % 9000) + 300;
		Teia* pT = new Teia((float)posicao, -200);
		lista_entidades.Inserir(static_cast<Entidade*>(pT));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pT));
	}
}

void Fase::Gerar_Plataformas()
{
}

void Fase::Gerar_Chefao()
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
