#include "Jogador1.h"

Jogador1::Jogador1(float x, float y):
	Jogador()
{
	CarregaTextura(JOGADOR1);
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;
}

Jogador1::Jogador1()
{
	CarregaTextura(JOGADOR1);
}

Jogador1::~Jogador1()
{
}

bool Jogador1::mover_esq()
{
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::A));
}

bool Jogador1::mover_dir()
{
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::D));
}

bool Jogador1::pular()
{
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::W));
}

