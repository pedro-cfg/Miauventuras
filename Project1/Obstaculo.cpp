#include "stdafx.h"
#include "Obstaculo.h"

Obstaculo::Obstaculo() :
	Entidade() 
{
	setTipo();
}

Obstaculo::~Obstaculo() {

}

void Obstaculo::Rotacionar()
{
	forma.setSize(sf::Vector2f(forma.getSize().y, forma.getSize().x));
	forma.setOrigin(forma.getSize().x/2.f, 0.f);
	forma.setRotation(180.f);
}

void Obstaculo::setTipo() {
	tipo = "Obstaculo";
}

