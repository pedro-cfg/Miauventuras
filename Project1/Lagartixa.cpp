#include "Lagartixa.h"

Lagartixa::Lagartixa(float x, float y) :
	Inimigo() 
{
	CarregaTextura("Texturas/lagartixa.png");
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;
}

Lagartixa::~Lagartixa() 
{

}