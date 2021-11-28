#include "Jogador2.h"

Jogador2::Jogador2(float x, float y)
{
	CarregaTextura(JOGADOR2);
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;
}

Jogador2::Jogador2()
{
	CarregaTextura(JOGADOR2);
}

Jogador2::~Jogador2()
{
}

bool Jogador2::mover_esq()
{
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::A));
}

bool Jogador2::mover_dir()
{
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::D));
}

bool Jogador2::pular()
{
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::W));
}
