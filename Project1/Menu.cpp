#include "stdafx.h"
#include "Menu.h"
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"

Menu::Menu(float largura, float altura, FasePrimeira* pFase) :
	Ente(), 
	pF(pFase)
{
	indice = 0;
	fonte.loadFromFile("Fontes/arial.ttf");

	texto[0].setFont(fonte);
	texto[0].setFillColor(sf::Color::Green);
	texto[0].setString("Jogar");
	texto[0].setPosition(sf::Vector2f(largura / 2.f, altura / 2.f * 1));

	texto[1].setFont(fonte);
	texto[1].setFillColor(sf::Color::White);
	texto[1].setString("Placar");
	texto[1].setPosition(sf::Vector2f(largura / 2.f, altura / 2.f * 2));

	texto[2].setFont(fonte);
	texto[2].setFillColor(sf::Color::White);
	texto[2].setString("Sair");
	texto[2].setPosition(sf::Vector2f(largura / 2.f, altura / 2.f * 3));

	executando = true;
}

Menu::~Menu() {

}

void Menu::Executar(float dT)
{
	if(executando)
		imprimir_se();
}

void Menu::imprimir_se()
{
	pGG->DesenhaTexto(texto);
}

void Menu::Escolher_Opcao(sf::Window& janela)
{
	if (executando) {
		switch (indice) {
		case 0:
			pF->setExecutando(true);
			this->setExecutando(false);
			break;
		case 1:
			break;
		case 2:
			janela.close();
			break;
		}
	}
}

void Menu::opcao_acima()
{
	if (indice > 0) {
		texto[indice].setFillColor(sf::Color::White);
		indice--;
		texto[indice].setFillColor(sf::Color::Green);
	}
}

void Menu::opcao_abaixo()
{
	if (indice < 2) {
		texto[indice].setFillColor(sf::Color::White);
		indice++;
		texto[indice].setFillColor(sf::Color::Green);
	}
}
