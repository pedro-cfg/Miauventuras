#include "stdafx.h"
#include "Espinho.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Espinho::Espinho():Obstaculo()
{
	CarregaTextura(ESPINHO);
	setTipo();
	ehPlataforma = false;
}

Espinho::Espinho(float x, float y) :
	Obstaculo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura(ESPINHO);
	forma.setPosition(sf::Vector2f(x, y));

	setTipo();
	ehPlataforma = false;
}

Espinho::~Espinho() {

}

void Espinho::ExecutaImpedimento(Jogador* pJ)
{
	if (pJ->getContador() > 1.f) {
		pJ->sofreDano();
	}
	pJ->Atualiza_Contador(0.f, true);
}

void Espinho::setTipo()
{
	tipo = "Espinho";
}

void Espinho::Recuperar(float cX, float cY, float XI, int numVidas)
{
	Reposicionar(cX, cY);

	pLista->Inserir(this);
	pGC->Inserir(this);
}
