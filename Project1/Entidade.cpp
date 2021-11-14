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
	textura(),
	forma(),
	x(0),
	y(0)
{
	setTipo();
	contador_tempo = 0.f;
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

void Entidade::Deslocar(float dx, float dy)
{
	forma.move(dx, dy);
	x += dx;
	y += dy;
}

void Entidade::setTipo()
{
	tipo = "";
}

const string Entidade::getTipo() const
{
	return tipo;
}

void Entidade::mover(float dT)
{
}

void Entidade::Executar(float dT)
{
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

void Entidade::Atualiza_Contador(float dT, bool zera)
{
	if (zera)
	{
		contador_tempo = 0.f;
	}
	else
	{
		contador_tempo += dT;
		if (contador_tempo > 20.f)
			contador_tempo = 0.f;
	}
}