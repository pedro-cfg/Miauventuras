#include "Plataforma.h"

Plataforma::Plataforma(float x, float y) : 
	Obstaculo() 
{
	CarregaTextura("Texturas/plataformatmp.png");
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;

	ehPlataforma = true;
}

Plataforma::~Plataforma() 
{

}

void Plataforma::ExecutaImpedimento(Jogador* pJ, bool esq, bool dir, bool cima, bool baixo)
{
	pJ->setColidiuEsquerda(esq);
	pJ->setColidiuDireita(dir);
	pJ->setColidiuCima(cima);
	pJ->setColidiuBaixo(baixo);
}


