#include "Ratao.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Ratao::Ratao():Inimigo()
{
	CarregaTextura(RATAO);
	valor = 3;
	tipo = "Ratao";
}

Ratao::Ratao(float x, float y) :
	Inimigo() 
{
	CarregaTextura(RATAO);
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;

	Xinicial = x;

	tipo = "Ratao";
	vidas = 3;
	valor = 3;
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