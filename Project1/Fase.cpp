#include "stdafx.h"
#include "Fase.h"

Fase::Fase(Jogador* pJ) :
	Ente(),
	gerenciador_colisoes(&lista_entidades)
	//a1(500, -49),
	//l1(5000, -20),
	//r1(8500, -150),
	//t1(1000, -75),
	//e1(1500, -75)
{
	Entidade::setGerenciadorColisoes(&gerenciador_colisoes);
	Entidade::setPonteiroLista(&lista_entidades);
	/*Inserir_Entidades_Prontas();
	Inserir_Colisoes_Prontas();*/
	pJ1 = pJ;
	Inserir_Obstaculos();
}

Fase::~Fase() {

}

void Fase::Executar(float dT)
{
	gerenciador_colisoes.Checa_Colisao(pJ1);
	lista_entidades.Executar(dT);
}

void Fase::gerenciar_colisoes() {

}

//void Fase::Inserir_Entidades_Prontas()
//{
//	lista_entidades.Inserir(static_cast<Entidade*>(&a1));
//	lista_entidades.Inserir(static_cast<Entidade*>(&l1));
//	lista_entidades.Inserir(static_cast<Entidade*>(&r1));
//	lista_entidades.Inserir(static_cast<Entidade*>(&t1));
//	lista_entidades.Inserir(static_cast<Entidade*>(&e1));
//}
//
//void Fase::Inserir_Colisoes_Prontas()
//{
//	gerenciador_colisoes.Inserir(static_cast<Inimigo*>(&a1));
//	gerenciador_colisoes.Inserir(static_cast<Inimigo*>(&l1));
//	gerenciador_colisoes.Inserir(static_cast<Inimigo*>(&r1));
//	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(&t1));
//	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(&e1));
//}

void Fase::Inserir_Entidade(Entidade* pE)
{
	lista_entidades.Inserir(pE);
}

void Fase::Inserir_Obstaculos()
{
	int instancias, posicao;

	srand(time(NULL));
	instancias = rand() % 5;
	for (int i = 0; i < instancias; i++) {
		posicao = rand() % 9000;
		Espinho* pE = new Espinho(posicao, -75);
		lista_entidades.Inserir(static_cast<Entidade*>(pE));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pE));
	}

	instancias = rand() % 5;
	for (int i = 0; i < instancias; i++) {
		posicao = rand() % 9000;
		Teia* pT = new Teia(posicao, -75);
		lista_entidades.Inserir(static_cast<Entidade*>(pT));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pT));
	}
}

ListaEntidades& Fase::getLista()
{
	return lista_entidades;
}
