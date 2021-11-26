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

void Ratao::Gravar()
{
	fstream arquivo;
	arquivo.open("Persistencia/Ratao.bin", ios::binary | ios::out | ios::app);

	GravarInfo(arquivo);
	
	arquivo.close();
}
