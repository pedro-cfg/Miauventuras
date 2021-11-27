#include "Teia.h"

int Teia::cont = 0;
int Teia::getQuantidade()
{
	return cont;
}

Teia::Teia():
	Obstaculo()
{
	cont++;
	CarregaTextura(TEIA);
}

Teia::Teia(float x, float y):
	Obstaculo() 
{
	cont++;
	this->x = x;
	this->y = y;
	CarregaTextura(TEIA);
	forma.setPosition(sf::Vector2f(x, y));
}

Teia::~Teia() 
{
	cont--;
}

void Teia::ExecutaImpedimento(Jogador* pJ)
{
	pJ->setVelocidadeEscalar(pJ->getVelocidadeEscalar() * 0.5f);
}

void Teia::Gravar()
{
	fstream arquivo;
	arquivo.open(TEIAS_SAVE, ios::binary | ios::out | ios::app);

	GravarInfo(arquivo);

	arquivo.close();
}
