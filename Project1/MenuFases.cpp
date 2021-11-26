#include "MenuFases.h"
#include "Jogo.h"

using namespace Menus;

MenuFases::MenuFases():
	Menu()
{
	InicializaTexto();
	linhas_texto = 4;
}

MenuFases::~MenuFases()
{
}

void MenuFases::InicializaTexto()
{
	fonte.loadFromFile("Fontes/SIXTY.ttf");
	texto[0].setFont(fonte);
	texto[0].setFillColor(sf::Color::Black);
	texto[0].setString("OJogoDoGato");
	texto[0].setCharacterSize(180);
	texto[0].setOrigin(sf::Vector2f(CalculaTamanho(texto[0]), 160.f));
	texto[0].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 160.f, ALTURA_JANELA / 6.f * 1));
	texto[1].setFont(fonte);
	texto[1].setFillColor(sf::Color::Blue);
	texto[1].setString("Iniciar Fase 1");
	texto[1].setCharacterSize(45);
	texto[1].setOrigin(sf::Vector2f(CalculaTamanho(texto[1]), 0.f));
	texto[1].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 3));
	texto[2].setFont(fonte);
	texto[2].setFillColor(sf::Color::Black);
	texto[2].setString("Iniciar Fase 2");
	texto[2].setCharacterSize(45);
	texto[2].setOrigin(sf::Vector2f(CalculaTamanho(texto[2]), 0.f));
	texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 145.f, ALTURA_JANELA / 6.f * 4));
	texto[3].setFont(fonte);
	texto[3].setFillColor(sf::Color::Black);
	texto[3].setString("Voltar");
	texto[3].setCharacterSize(45);
	texto[3].setOrigin(sf::Vector2f(CalculaTamanho(texto[3]), 0.f));
	texto[3].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 145.f, ALTURA_JANELA / 6.f * 5));
}

void MenuFases::Escolher_Opcao()
{
	switch (indice)
	{
	case 1: /*Fase 1*/
		pJogo->MudaFundo(1);
		pMaquinaEstados->setEstadoAtual(PRIMEIRA_FASE);
		if (dois_jogadores)
		{
			pJogo->getPrimeiraFase()->reseta_fase(pJogo->getJogador1(), pJogo->getJogador2(), true);
			pJogo->getJogador1()->setFase(1);
			pJogo->getJogador2()->setFase(1);
		}
		else
		{
			pJogo->getPrimeiraFase()->reseta_fase(pJogo->getJogador1(), NULL, true);
			pJogo->getJogador1()->setFase(1);
		}
		break;
	case 2: /*Fase 2*/
		pJogo->MudaFundo(2);
		pMaquinaEstados->setEstadoAtual(SEGUNDA_FASE);
		if (dois_jogadores)
		{
			pJogo->getSegundaFase()->reseta_fase(pJogo->getJogador1(), pJogo->getJogador2(), true);
			pJogo->getJogador1()->setFase(2);
			pJogo->getJogador2()->setFase(2);
		}
		else
		{
			pJogo->getSegundaFase()->reseta_fase(pJogo->getJogador1(), NULL, true);
			pJogo->getJogador1()->setFase(2);
		}
		break;
	case 3: /*Voltar*/
		pJogo->getJogador1()->setNome("");
		pJogo->getJogador2()->setNome("");
		pMaquinaEstados->setEstadoAtual(MENU_NUM_JOGADORES);
		break;
	default:
		break;
	}
	indice = 1;
	setCorTexto();
}
