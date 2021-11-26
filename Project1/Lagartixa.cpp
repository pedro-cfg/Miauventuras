#include "Lagartixa.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Lagartixa::Lagartixa():
	Inimigo()
{
	CarregaTextura(LAGARTIXA);
	valor = 2;

}

Lagartixa::Lagartixa(float x, float y) :
	Inimigo() 
{
	CarregaTextura(LAGARTIXA);
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;
	velocidadeEscalar = 500.f;

	Xinicial = x;

	valor = 2;
}

Lagartixa::~Lagartixa() 
{
}

void Lagartixa::reseta_velocidade()
{
	velocidadeEscalar = 500.0f;
}

void Lagartixa::Recuperar(float cX, float cY, float XI, int numVidas, float velX, float velY)
{
	setVidas(numVidas);
	Reposicionar(cX, cY);

	velocidadeX = velX;
	Xinicial = cX;

	pLista->Inserir(this);
	pGC->Inserir(this);
}

void Lagartixa::Gravar_Individual(fstream& arquivo)
{
	string tipo = "Lagartixa";
	int tamanho_tipo = tipo.size();
	arquivo.write((char*)&tamanho_tipo, sizeof(tamanho_tipo));
	arquivo.write((char*)&tipo[0], tamanho_tipo);

	arquivo.write((char*)&x, sizeof(x));
	arquivo.write((char*)&y, sizeof(y));
	arquivo.write((char*)&Xinicial, sizeof(Xinicial));
	arquivo.write((char*)&vidas, sizeof(vidas));
	arquivo.write((char*)&velocidadeEscalar, sizeof(velocidadeEscalar));
	arquivo.write((char*)&velocidadeEscalar, sizeof(velocidadeEscalar));
}
