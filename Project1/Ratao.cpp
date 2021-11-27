#include "Ratao.h"

int Ratao::cont = 0;
int Ratao::getQuantidade()
{
	return cont;
}

Ratao::Ratao():Inimigo()
{
	cont++;
	CarregaTextura(RATAO);
	valor = 3;
	ehChefao = true;
}

Ratao::Ratao(float x, float y) :
	Inimigo() 
{
	cont++;
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
	cont--;
}

void Ratao::reseta_cont()
{
	cont = 0;
}

void Ratao::diminui_cont()
{
	cont--;
}

void Ratao::Gravar()
{
	fstream arquivo;
	arquivo.open(RATAO_SAVE, ios::binary | ios::out | ios::app);

	GravarInfo(arquivo);
	
	arquivo.close();
}
