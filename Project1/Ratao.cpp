#include "Ratao.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Ratao::Ratao():Inimigo()
{
	CarregaTextura(RATAO);
	valor = 3;
	ehChefao = true;
}

Ratao::Ratao(float x, float y) :
	Inimigo() 
{
	CarregaTextura(RATAO);
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;

	Xinicial = x;

	vidas = 3;
	valor = 3;
	ehChefao = true;
}

Ratao::~Ratao() 
{

}

void Ratao::Recuperar(float cX, float cY, float XI, int numVidas, float velX, float velY)
{
	setVidas(numVidas);
	Reposicionar(cX, cY);

	velocidadeX = velX;
	Xinicial = cX;

	pLista->Inserir(this);
	pGC->Inserir(this);
}

void Ratao::Gravar_Individual(fstream& arquivo)
{
	string tipo = "Ratao";
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
