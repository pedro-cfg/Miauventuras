#include "MenuPrincipal.h"
#include "Gerenciador_Grafico.h"
#include "Jogo.h"

using namespace Menus;

MenuPrincipal::MenuPrincipal():
	Menu()

{
	InicializaTexto();
	linhas_texto = 5;
}

MenuPrincipal::~MenuPrincipal()
{
}

void MenuPrincipal::InicializaTexto()
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
	texto[1].setString("Novo Jogo");
	texto[1].setCharacterSize(45);
	texto[1].setOrigin(sf::Vector2f(CalculaTamanho(texto[1]), 0.f));
	texto[1].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 3));
	texto[2].setFont(fonte);
	texto[2].setFillColor(sf::Color::Black);
	texto[2].setString("Carregar");
	texto[2].setCharacterSize(45);
	texto[2].setOrigin(sf::Vector2f(CalculaTamanho(texto[2]), 0.f));
	texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 145.f, ALTURA_JANELA / 6.f * 4));
	texto[3].setFont(fonte);
	texto[3].setFillColor(sf::Color::Black);
	texto[3].setString("Placar");
	texto[3].setCharacterSize(45);
	texto[3].setOrigin(sf::Vector2f(CalculaTamanho(texto[3]), 0.f));
	texto[3].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 145.f, ALTURA_JANELA / 6.f * 5));
	texto[4].setFont(fonte);
	texto[4].setFillColor(sf::Color::Black);
	texto[4].setString("Sair");
	texto[4].setCharacterSize(45);
	texto[4].setOrigin(sf::Vector2f(CalculaTamanho(texto[4]), 0.f));
	texto[4].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 145.f, ALTURA_JANELA / 6.f * 6));
}

void MenuPrincipal::Escolher_Opcao()
{
	switch (indice)
	{
	case 1: /*Novo Jogo*/
		pMaquinaEstados->setEstadoAtual(MENU_NUM_JOGADORES);
		break;
	case 2: /*Carregar*/
		pJogo->Carregar();
		break;
	case 3:	/*Placar*/
		eventoPlacar = true;
		pMaquinaEstados->setEstadoAtual(MENU_PLACAR);
		break;
	case 4: /*Sair*/
		pGG->FecharJanela();
		break;
	default:
		break;
	}
	indice = 1;
	setCorTexto();
}
