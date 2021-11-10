#include "Entidade.h"
#include "Gerenciador_Grafico.h"

Entidade::Entidade() :
	Ente(),
	textura(),
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
	textura.loadFromFile(caminho);
	forma.setSize((sf::Vector2f)textura.getSize());
	forma.setTexture(&textura);
	forma.setOrigin(forma.getSize() / 2.0f);
}
void Entidade::desenhar()
{
	gerenciar_graficos->DesenhaForma(forma);
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