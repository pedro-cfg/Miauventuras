#include "Jogador.h"
#include "Gerenciador_Colisoes.h"

Jogador::Jogador(float x, float y) :
	Personagem()
{
	pontos = 0;
	vidas = 3;
	velocidadeEscalar = 400.0f;
	velocidadeX = 0.0f;
	velocidadeY = 0.0f;
	alturaPulo = 160.0f;
	podePular = true;
	this->x = x;
	this->y = y;
	forma.setPosition(sf::Vector2f(x, y));
	CarregaTextura("Texturas/jogador.png");
}

Jogador::~Jogador()
{

}

void Jogador::mover(float dT)
{
	velocidadeX = 0.0f;

	if (colidiu_cima)
		velocidadeY = 0.f;

	if (!colidiu_baixo)
		velocidadeY += 981.0f * dT;
	else
	{
		podePular = true;
		velocidadeY = 0.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!colidiu_direita)
			velocidadeX += velocidadeEscalar;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (!colidiu_esquerda)
			velocidadeX -= velocidadeEscalar;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && podePular && colidiu_baixo)
	{
		podePular = false;
		velocidadeY = -sqrt(2.0f * 981.0f * alturaPulo);
	}

	float dx = velocidadeX * dT;
	float dy = velocidadeY * dT;
	x += dx;
	y += dy;

	forma.move(dx, dy);
	
}

void Jogador::zera_colidiu()
{
	colidiu_baixo = colidiu_cima = colidiu_direita = colidiu_esquerda = false;
}

void Jogador::setColidiuCima(bool colidiu)
{
	colidiu_cima = colidiu;
}

void Jogador::setColidiuBaixo(bool colidiu)
{
	colidiu_baixo = colidiu;
}

void Jogador::setColidiuDireita(bool colidiu)
{
	colidiu_direita = colidiu;
}

void Jogador::setColidiuEsquerda(bool colidiu)
{
	colidiu_esquerda = colidiu;
}


bool Jogador::getColidiuCima() const
{
	return colidiu_cima;
}

bool Jogador::getColidiuBaixo() const
{
	return colidiu_baixo;
}

bool Jogador::getColidiuDireita() const
{
	return colidiu_direita;
}

bool Jogador::getColidiuEsquerda() const
{
	return colidiu_esquerda;
}

