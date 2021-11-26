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

void Lagartixa::Gravar()
{
	fstream arquivo;
	arquivo.open("Persistencia/Lagartixas.bin", ios::binary | ios::out | ios::app);

	GravarInfo(arquivo);

	arquivo.close();
}
