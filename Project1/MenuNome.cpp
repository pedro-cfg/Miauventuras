#include "MenuNome.h"
#include "Jogo.h"

using namespace Menus;

MenuNome::MenuNome()
{
	InicializaTexto();
	linhas_texto = 3;
}

MenuNome::~MenuNome()
{
}

void MenuNome::InicializaTexto()
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
	texto[1].setString("Jogador 1, informe seu nome:");
	texto[1].setCharacterSize(45);
	texto[1].setOrigin(sf::Vector2f(CalculaTamanho(texto[1]), 0.f));
	texto[1].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f + 150.f, ALTURA_JANELA / 6.f * 3));
	texto[2].setFont(fonte);
	texto[2].setFillColor(sf::Color::Black);
	texto[2].setString("");
	texto[2].setCharacterSize(45);
	texto[2].setPosition(sf::Vector2f(LARGURA_JANELA / 2.f - 0.f, ALTURA_JANELA / 6.f * 4));
}

void MenuNome::Escolher_Opcao()
{
	string nome1 = pJogo->getJogador1()->getNome();
	string nome2 = pJogo->getJogador2()->getNome();

	texto[1].setString("Jogador 1, informe seu nome:");

	if (dois_jogadores)
	{
		if (nome1 == "")
		{
			pJogo->getJogador1()->setNome(texto[2].getString(), true);
			texto[1].setString("Jogador 2, informe seu nome:");
		}
		else if (nome2 == "")
		{
			pJogo->getJogador2()->setNome(texto[2].getString(), true);
			pMaquinaEstados->setEstadoAtual(MENU_FASES);
		}
	}
	else
	{
		pJogo->getJogador1()->setNome(texto[2].getString(), true);
		pMaquinaEstados->setEstadoAtual(MENU_FASES);
	}

	texto[2].setString("");
	indice = 1;
	setCorTexto();
}

void MenuNome::incluiTexto(char letra)
{
	string frase = texto[2].getString();
	frase += letra;
	texto[2].setString(frase);
}

void MenuNome::retiraTexto()
{
	string frase = texto[2].getString();
	if (frase != "")
		frase.pop_back();
	texto[2].setString(frase);
}
