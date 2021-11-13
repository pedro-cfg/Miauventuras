#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo() :
	j1(-265, -29),
	a1(100, 5),
	l1(400, 30),
	r1(700, -25),
	p1(1950, 118),
	p2(-903, 100),
	gerenciador_grafico(&j1),
	gerenciador_colisoes(&lista_entidades, &gerenciador_grafico)
{

	j1.setGerenciadorGrafico(&gerenciador_grafico);
	a1.setGerenciadorGrafico(&gerenciador_grafico);
	l1.setGerenciadorGrafico(&gerenciador_grafico);
	r1.setGerenciadorGrafico(&gerenciador_grafico);
	p1.setGerenciadorGrafico(&gerenciador_grafico);
	p2.setGerenciadorGrafico(&gerenciador_grafico);

	j1.setGerenciadorColisoes(&gerenciador_colisoes);
	a1.setGerenciadorColisoes(&gerenciador_colisoes);
	l1.setGerenciadorColisoes(&gerenciador_colisoes);
	r1.setGerenciadorColisoes(&gerenciador_colisoes);
	p1.setGerenciadorColisoes(&gerenciador_colisoes);
	p2.setGerenciadorColisoes(&gerenciador_colisoes);

	p2.Rotacionar();

	Inserir_Entidade();

	Executar();
}

Jogo::~Jogo() 
{

}

void Jogo::Executar()
{
	Inserir_Colisao();

	float dT = 0.0f;
	sf::Clock relogio;

	while (gerenciador_grafico.JanelaAberta())
	{
		dT = relogio.restart().asSeconds();

		gerenciador_grafico.EventosJanela();

		gerenciador_colisoes.Checa_Colisao(&j1);

		j1.mover(dT);

		gerenciador_grafico.AjustarVista(&j1);

		gerenciador_grafico.DesenhaTudo(lista_entidades);
	}
}

void Jogo::Inserir_Entidade()
{
	lista_entidades.Inserir(static_cast<Entidade*>(&j1));
	lista_entidades.Inserir(static_cast<Entidade*>(&a1));
	lista_entidades.Inserir(static_cast<Entidade*>(&l1));
	lista_entidades.Inserir(static_cast<Entidade*>(&r1));
	lista_entidades.Inserir(static_cast<Entidade*>(&p1));
	lista_entidades.Inserir(static_cast<Entidade*>(&p2));
}

void Jogo::Inserir_Colisao()
{
	gerenciador_colisoes.InserirInimigo(static_cast<Inimigo*>(&a1));
	gerenciador_colisoes.InserirInimigo(static_cast<Inimigo*>(&l1));
	gerenciador_colisoes.InserirInimigo(static_cast<Inimigo*>(&r1));

	gerenciador_colisoes.InserirObstaculo(static_cast<Obstaculo*>(&p1));
	gerenciador_colisoes.InserirObstaculo(static_cast<Obstaculo*>(&p2));
}
