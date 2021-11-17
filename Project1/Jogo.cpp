#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo() :
	//j1(0, -100),
	pJ1(NULL),
	gerenciador_grafico(&menu_principal),
	primeira_fase(),
	menu_principal(LARGURA_JANELA/2.f, ALTURA_JANELA/2.f, &primeira_fase)
{
	Inicializar();
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

		gerenciador_grafico.EventosJanela();

		menu_principal.Executar(dT);

		primeira_fase.Executar(dT);

		gerenciador_grafico.LimparTela();
	}
}

void Jogo::Inicializar()
{
	Ente::setGerenciadorGrafico(&gerenciador_grafico);

	pJ1 = new Jogador(0, -100);

	gerenciador_grafico.getMarcador()->setJogador(pJ1);

	primeira_fase.setJogador(pJ1);
	primeira_fase.Inserir_Entidade(static_cast<Entidade*>(pJ1));
	primeira_fase.Gerar_Objetos();
}
