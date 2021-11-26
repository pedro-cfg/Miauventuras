#include "Entidade.h"
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colisoes.h"
#include "ListaEntidades.h"

/*Ponteiro estático para gerenciador de colisões e lista de entidades*/
Gerenciador_Colisoes* Entidade::pGC = NULL;
void Entidade::setGerenciadorColisoes(Gerenciador_Colisoes* pG)
{
	pGC = pG;
}

ListaEntidades* Entidade::pLista = NULL;
void Entidade::setPonteiroLista(ListaEntidades* pL)
{
	pLista = pL;
}


Entidade::Entidade() :
	Ente(),
	forma(),
	x(0),
	y(0)
{
}

Entidade::~Entidade() 
{
}

void Entidade::CarregaTextura(string caminho)
{
	sf::Texture* pAux = pGG->getMapaTexturas()[caminho];
	forma.setSize((sf::Vector2f)pAux->getSize());
	forma.setTexture(pAux);
	forma.setOrigin(forma.getSize() / 2.0f);
}

void Entidade::Reposicionar(float X, float Y)
{
	forma.setPosition(sf::Vector2f(X, Y));
	setX(X);
	setY(Y);
}

void Entidade::Deslocar(float dx, float dy)
{
	forma.move(dx, dy);
	x += dx;
	y += dy;
}

void Entidade::desenhar()
{
	pGG->DesenhaForma(forma);
}

void Entidade::setX(float x)
{
	this->x = x;
}
void Entidade::setY(float y)
{
	this->y = y;
}
float Entidade::getX() const
{
	return x;
}
float Entidade::getY() const
{
	return y;
}

float Entidade::getAltura() const
{
	return forma.getSize().y;
}

float Entidade::getLargura() const
{
	return forma.getSize().x;
}
