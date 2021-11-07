#include "Aranha.h"

Aranha::Aranha():
	Inimigo()
{
	forma.setPosition(sf::Vector2f(100.f, 100.f));
	textura.loadFromFile("Texturas/aranhatmp.png");
	forma.setTexture(&textura);
}

Aranha::~Aranha() 
{

}