#include "Personagem.h"

Personagem::Personagem():
	Entidade()
{
	vidas = 3;

	contador_tempo = 0.f;
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

void Personagem::Atualiza_Contador(float dT, bool zera)
{
	if (zera)
	{
		contador_tempo = 0.f;
	}
	else
	{
		contador_tempo += dT;
	}
}

float Personagem::getContador()
{
	return contador_tempo;
}