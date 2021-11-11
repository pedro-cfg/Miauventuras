#include "Aranha.h"

Aranha::Aranha(float x, float y):
	Inimigo()
{
	this->x = x;
	this->y = y;
	CarregaTextura("Texturas/aranha.png");
	forma.setPosition(sf::Vector2f(x, y));
}

Aranha::~Aranha() 
{

}