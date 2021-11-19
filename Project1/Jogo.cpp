#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo() :
	//j1(0, -100),
	estado_de_jogo(0),
	pJ1(NULL),
	gerenciador_grafico(&menu_principal),
	primeira_fase(&estado_de_jogo),
	segunda_fase(&estado_de_jogo),
	menu_principal(LARGURA_JANELA/2.f, ALTURA_JANELA/2.f, estado_de_jogo)
{
	Inicializar();
	Executar();
}

Jogo::~Jogo() 
{
	if (pJ1 != NULL)
	{
		delete pJ1;
	}
}

void Jogo::Executar()
{
	float dT = 0.0f;
	sf::Clock relogio;

	while (gerenciador_grafico.JanelaAberta())
	{
		dT = relogio.restart().asSeconds();

		gerenciador_grafico.EventosJanela(estado_de_jogo);

		switch (estado_de_jogo)
		{
		case -1:
			gerenciador_grafico.FecharJanela();
			break;
		case 0:
			menu_principal.Executar(dT);
			break;
		case 1:
			primeira_fase.Executar(dT);
			break;
		case 2:
			segunda_fase.Executar(dT);
			break;
		default:
			break;
		}

		gerenciador_grafico.LimparTela();
	}
}

void Jogo::Inicializar()
{
	Ente::setGerenciadorGrafico(&gerenciador_grafico);

	pJ1 = new Jogador(0, -100);

	gerenciador_grafico.getMarcador()->setJogador(pJ1);

	primeira_fase.setJogador(pJ1);
	primeira_fase.Gerar_Objetos();

	segunda_fase.setJogador(pJ1);
	segunda_fase.Gerar_Objetos();

	//primeira_fase.setJogador(pJ1);
	//primeira_fase.Inserir_Entidade(static_cast<Entidade*>(pJ1));
	//primeira_fase.Gerar_Objetos();
}
