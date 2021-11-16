#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo() :
	j1(0, -100),
	gerenciador_grafico(&j1,&menu_principal),
	primeira_fase(&j1),
	menu_principal(LARGURA_JANELA/2.f, ALTURA_JANELA/2.f, &primeira_fase)
{
	Ente::setGerenciadorGrafico(&gerenciador_grafico);

	primeira_fase.Inserir_Entidade(static_cast<Entidade*>(&j1));

	Executar();
}

Jogo::~Jogo() 
{

}

void Jogo::Executar()
{


	float dT = 0.0f;
	sf::Clock relogio;

	while (gerenciador_grafico.JanelaAberta())
	{
		dT = relogio.restart().asSeconds();

		menu_principal.Executar(dT);

		gerenciador_grafico.EventosJanela();

		primeira_fase.Executar(dT);

		gerenciador_grafico.LimparTela();
	}
}
