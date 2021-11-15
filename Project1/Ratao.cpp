#include "Ratao.h"

Ratao::Ratao(float x, float y) :
	Inimigo() 
{
	CarregaTextura("Texturas/ratao.png");
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;

	Xinicial = x;

	vidas = 3;
	valor = 3;
}

Ratao::~Ratao() 
{

}