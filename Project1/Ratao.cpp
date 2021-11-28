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

void Ratao::mover(float dT)
{
	velocidadeEscalar = 400.f;
	tempo += dT;

	velocidadeX = 0.0f;

	if (colidiu_cima)
	{
		velocidadeY = 0.0f;
	}
	if (!colidiu_baixo && abs(y) >= getAltura() / 2.f)
	{
		velocidadeY += 981.0f * dT;
	}
	else
		velocidadeY = 0.0f;

	if (tempo >= 2.f) 
	{
		tempo = 0.f;
		velocidadeY = -700.f;
	}

	if (direcao > 0)
	{
		if (!colidiu_direita)
		{
			velocidadeX += velocidadeEscalar;
		}
	}
	if (direcao < 0)
	{
		if (!colidiu_esquerda)
		{
			velocidadeX -= velocidadeEscalar;
		}
	}

	if (abs(x - Xinicial) >= amplitude)
	{
		velocidadeX = -velocidadeX;
		direcao = (abs(velocidadeX) / velocidadeX);

		if (x - Xinicial > 0.f)
		{
			Deslocar(-1.f, 0.f);
		}
		else
		{
			Deslocar(1.f, 0.f);
		}
	}

	float dx = velocidadeX * dT;
	float dy = velocidadeY * dT;

	Deslocar(dx, dy);
}

void Ratao::Gravar()
{
	fstream arquivo;
	arquivo.open(RATAO_SAVE, ios::binary | ios::out | ios::app);

	GravarInfo(arquivo);
	
	arquivo.close();
}
