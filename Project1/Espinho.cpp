#include "stdafx.h"
#include "Espinho.h"

int Espinho::cont = 0;
int Espinho::getQuantidade()
{
	return cont;
}

Espinho::Espinho():Obstaculo()
{
	cont++;
	CarregaTextura(ESPINHO);
}

Espinho::Espinho(float x, float y) :
	Obstaculo() 
{
	cont++;
	this->x = x;
	this->y = y;
	CarregaTextura(ESPINHO);
	forma.setPosition(sf::Vector2f(x, y));
}

Espinho::~Espinho() 
{
	cont--;
}

void Espinho::ExecutaImpedimento(Jogador* pJ)
{
	if (pJ->getContador() > 1.f) {
		pJ->operator--();
	}
	pJ->Atualiza_Contador(0.f, true);
}

void Espinho::Gravar()
{
	fstream arquivo;
	arquivo.open(ESPINHOS_SAVE, ios::binary | ios::out | ios::app);

	GravarInfo(arquivo);

	arquivo.close();
}