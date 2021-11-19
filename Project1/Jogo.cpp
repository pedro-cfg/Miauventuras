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
		case 3:
			Gravar();
			estado_de_jogo = 0;
			break;
		case 4:
			Ler();
			estado_de_jogo = 0;
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

void Jogo::Gravar()
{
	fstream arquivo;
	arquivo.open("Persistencia/cudosimao.bin", ios::binary | ios::out | ios::trunc);

	GravarJogador(arquivo);
	primeira_fase.GravarLista(arquivo);
}

void Jogo::Ler()
{
	fstream arquivo;
	arquivo.open("Persistencia/cudosimao.bin", ios::binary | ios::in);

	LerJogador(arquivo);
	primeira_fase.LerLista(arquivo);
}

void Jogo::GravarJogador(fstream& arquivo)
{
	float x, y;
	int vidas;

	x = pJ1->getX();
	y = pJ1->getY();
	vidas = pJ1->getVidas();

	arquivo.write((char*)&x, sizeof(x));
	arquivo.write((char*)&y, sizeof(y));
	arquivo.write((char*)&vidas, sizeof(vidas));
}

void Jogo::LerJogador(fstream& arquivo)
{
	float x, y;
	int vidas;

	arquivo.read((char*)&x, sizeof(x));
	arquivo.read((char*)&y, sizeof(y));
	arquivo.read((char*)&vidas, sizeof(vidas));

	pJ1->setVidas(vidas);
	pJ1->Reposicionar(x, y);
}


