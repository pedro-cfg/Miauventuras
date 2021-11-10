#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo() :
	j1(500, 500),
	a1(100, 100),
	l1(200, 200),
	r1(300, 300),
	p1(600, 700),
	gerenciador_colisoes(&j1)
{
	j1.setGerenciadorGrafico(&gerenciador_grafico);
	a1.setGerenciadorGrafico(&gerenciador_grafico);
	l1.setGerenciadorGrafico(&gerenciador_grafico);
	r1.setGerenciadorGrafico(&gerenciador_grafico);
	p1.setGerenciadorGrafico(&gerenciador_grafico);

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

		gerenciador_colisoes.Checa_Colisao();

		j1.mover(dT, &gerenciador_colisoes);

		gerenciador_grafico.AjustarVista(&j1);

		gerenciador_grafico.DesenhaTudo(static_cast<Entidade*>(&j1), static_cast<Entidade*>(&a1), 
										static_cast<Entidade*>(&l1), static_cast<Entidade*>(&r1), 
										static_cast<Entidade*>(&p1));
	}
}

void Jogo::Inserir_Colisao()
{
	gerenciador_colisoes.InserirInimigo(static_cast<Inimigo*>(&a1));
	gerenciador_colisoes.InserirInimigo(static_cast<Inimigo*>(&l1));
	gerenciador_colisoes.InserirInimigo(static_cast<Inimigo*>(&r1));

	gerenciador_colisoes.InserirObstaculo(static_cast<Obstaculo*>(&p1));
}
