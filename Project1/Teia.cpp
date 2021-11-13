#include "Teia.h"

Teia::Teia(float x, float y):
	Obstaculo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura("Texturas/teia.png");
	forma.setPosition(sf::Vector2f(x, y));

	ehPlataforma = false;
}

Teia::~Teia() 
{

}

void Teia::ExecutaImpedimento(Jogador* pJ)
{
	pJ->setVelocidadeEscalar(pJ->getVelocidadeEscalar() * 0.5f);
}
