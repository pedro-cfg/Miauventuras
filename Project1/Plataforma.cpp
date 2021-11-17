#include "Plataforma.h"

Plataforma::Plataforma(float x, float y) : 
	Obstaculo() 
{
	CarregaTextura("Texturas/plataforma.png");
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;

	ehPlataforma = true;
}

Plataforma::~Plataforma() 
{

}

void Plataforma::ExecutaImpedimento(Personagem* pP, bool esq, bool dir, bool cima, bool baixo)
{
	pP->setColidiuEsquerda(esq);
	pP->setColidiuDireita(dir);
	pP->setColidiuCima(cima);
	pP->setColidiuBaixo(baixo);
}


