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



Menu::Menu(float largura, float altura, int& estado):
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
	texto[0].setPosition(sf::Vector2f(largura / 2.f, altura / 2.f * 1));

	texto[1].setFont(fonte);
	texto[1].setFillColor(sf::Color::White);
	texto[1].setString("Jogar Segunda Fase");
	texto[1].setPosition(sf::Vector2f(largura / 2.f, altura / 2.f * 2));

	texto[2].setFont(fonte);
	texto[2].setFillColor(sf::Color::White);
	texto[2].setString("Placar");
	texto[2].setPosition(sf::Vector2f(largura / 2.f, altura / 2.f * 3));

	texto[3].setFont(fonte);
	texto[3].setFillColor(sf::Color::White);
	texto[3].setString("Sair");
	texto[3].setPosition(sf::Vector2f(largura / 2.f, altura / 2.f * 4));
}

void Menu::Executar(float dT)
{
	//if (executando == 0)
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
		estado_jogo = 1;
		break;
	case 1:
		estado_jogo = 2;
		break;
	case 2:
		/**/
		break;
	case 3:
		estado_jogo = -1;
	default:
		break;
	}
	//if (executando == 0) {
	//	switch (indice) {
	//	case 0:
	//		setExecutando(1);
	//		break;
	//	case 1:
	//		break;
	//	case 2:
	//		janela.close();
	//		break;
	//	}
	//}
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
	if (indice < 3) 
	{
		texto[indice].setFillColor(sf::Color::White);
		indice++;
		texto[indice].setFillColor(sf::Color::Green);
	}
}
