#include "Lagartixa.h"

Lagartixa::Lagartixa(float x, float y) :
	Inimigo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura("Texturas/lagartixatmp.png");
	forma.setPosition(sf::Vector2f((float)x, (float)y));
}

Lagartixa::~Lagartixa() 
{

}