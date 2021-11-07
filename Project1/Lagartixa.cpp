#include "Lagartixa.h"

Lagartixa::Lagartixa() :
	Inimigo() 
{
	forma.setPosition(sf::Vector2f(200.f, 200.f));
	textura.loadFromFile("Texturas/lagartixatmp.png");
	forma.setTexture(&textura);
}

Lagartixa::~Lagartixa() 
{

}