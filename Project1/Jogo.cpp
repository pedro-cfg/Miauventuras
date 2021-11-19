#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo() :
	//j1(0, -100),
	estado_de_jogo(0),
	reinicio(true),
	pJ1(NULL),
	gerenciador_grafico(&menu_principal),
	primeira_fase(&estado_de_jogo, &reinicio),
	segunda_fase(&estado_de_jogo, &reinicio),
	menu_principal(LARGURA_JANELA / 2.f, ALTURA_JANELA / 2.f, estado_de_jogo)
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
			if (reinicio) {
				primeira_fase.reseta_fase();
				gerenciador_grafico.MudaFundo(1);
				pJ1->setFase(1);
				reinicio = false;
			}
			primeira_fase.Executar(dT);
			break;
		case 2:
			if (reinicio) {
				segunda_fase.reseta_fase();
				gerenciador_grafico.MudaFundo(2);
				pJ1->setFase(2);
				reinicio = false;
			}
			segunda_fase.Executar(dT);
			break;
		case 3:
			Ler();
			reinicio = false;
			estado_de_jogo = pJ1->getFase();
			break;
		case 4:
			Gravar();
			reinicio = true;
			estado_de_jogo = 0;
			/*primeira_fase.reseta_fase();
			segunda_fase.reseta_fase();*/
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
}

void Jogo::Gravar()
{
	fstream arquivo;
	arquivo.open("Persistencia/memoria.bin", ios::binary | ios::out | ios::trunc);

	int fase = pJ1->getFase();
	arquivo.write((char*)&fase, sizeof(fase));

	GravarJogador(arquivo);
	if (fase == 1)
		primeira_fase.GravarLista(arquivo);
	else
		segunda_fase.GravarLista(arquivo);
}

void Jogo::Ler()
{
	fstream arquivo;
	arquivo.open("Persistencia/memoria.bin", ios::binary | ios::in);

	int fase;
	arquivo.read((char*)&fase, sizeof(fase));

	pJ1->setFase(fase);

	LerJogador(arquivo);
	if (fase == 1)
		primeira_fase.LerLista(arquivo);
	else
		segunda_fase.LerLista(arquivo);
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


