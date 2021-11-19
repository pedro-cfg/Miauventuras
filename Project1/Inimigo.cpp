#include "Inimigo.h"
#include "Obstaculo.h"

Inimigo::Inimigo() :
	Personagem()
{
	vidas = 1;
	//setTipo();
	velocidadeEscalar = 100.f;
	amplitude = 500.f;
	vidas = 1;
	direcao = 1.0f;
}

Inimigo::~Inimigo()
{

}

//void Inimigo::setTipo() {
//	tipo = "Inimigo";
//}

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

float Inimigo::getDirecao() const
{
	return direcao;
}

void Inimigo::reseta_velocidade()
{
	velocidadeEscalar = 100.0f;
}

void Inimigo::InimigoEmPlataforma(Obstaculo* pO)
{
	Xinicial = pO->getX();
	amplitude = pO->getLargura()/2.f;
}

const float Inimigo::getXinicial() const
{
	return Xinicial;
}


