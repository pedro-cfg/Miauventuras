#include "stdafx.h"
#include "FasePrimeira.h"

FasePrimeira::FasePrimeira() :
	Fase() 
{
	gerenciador_colisoes.setPrimeiraFase(this);
}

FasePrimeira::~FasePrimeira() {

}

void FasePrimeira::Executar(float dT)
{
	if (executando == 1) 
	{
		gerenciador_colisoes.Checa_Colisao(pJ1);
		gerenciador_colisoes.Checa_Colisao_Inimigos();
		lista_entidades.Executar(dT);

		pGG->AjustarVista(pJ1);
		pGG->DesenhaTudo(getLista());
		
		gerenciador_colisoes.Fim_de_Fase(pJ1);
	}
}

void FasePrimeira::Gerar_Objetos()
{
	srand(time(NULL));
	Gerar_Inimigos();
	Gerar_Obstaculos();
}

void FasePrimeira::Gerar_Inimigos()
{
	/*Aranha* pA = new Aranha(1300, -700);
	lista_entidades.Inserir(static_cast<Entidade*>(pA));
	gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pA));*/
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

void FasePrimeira::Gerar_Obstaculos()
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

void FasePrimeira::Gerar_Plataformas()
{
	Plataforma* p1 = new Plataforma(1300, -290);
	lista_entidades.Inserir(static_cast<Entidade*>(p1));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p1));

	Plataforma* p2 = new Plataforma(2110, -600);
	lista_entidades.Inserir(static_cast<Entidade*>(p2));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p2));

	Plataforma* p3 = new Plataforma(3060, -400);
	lista_entidades.Inserir(static_cast<Entidade*>(p3));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p3));

	Plataforma* p4 = new Plataforma(4160, -490);
	lista_entidades.Inserir(static_cast<Entidade*>(p4));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p4));

	Plataforma* p5 = new Plataforma(5370, -510);
	lista_entidades.Inserir(static_cast<Entidade*>(p5));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p5));

	Plataforma* p6 = new Plataforma(6330, -650);
	lista_entidades.Inserir(static_cast<Entidade*>(p6));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p6));

	Plataforma* p7 = new Plataforma(7230, -460);
	lista_entidades.Inserir(static_cast<Entidade*>(p7));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p7));

	Plataforma* p8 = new Plataforma(8430, -290);
	lista_entidades.Inserir(static_cast<Entidade*>(p8));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p8));
}
