#include "Lagartixa.h"

Lagartixa::Lagartixa(float x, float y) :
	Inimigo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura("Texturas/lagartixa.png");
	forma.setPosition(sf::Vector2f(x, y));
}

Lagartixa::~Lagartixa() 
{

}