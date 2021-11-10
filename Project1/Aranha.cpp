#include "Aranha.h"

Aranha::Aranha(float x, float y):
	Inimigo()
{
	this->x = x;
	this->y = y;
	CarregaTextura("Texturas/aranhatmp.png");
	forma.setPosition(sf::Vector2f((float)x, (float)y));
}

Aranha::~Aranha() 
{

}