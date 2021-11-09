#include "Jogador.h"

Jogador::Jogador()
{
	forma.setPosition(sf::Vector2f(512.f, 512.f));
	textura.loadFromFile("Texturas/jogadortmp.png");
	forma.setTexture(&textura);
}

Jogador::~Jogador() 
{

}