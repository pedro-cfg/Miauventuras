#include "Teia.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Teia::Teia():
	Obstaculo()
{
	CarregaTextura(TEIA);
	tipo = "Teia";
}

Teia::Teia(float x, float y):
	Obstaculo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura(TEIA);
	forma.setPosition(sf::Vector2f(x, y));

	tipo = "Teia";
}

Teia::~Teia() 
{

}

void Teia::ExecutaImpedimento(Jogador* pJ)
{
	pJ->setVelocidadeEscalar(pJ->getVelocidadeEscalar() * 0.5f);
}

void Teia::Recuperar(float cX, float cY, float XI, int numVidas, float velX, float velY)
{
	Reposicionar(cX, cY);

	pLista->Inserir(this);
	pGC->Inserir(this);
}
