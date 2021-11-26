#include "Plataforma.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Plataforma::Plataforma():
	Obstaculo()
{
	EhPlataforma = true;
	CarregaTextura(PLATAFORMA);
}

Plataforma::Plataforma(float x, float y) :
	Obstaculo() 
{
	EhPlataforma = true;
	CarregaTextura(PLATAFORMA);
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;
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

void Plataforma::Gravar()
{
	fstream arquivo;
	arquivo.open("Persistencia/Plataformas.bin", ios::binary | ios::out | ios::app);

	GravarInfo(arquivo);

	arquivo.close();
}


