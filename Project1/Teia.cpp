#include "Teia.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Teia::Teia()
{
	CarregaTextura(TEIA);
	setTipo();
	ehPlataforma = false;
}

Teia::Teia(float x, float y):
	Obstaculo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura(TEIA);
	forma.setPosition(sf::Vector2f(x, y));

	setTipo();
	ehPlataforma = false;
}

Teia::~Teia() 
{

}

void Teia::ExecutaImpedimento(Jogador* pJ)
{
	pJ->setVelocidadeEscalar(pJ->getVelocidadeEscalar() * 0.5f);
}

void Teia::setTipo()
{
	tipo = "Teia";
}

void Teia::Recuperar(float cX, float cY, float XI, int numVidas)
{
	Reposicionar(cX, cY);

	pLista->Inserir(this);
	pGC->Inserir(this);
}
