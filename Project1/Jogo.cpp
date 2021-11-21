#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo() :
	estado_de_jogo(0),
	reinicio(true),
	pJ1(NULL),
	pJ2(NULL),
	gerenciador_grafico(&menu_principal),
	menu_principal(&estado_de_jogo, &dois_jogadores),
	primeira_fase(&estado_de_jogo, &reinicio),
	segunda_fase(&estado_de_jogo, &reinicio)
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
	if (pJ2 != NULL)
	{
		delete pJ2;
	}
}

void Jogo::Executar()
{
	float dT = 0.0f;
	sf::Clock relogio;

	while (gerenciador_grafico.JanelaAberta())
	{
		dT = relogio.restart().asSeconds();

		gerenciador_grafico.EventosJanela(&estado_de_jogo);

		switch (estado_de_jogo)
		{
		case -1: //Fechar Jogo
			gerenciador_grafico.FecharJanela();
			break;
		case 0: //Menu Principal
			menu_principal.Executar(dT);
			break;
		case 1: //Fase 1
			if (reinicio) {
				if (dois_jogadores)
					primeira_fase.reseta_fase(pJ1, pJ2);
				else
					primeira_fase.reseta_fase(pJ1, NULL);
				reinicio = false;
			}
			gerenciador_grafico.MudaFundo(1);
			pJ2->setFase(1);
			pJ1->setFase(1);
			primeira_fase.Executar(dT);
			break;
		case 2: //Fase 2
			if (reinicio) {
				if (dois_jogadores)
					segunda_fase.reseta_fase(pJ1, pJ2);
				else
					segunda_fase.reseta_fase(pJ1, NULL);
				reinicio = false;
			}
			gerenciador_grafico.MudaFundo(2);
			pJ2->setFase(2);
			pJ1->setFase(2);
			segunda_fase.Executar(dT);
			break;
		case 3: //Recuperar
			Ler();
			reinicio = false;
			estado_de_jogo = 7;
			break;
		case 4: //Menu de Pausa
			estado_de_jogo = 0;
			menu_principal.setEstadoMenu(2);
			menu_principal.setInicializar(true);
			menu_principal.setTamanhoTexto(4);
			break;
		case 5: //Gravar
			Gravar();
			estado_de_jogo = 0;
			break;
		case 6: //Zerar Fases
			reinicio = true;
			estado_de_jogo = 0;
			break;
		case 7: //Continuar Jogo
			reinicio = false;
			estado_de_jogo = pJ1->getFase();
			break;
		case 8: //Menu de Informar Nome
			menu_principal.setEstadoMenu(3);
			menu_principal.setInicializar(true);
			menu_principal.setTamanhoTexto(3);
			estado_de_jogo = 6;
		default:
			break;
		}

		gerenciador_grafico.AtualizarTela();
	}
}

void Jogo::Inicializar()
{
	Ente::setGerenciadorGrafico(&gerenciador_grafico);

	pJ1 = new Jogador1(0, -100);
	pJ2 = new Jogador2(0, -100);

	menu_principal.setJogadores(pJ1, pJ2);
	gerenciador_grafico.getMarcador1()->setJogador(static_cast<Jogador*>(pJ1));
	gerenciador_grafico.getMarcador2()->setJogador(static_cast<Jogador*>(pJ2));

	/*primeira_fase.setJogador1(pJ1);
	primeira_fase.setJogador2(pJ2);
	primeira_fase.Gerar_Objetos();

	segunda_fase.setJogador1(pJ1);
	segunda_fase.setJogador2(pJ2);
	segunda_fase.Gerar_Objetos();*/
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

	if (fase == 1) {
		if (dois_jogadores)
			primeira_fase.LerLista(arquivo, pJ1, pJ2);
		else
			primeira_fase.LerLista(arquivo, pJ1, NULL);
	}
	else {
		if (dois_jogadores)
			segunda_fase.LerLista(arquivo, pJ1, pJ2);
		else
			segunda_fase.LerLista(arquivo, pJ1, NULL);
	}
}

void Jogo::GravarJogador(fstream& arquivo)
{
	float x, y, x2, y2;
	int vidas, vidas2, pontos, pontos2;

	x = pJ1->getX();
	y = pJ1->getY();
	vidas = pJ1->getVidas();
	pontos = pJ1->getPontuacao();

	x2 = pJ2->getX();
	y2 = pJ2->getY();
	vidas2 = pJ2->getVidas();
	pontos2 = pJ2->getPontuacao();

	arquivo.write((char*)&x, sizeof(x));
	arquivo.write((char*)&y, sizeof(y));
	arquivo.write((char*)&vidas, sizeof(vidas));
	arquivo.write((char*)&pontos, sizeof(pontos));

	arquivo.write((char*)&x2, sizeof(x2));
	arquivo.write((char*)&y2, sizeof(y2));
	arquivo.write((char*)&vidas2, sizeof(vidas2));
	arquivo.write((char*)&pontos2, sizeof(pontos2));

	arquivo.write((char*)&dois_jogadores, sizeof(dois_jogadores));
}

void Jogo::LerJogador(fstream& arquivo)
{
	float x, y, x2, y2;
	int vidas, vidas2, pontos, pontos2;

	arquivo.read((char*)&x, sizeof(x));
	arquivo.read((char*)&y, sizeof(y));
	arquivo.read((char*)&vidas, sizeof(vidas));
	arquivo.read((char*)&pontos, sizeof(pontos));

	pJ1->setVidas(vidas);
	pJ1->setPontuacao(pontos);
	pJ1->Reposicionar(x, y);

	arquivo.read((char*)&x2, sizeof(x2));
	arquivo.read((char*)&y2, sizeof(y2));
	arquivo.read((char*)&vidas2, sizeof(vidas2));
	arquivo.read((char*)&pontos2, sizeof(pontos2));

	pJ2->setVidas(vidas2);
	pJ2->setPontuacao(pontos2);
	pJ2->Reposicionar(x2, y2);

	arquivo.read((char*)&dois_jogadores, sizeof(dois_jogadores));
}


