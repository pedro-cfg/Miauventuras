#include "Ratao.h"

Ratao::Ratao(float x, float y) :
	Inimigo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura("Texturas/ratao.png");
	forma.setPosition(sf::Vector2f(x, y));
}

Ratao::~Ratao() 
{

}