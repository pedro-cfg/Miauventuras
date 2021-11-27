#include "Lagartixa.h"

int Lagartixa::cont = 0;
int Lagartixa::getQuantidade()
{
	return cont;
}

Lagartixa::Lagartixa():
	Inimigo()
{
	cont++;
	CarregaTextura(LAGARTIXA);
	valor = 2;
}

Lagartixa::Lagartixa(float x, float y) :
	Inimigo() 
{
	cont++;
	CarregaTextura(LAGARTIXA);
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;
	velocidadeEscalar = 500.f;

	Xinicial = x;

	valor = 2;
}

Lagartixa::~Lagartixa() 
{
	cont--;
}

void Lagartixa::reseta_velocidade()
{
	velocidadeEscalar = 500.0f;
}

void Lagartixa::Gravar()
{
	fstream arquivo;
	arquivo.open(LAGARTIXAS_SAVE, ios::binary | ios::out | ios::app);

	GravarInfo(arquivo);

	arquivo.close();
}
