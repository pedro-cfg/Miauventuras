#include "Teia.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Teia::Teia():
	Obstaculo()
{
	CarregaTextura(TEIA);
}

Teia::Teia(float x, float y):
	Obstaculo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura(TEIA);
	forma.setPosition(sf::Vector2f(x, y));
}

Teia::~Teia() 
{
}

void Teia::ExecutaImpedimento(Jogador* pJ)
{
	pJ->setVelocidadeEscalar(pJ->getVelocidadeEscalar() * 0.5f);
}

void Teia::Gravar()
{
	fstream arquivo;
	arquivo.open("Persistencia/Teias.bin", ios::binary | ios::out | ios::app);

	GravarInfo(arquivo);

	arquivo.close();
}
