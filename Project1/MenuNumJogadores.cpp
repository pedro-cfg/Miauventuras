#include "MenuNumJogadores.h"
#include "Jogo.h"

using namespace Menus;

MenuNumJogadores::MenuNumJogadores():
	Menu()
{
	linhas_texto = 4;
	InicializaTexto();
}

MenuNumJogadores::~MenuNumJogadores()
{
}

void MenuNumJogadores::InicializaTexto()
{
	texto[0].setFont(fonte);
	texto[0].setFillColor(sf::Color::Black);
	texto[0].setString("Miauventuras");
	texto[0].setCharacterSize(180);
	texto[0].setOrigin(sf::Vector2f(CalculaTamanho(texto[0]), 160.f));
	texto[0].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 160.f, ALTURA_JANELA / 6.f * 1));
	texto[1].setFont(fonte);
	texto[1].setFillColor(sf::Color::Blue);
	texto[1].setString("1 Jogador");
	texto[1].setCharacterSize(45);
	texto[1].setOrigin(sf::Vector2f(CalculaTamanho(texto[1]), 0.f));
	texto[1].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 3));
	texto[2].setFont(fonte);
	texto[2].setFillColor(sf::Color::Black);
	texto[2].setString("2 Jogadores");
	texto[2].setCharacterSize(45);
	texto[2].setOrigin(sf::Vector2f(CalculaTamanho(texto[2]), 0.f));
	texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 4));
	texto[3].setFont(fonte);
	texto[3].setFillColor(sf::Color::Black);
	texto[3].setString("Voltar");
	texto[3].setCharacterSize(45);
	texto[3].setOrigin(sf::Vector2f(CalculaTamanho(texto[3]), 0.f));
	texto[3].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 5));
}

void MenuNumJogadores::Escolher_Opcao()
{
	switch (indice)
	{
	case 1: /*1 jogador*/
		dois_jogadores = false;
		pMaquinaEstados->setEstadoAtual(MENU_NOME);
		break;
	case 2: /*2 jogadores*/
		dois_jogadores = true;
		pMaquinaEstados->setEstadoAtual(MENU_NOME);
		break;
	case 3: /*Voltar*/
		pMaquinaEstados->setEstadoAtual(MENU_PRINCIPAL);
		//pJogo->getJogador1()->setNome("");
		//pJogo->getJogador2()->setNome("");
		break;
	default:
		break;
	}
	indice = 1;
	setCorTexto();
}
