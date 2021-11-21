#include "Lagartixa.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Lagartixa::Lagartixa():Inimigo()
{
	CarregaTextura(LAGARTIXA);
	valor = 2;
	setTipo();
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
	setTipo();
}

Lagartixa::~Lagartixa() 
{

}

void Lagartixa::reseta_velocidade()
{
	velocidadeEscalar = 500.0f;
}

void Lagartixa::setTipo()
{
	tipo = "Lagartixa";
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
