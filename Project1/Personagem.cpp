#include "Personagem.h"

Personagem::Personagem():
	Entidade()
{
	vidas = 0;
	velocidadeX = 0.0f;
	velocidadeY = 0.0f;
	reseta_colidiu();
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

void Personagem::reseta_velocidade()
{
}

void Personagem::setVelocidadeY(float v)
{
	velocidadeY = v;
}

void Personagem::setVelocidadeX(float v)
{
	velocidadeX = v;
}

float Personagem::getContador()
{
	return contador_tempo;
}

void Personagem::reseta_colidiu()
{
	colidiu_baixo = colidiu_cima = colidiu_direita = colidiu_esquerda = false;
}

void Personagem::setColidiuCima(bool colidiu)
{
	colidiu_cima = colidiu;
}

void Personagem::setColidiuBaixo(bool colidiu)
{
	colidiu_baixo = colidiu;
}

void Personagem::setColidiuDireita(bool colidiu)
{
	colidiu_direita = colidiu;
}

void Personagem::setColidiuEsquerda(bool colidiu)
{
	colidiu_esquerda = colidiu;
}


bool Personagem::getColidiuCima() const
{
	return colidiu_cima;
}

bool Personagem::getColidiuBaixo() const
{
	return colidiu_baixo;
}

bool Personagem::getColidiuDireita() const
{
	return colidiu_direita;
}

bool Personagem::getColidiuEsquerda() const
{
	return colidiu_esquerda;
}