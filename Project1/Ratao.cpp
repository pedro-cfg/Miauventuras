#include "Ratao.h"

Ratao::Ratao(float x, float y) :
	Inimigo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura("Texturas/rataotmp.png");
	forma.setPosition(sf::Vector2f((float)x, (float)y));
}

Ratao::~Ratao() 
{

}