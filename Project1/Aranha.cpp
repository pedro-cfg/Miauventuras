#include "Aranha.h"

Aranha::Aranha(float x, float y):
	Inimigo()
{
	CarregaTextura("Texturas/aranha.png");
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;
}

Aranha::~Aranha() 
{

}