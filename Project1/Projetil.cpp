#include "stdafx.h"
#include "Projetil.h"

int Projetil::cont = 0;
int Projetil::getQuantidade()
{
	return cont;
}

Projetil::Projetil()
{
	cont++;
	CarregaTextura(PROJETIL);
	velocidadeEscalar = 700.f;
	contador_tempo = 0.f;
	velocidadeX = 0.0f;
	velocidadeY = 0.0f;
}

Projetil::Projetil(Aranha* pAr) :
	Entidade() 
{
	cont++;
	x = pAr->getX();
	y = pAr->getY();
	CarregaTextura(PROJETIL);
	forma.setPosition(sf::Vector2f(x, y));

	velocidadeEscalar = 700.f;
	velocidadeX = velocidadeEscalar * pAr->getDirecao();
	velocidadeY = -velocidadeEscalar;

	contador_tempo = 0.f;
}

Projetil::~Projetil() 
{
	cont--;
}

void Projetil::Executar(float dT)
{
	mover(dT);
}

const float Projetil::getVelX() const
{
	return velocidadeX;
}

const float Projetil::getVelY() const
{
	return velocidadeY;
}

void Projetil::Carregar(fstream& arquivo)
{
	arquivo.read((char*)&x, sizeof(x));
	arquivo.read((char*)&y, sizeof(y));
	arquivo.read((char*)&velocidadeX, sizeof(velocidadeX));
	arquivo.read((char*)&velocidadeY, sizeof(velocidadeY));

	Reposicionar(x, y);
}

void Projetil::GravarInfo(fstream& arquivo)
{
	arquivo.write((char*)&x, sizeof(x));
	arquivo.write((char*)&y, sizeof(y));
	arquivo.write((char*)&velocidadeX, sizeof(velocidadeX));
	arquivo.write((char*)&velocidadeY, sizeof(velocidadeY));
}

void Projetil::mover(float dT)
{
	velocidadeY += 981.0f * dT;

	Atualiza_Contador(dT);

	float dx = velocidadeX * dT;
	float dy = velocidadeY * dT;

	Deslocar(dx, dy);
}