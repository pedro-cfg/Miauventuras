#include "Plataforma.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

int Plataforma::cont = 0;
int Plataforma::getQuantidade()
{
	return cont;
}

Plataforma::Plataforma():
	Obstaculo()
{
	cont++;
	EhPlataforma = true;
	CarregaTextura(PLATAFORMA);
}

Plataforma::Plataforma(float x, float y) :
	Obstaculo() 
{
	cont++;
	EhPlataforma = true;
	CarregaTextura(PLATAFORMA);
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;
}

Plataforma::~Plataforma() 
{
	cont--;
}

void Plataforma::ExecutaImpedimento(Personagem* pP, bool esq, bool dir, bool cima, bool baixo)
{
	pP->setColidiuEsquerda(esq);
	pP->setColidiuDireita(dir);
	pP->setColidiuCima(cima);
	pP->setColidiuBaixo(baixo);
}

void Plataforma::Gravar()
{
	fstream arquivo;
	arquivo.open(PLATAFORMAS_SAVE, ios::binary | ios::out | ios::app);

	GravarInfo(arquivo);

	arquivo.close();
}


