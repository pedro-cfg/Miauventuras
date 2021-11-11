#include "stdafx.h"
#include "Obstaculo.h"

Obstaculo::Obstaculo() :
	Entidade() 
{

}

Obstaculo::~Obstaculo() {

}

void Obstaculo::Rotacionar()
{
	// forma.rotate(90.f);
	forma.setSize(sf::Vector2f(forma.getSize().y, forma.getSize().x));
	forma.setOrigin(forma.getSize().x/2.f, 0.f);
	forma.setRotation(180.f);
}

