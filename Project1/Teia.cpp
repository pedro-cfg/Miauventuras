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

void Teia::Recuperar(float cX, float cY, float XI, int numVidas, float velX, float velY)
{
	Reposicionar(cX, cY);

	pLista->Inserir(this);
	pGC->Inserir(this);
}

void Teia::Gravar_Individual(fstream& arquivo)
{
	string tipo = "Teia";
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
