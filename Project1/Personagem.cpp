#include "Personagem.h"

Personagem::Personagem():
	textura(),
	forma(sf::Vector2f(100.f, 100.f))
{
	forma.setOrigin(forma.getSize() / 2.f);
}

Personagem::~Personagem() {

}

sf::RectangleShape Personagem::getForma() const
{
	return forma;
}

void Personagem::mover(float dx, float dy)
{
	forma.move(sf::Vector2f(dx, dy));
}

sf::Vector2f Personagem::getPosicao()
{
	return forma.getPosition();
}
