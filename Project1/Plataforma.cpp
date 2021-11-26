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

void Plataforma::Recuperar(float cX, float cY, float XI, int numVidas, float velX, float velY)
{
	Reposicionar(cX, cY);

	pLista->Inserir(this);
	pGC->Inserir(this);
}

void Plataforma::Gravar_Individual(fstream& arquivo)
{
	string tipo = "Plataforma";
	int tamanho_tipo = tipo.size();
	arquivo.write((char*)&tamanho_tipo, sizeof(tamanho_tipo));
	arquivo.write((char*)&tipo[0], tamanho_tipo);

	arquivo.write((char*)&x, sizeof(x));
	arquivo.write((char*)&y, sizeof(y));
	arquivo.write((char*)&x, sizeof(x));
	arquivo.write((char*)&y, sizeof(y));
	arquivo.write((char*)&x, sizeof(x));
	arquivo.write((char*)&y, sizeof(y));
}


