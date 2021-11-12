#include "Marcador_Vida.h"

Marcador_Vida::Marcador_Vida(float x, float y)
{
	this->x = x;
	this->y = y;
	CarregaTextura("Texturas/Numeros/numero3.png");
	forma.setPosition(sf::Vector2f(x, y));
}

Marcador_Vida::~Marcador_Vida()
{
}
