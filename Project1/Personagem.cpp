#include "Personagem.h"

Personagem::Personagem():
	Entidade()
{
}

Personagem::~Personagem() {

}

int Personagem::getVidas() const
{
	return vidas;
}

void Personagem::operator--()
{
	vidas--;
}

