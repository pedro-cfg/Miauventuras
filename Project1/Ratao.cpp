#include "Ratao.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Ratao::Ratao():Inimigo()
{
	CarregaTextura("Texturas/ratao.png");
	valor = 3;
	setTipo();
}

Ratao::Ratao(float x, float y) :
	Inimigo() 
{
	CarregaTextura("Texturas/ratao.png");
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;

	Xinicial = x;

	setTipo();
	vidas = 3;
	valor = 3;
}

Ratao::~Ratao() 
{

}

void Ratao::setTipo()
{
	tipo = "Ratao";
}

void Ratao::Recuperar(float cX, float cY, float XI, int numVidas)
{
	setVidas(numVidas);
	Reposicionar(cX, cY);

	Xinicial = cX;

	pLista->Inserir(this);
	pGC->Inserir(this);
}
