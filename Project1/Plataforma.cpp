#include "Plataforma.h"

Plataforma::Plataforma(float x, float y) : 
	Obstaculo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura("Texturas/plataformatmp.png");
	forma.setPosition(sf::Vector2f(x, y));
}

Plataforma::~Plataforma() {

}

