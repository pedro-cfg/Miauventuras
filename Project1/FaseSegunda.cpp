#include "stdafx.h"
#include "FaseSegunda.h"
using namespace Menus;

FaseSegunda::FaseSegunda():
	Fase() 
{
}

FaseSegunda::~FaseSegunda() 
{
}

int FaseSegunda::Numero_Instancias()
{
	return (rand() % 3) + 5;
}

void FaseSegunda::Passou_Fase()
{
	if (pJ1 && pJ2)
	{
		if (pJ1->getVenceu() || pJ2->getVenceu())
		{
			pJ1->reseta_jogador();
			pJ2->reseta_jogador();
			pMaquinaEstados->setEstadoAtual(MENU_FIM);
			MenuFim* pMenu = static_cast<MenuFim*>(pMaquinaEstados->getEstadoAtual());
			pMenu->setVitoria(true);
		}
	}
	else if (pJ1)
	{
		if (pJ1->getVenceu())
		{
			pJ1->reseta_jogador();
			pMaquinaEstados->setEstadoAtual(MENU_FIM);
			MenuFim* pMenu = static_cast<MenuFim*>(pMaquinaEstados->getEstadoAtual());
			pMenu->setVitoria(true);
		}
	}
	else if (pJ2)
	{
		if (pJ2->getVenceu())
		{
			pJ2->reseta_jogador();
			pMaquinaEstados->setEstadoAtual(MENU_FIM);
			MenuFim* pMenu = static_cast<MenuFim*>(pMaquinaEstados->getEstadoAtual());
			pMenu->setVitoria(true);
		}
	}
}

void FaseSegunda::Gerar_Plataformas()
{
	Plataforma* p1 = new Plataforma(1300, -290);
	lista_entidades.Inserir(static_cast<Entidade*>(p1));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p1));

	Plataforma* p2 = new Plataforma(2510, -300);
	lista_entidades.Inserir(static_cast<Entidade*>(p2));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p2));

	Plataforma* p3 = new Plataforma(3200, -600);
	lista_entidades.Inserir(static_cast<Entidade*>(p3));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p3));

	Plataforma* p4 = new Plataforma(4160, -490);
	lista_entidades.Inserir(static_cast<Entidade*>(p4));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p4));

	Plataforma* p5 = new Plataforma(5370, -290);
	lista_entidades.Inserir(static_cast<Entidade*>(p5));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p5));

	Plataforma* p6 = new Plataforma(6430, -600);
	lista_entidades.Inserir(static_cast<Entidade*>(p6));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p6));

	Plataforma* p7 = new Plataforma(7930, -290);
	lista_entidades.Inserir(static_cast<Entidade*>(p7));
	gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(p7));
}

void FaseSegunda::Gerar_Chefao()
{
	Ratao* pR = new Ratao(9400, -150);
	lista_entidades.Inserir(static_cast<Entidade*>(pR));
	gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pR));
}