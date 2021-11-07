#include "Jogador.h"

Jogador::Jogador()
{
	forma.setPosition(sf::Vector2f(0.f, 0.f));
	textura.loadFromFile("Texturas/jogadortmp.png");
	forma.setTexture(&textura);
}

Jogador::~Jogador() 
{

}