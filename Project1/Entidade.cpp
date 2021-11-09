#include "Entidade.h"

Entidade::Entidade()://public Ente
	textura(),
	forma(sf::Vector2f(100.f, 100.f))
{
	forma.setOrigin(forma.getSize() / 2.f);
}


Entidade::~Entidade() {

}

sf::RectangleShape Entidade::getForma() const
{
	return forma;
}

sf::Vector2f Entidade::getPosicao()
{
	return forma.getPosition();
}
