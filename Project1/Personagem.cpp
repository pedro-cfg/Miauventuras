#include "Personagem.h"

Personagem::Personagem():
	Entidade()
{
	vidas = 3;

}

Personagem::~Personagem() 
{

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

void Personagem::mover(float dT)
{
}

void Personagem::setVelocidadeEscalar(float v)
{
	velocidadeEscalar = v;
}

float Personagem::getVelocidadeEscalar() const
{
	return velocidadeEscalar;
}

float Personagem::getContador()
{
	return contador_tempo;
}