#include "MenuPausa.h"
#include "Jogo.h"

using namespace Menus;

MenuPausa::MenuPausa():
	Menu()
{
	linhas_texto = 4;
	InicializaTexto();
}

MenuPausa::~MenuPausa()
{
}

void MenuPausa::InicializaTexto()
{
	texto[0].setFont(fonte);
	texto[0].setFillColor(sf::Color::Black);
	texto[0].setString("Miauventuras");
	texto[0].setCharacterSize(180);
	texto[0].setOrigin(sf::Vector2f(CalculaTamanho(texto[0]), 160.f));
	texto[0].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 160.f, ALTURA_JANELA / 6.f * 1));
	texto[1].setFont(fonte);
	texto[1].setFillColor(sf::Color::Blue);
	texto[1].setString("Continuar");
	texto[1].setCharacterSize(45);
	texto[1].setOrigin(sf::Vector2f(CalculaTamanho(texto[1]), 0.f));
	texto[1].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 3));
	texto[2].setFont(fonte);
	texto[2].setFillColor(sf::Color::Black);
	texto[2].setString("Salvar");
	texto[2].setCharacterSize(45);
	texto[2].setOrigin(sf::Vector2f(CalculaTamanho(texto[2]), 0.f));
	texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 4));
	texto[3].setFont(fonte);
	texto[3].setFillColor(sf::Color::Black);
	texto[3].setString("Voltar para o Menu Principal");
	texto[3].setCharacterSize(45);
	texto[3].setOrigin(sf::Vector2f(CalculaTamanho(texto[3]), 0.f));
	texto[3].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 160.f, ALTURA_JANELA / 6.f * 5));
}

void MenuPausa::Escolher_Opcao()
{
	switch (indice)
	{
	case 1: /*Continuar jogada*/
		texto[2].setString("Salvar");
		if (pJogo->getJogador1()->getFase() == 1)
		{
			pMaquinaEstados->setEstadoAtual(PRIMEIRA_FASE);
		}
		else if (pJogo->getJogador1()->getFase() == 2)
		{
			pMaquinaEstados->setEstadoAtual(SEGUNDA_FASE);
		}
		break;
	case 2: /*Salvar jogada*/
		pJogo->Gravar();
		SalvarPontuacao();
		texto[2].setString("Jogo Salvo!");
		break;
	case 3: /*Voltar ao menu principal*/
		texto[2].setString("Salvar");
		//SalvarPontuacao();
		pJogo->getJogador1()->reseta_jogador(true, true, true);
		pJogo->getJogador2()->reseta_jogador(true, true, true);
		pMaquinaEstados->setEstadoAtual(MENU_PRINCIPAL);
		break;
	default:
		break;
	}
	indice = 1;
	setCorTexto();
}
