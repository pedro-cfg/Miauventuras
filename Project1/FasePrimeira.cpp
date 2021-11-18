#include "stdafx.h"
#include "FasePrimeira.h"

FasePrimeira::FasePrimeira() :
	Fase() 
{
	//gerenciador_colisoes.setPrimeiraFase(this);
}

FasePrimeira::~FasePrimeira() {

}

void FasePrimeira::Executar(float dT)
{
	//if (executando == 1) 
	//{
	gerenciador_colisoes.Checa_Colisao(pJ1);
	gerenciador_colisoes.Checa_Colisao_Inimigos();

	pJ1->Executar(dT);
	lista_entidades.Executar(dT);

	pGG->AjustarVista(pJ1);

	pJ1->desenhar();
	pGG->DesenhaTudo(lista_entidades);
		
		//gerenciador_colisoes.Fim_de_Fase(pJ1);
	//}
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
