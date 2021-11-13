#include "stdafx.h"
#include "Espinho.h"

Espinho::Espinho(float x, float y) :
	Obstaculo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura("Texturas/espinho.png");
	forma.setPosition(sf::Vector2f(x, y));

	ehPlataforma = false;
}

Espinho::~Espinho() {

}

void Espinho::ExecutaImpedimento(Jogador* pJ)
{
	pJ->sofreDano();
}
