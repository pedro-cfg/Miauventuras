#include "Personagem.h"

Personagem::Personagem():
	Entidade()
{
	vidas = 3;
}

Personagem::~Personagem() {

}

int Personagem::getVidas() const
{
	return vidas;
}

void Personagem::sofreDano()
{
	this->operator--();
}

void Personagem::operator--()
{
	vidas--;
}

