#include "stdafx.h"
#include "FasePrimeira.h"
#include "Gerenciador_Grafico.h"

FasePrimeira::FasePrimeira() :
	Fase() 
{
}

FasePrimeira::~FasePrimeira() 
{
}

void FasePrimeira::Passou_Fase()
{
	if (pJ1 && pJ2)
	{
		if (pJ1->getX() >= 10000 && pJ2->getX() >= 10000)
		{
			Fase* pSegFase = static_cast<Fase*>(pMaquinaEstados->buscaEstado(SEGUNDA_FASE));
			pSegFase->reseta_fase(pJ1, pJ2);
			pGG->MudaFundo(2);
			pJ1->reseta_jogador(false, true);
			pJ2->reseta_jogador(false, true);
			pJ1->setFase(2);
			pJ2->setFase(2);
			pMaquinaEstados->setEstadoAtual(SEGUNDA_FASE);
		}
	}
	else if (pJ1)
	{
		if (pJ1->getX() >= 10000)
		{
			Fase* pSegFase = static_cast<Fase*>(pMaquinaEstados->buscaEstado(SEGUNDA_FASE));
			pSegFase->reseta_fase(pJ1, NULL);
			pGG->MudaFundo(2);
			pJ1->reseta_jogador(false, true);
			pJ1->setFase(2);
			pMaquinaEstados->setEstadoAtual(SEGUNDA_FASE);
		}
	}
	else if (pJ2)
	{
		if (pJ2->getX() >= 10000)
		{
			Fase* pSegFase = static_cast<Fase*>(pMaquinaEstados->buscaEstado(SEGUNDA_FASE));
			pSegFase->reseta_fase(NULL, pJ2);
			pGG->MudaFundo(2);
			pJ2->reseta_jogador(false, true);
			pJ2->setFase(2);
			pMaquinaEstados->setEstadoAtual(SEGUNDA_FASE);
		}
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