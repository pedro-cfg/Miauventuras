#include "Plataforma.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Plataforma::Plataforma()
{
	CarregaTextura(PLATAFORMA);
	setTipo();
	ehPlataforma = true;
}

Plataforma::Plataforma(float x, float y) :
	Obstaculo() 
{
	CarregaTextura(PLATAFORMA);
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;

	setTipo();
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

void Plataforma::setTipo()
{
	tipo = "Plataforma";
}

void Plataforma::Recuperar(float cX, float cY, float XI, int numVidas, float velX, float velY)
{
	Reposicionar(cX, cY);

	pLista->Inserir(this);
	pGC->Inserir(this);
}


