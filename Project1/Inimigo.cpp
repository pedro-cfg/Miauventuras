#include "Inimigo.h"

Inimigo::Inimigo() :
	Personagem()
{
	setTipo();
	velocidadeEscalar = 100.f;
	amplitude = 500.f;
	Xinicial = getX();
	vidas = 1;
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
	if (abs(getX() - Xinicial) > amplitude) {
		velocidadeEscalar = -velocidadeEscalar;
		if ((getX() - Xinicial) > 0.f)
			Movimentar(-1.f, 0.f);
		else
			Movimentar(1.f, 0.f);
	}

	float dx = velocidadeEscalar * dT;
	Movimentar(dx, 0.f);
}


