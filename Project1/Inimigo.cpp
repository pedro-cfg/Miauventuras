#include "Inimigo.h"

Inimigo::Inimigo() :
	Personagem()
{
	setTipo();
	velocidadeEscalar = 100.f;
	amplitude = 500.f;
	vidas = 1;
	direcao = 1.0f;
}

Inimigo::~Inimigo()
{

}

void Inimigo::setTipo() {
	tipo = "Inimigo";
}

int Inimigo::getValor() const
{
	return valor;
}

void Inimigo::Executar(float dT)
{
	mover(dT);
}

void Inimigo::mover(float dT)
{
	if (abs(x - Xinicial) >= amplitude) 
	{
		velocidadeEscalar = -velocidadeEscalar;
		direcao = (abs(velocidadeEscalar) / velocidadeEscalar);

		if (x - Xinicial > 0.f)
		{
			Deslocar(-1.f, 0.f);
		}
		else
		{
			Deslocar(1.f, 0.f);
		}
	}

	float dx = velocidadeEscalar * dT;
	Deslocar(dx, 0.f);
}

float Inimigo::getDirecao() const
{
	return direcao;
}


