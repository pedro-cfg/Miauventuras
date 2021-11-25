#include "stdafx.h"
#include "Espinho.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Espinho::Espinho():Obstaculo()
{
	CarregaTextura(ESPINHO);
}

Espinho::Espinho(float x, float y) :
	Obstaculo() 
{
	this->x = x;
	this->y = y;
	CarregaTextura(ESPINHO);
	forma.setPosition(sf::Vector2f(x, y));
}

Espinho::~Espinho() {

}

void Espinho::ExecutaImpedimento(Jogador* pJ)
{
	if (pJ->getContador() > 1.f) {
		pJ->operator--();
	}
	pJ->Atualiza_Contador(0.f, true);
}

void Espinho::Recuperar(float cX, float cY, float XI, int numVidas, float velX, float velY)
{
	Reposicionar(cX, cY);

	pLista->Inserir(this);
	pGC->Inserir(this);
}

void Espinho::Gravar_Individual(fstream& arquivo)
{
	string tipo = "Espinho";
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
