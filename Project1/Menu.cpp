#include "stdafx.h"
#include "Menu.h"
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"

//Menu::Menu(float largura, float altura, FasePrimeira* pFase) :
//	Ente(), 
//	pF(pFase)
//{
//	InicializaTexto(largura, altura);
//}

Menu::Menu(float largura, float altura, int* estado):
	Ente(),
	estado_jogo(estado)
{
	InicializaTexto(largura, altura);
}

Menu::~Menu() {

}

void Menu::InicializaTexto(float largura, float altura)
{
	indice = 0;
	fonte.loadFromFile("Fontes/arial.ttf");

	texto[0].setFont(fonte);
	texto[0].setFillColor(sf::Color::Green);
	texto[0].setString("Jogar Primeira Fase");
	texto[0].setPosition(sf::Vector2f(largura / 2.f, altura / 4.f * 1));

	texto[1].setFont(fonte);
	texto[1].setFillColor(sf::Color::White);
	texto[1].setString("Jogar Segunda Fase");
	texto[1].setPosition(sf::Vector2f(largura / 2.f, altura / 4.f * 2));

	texto[2].setFont(fonte);
	texto[2].setFillColor(sf::Color::White);
	texto[2].setString("Continuar");
	texto[2].setPosition(sf::Vector2f(largura / 2.f, altura / 4.f * 3));

	/*texto[3].setFont(fonte);
	texto[3].setFillColor(sf::Color::White);
	texto[3].setString("Salvar");
	texto[3].setPosition(sf::Vector2f(largura / 2.f, altura / 4.f * 4));*/

	texto[3].setFont(fonte);
	texto[3].setFillColor(sf::Color::White);
	texto[3].setString("Placar");
	texto[3].setPosition(sf::Vector2f(largura / 2.f, altura / 4.f * 4));

	texto[4].setFont(fonte);
	texto[4].setFillColor(sf::Color::White);
	texto[4].setString("Sair");
	texto[4].setPosition(sf::Vector2f(largura / 2.f, altura / 4.f * 5));

}

void Menu::Executar(float dT)
{
	pGG->RestaurarVista();
	imprimir_se();
}

void Menu::imprimir_se()
{
	pGG->DesenhaTexto(texto);
}

void Menu::Escolher_Opcao()
{
	switch (indice)
	{
	case 0:
		*estado_jogo = 1;
		break;
	case 1:
		*estado_jogo = 2;
		break;
	case 2:
		*estado_jogo = 3;
		break;
	case 3:
		/**/
		break;
	case 4:
		*estado_jogo = -1;
		break;
	default:
		break; 
	}
}

void Menu::opcao_acima()
{
	if (indice > 0) 
	{
		texto[indice].setFillColor(sf::Color::White);
		indice--;
		texto[indice].setFillColor(sf::Color::Green);
	}
}

void Menu::opcao_abaixo()
{
	if (indice < 4) 
	{
		texto[indice].setFillColor(sf::Color::White);
		indice++; 
		texto[indice].setFillColor(sf::Color::Green);
	}
}