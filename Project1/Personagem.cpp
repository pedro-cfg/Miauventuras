#include "Personagem.h"

Personagem::Personagem():Entidade()
{
}

Personagem::~Personagem() {

}


void Personagem::mover(float dx, float dy)
{
	forma.move(sf::Vector2f(dx, dy));
}
