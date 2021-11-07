#include "stdafx.h"
#include "Ratao.h"

Ratao::Ratao() :
	Inimigo() 
{
	forma.setPosition(sf::Vector2f(300.f, 300.f));
	textura.loadFromFile("Texturas/rataotmp.png");
	forma.setTexture(&textura);
}

Ratao::~Ratao() 
{

}