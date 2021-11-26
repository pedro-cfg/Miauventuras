#include "stdafx.h"
#include "Espinho.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Espinho::Espinho():Obstaculo()
{
	CarregaTextura(ESPINHO);
}

Espinho::Espinho(float x, float y) :
	Obstaculo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura(ESPINHO);
	forma.setPosition(sf::Vector2f(x, y));
}

Espinho::~Espinho() {

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
	arquivo.open("Persistencia/Espinhos.bin", ios::binary | ios::out | ios::app);

	GravarInfo(arquivo);

	arquivo.close();
}
