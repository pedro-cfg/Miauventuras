#include "Jogador.h"
#include "Gerenciador_Colisoes.h"

Jogador::Jogador(float x, float y) :
	Personagem()
{
	pontos = 0;
	//vidas = 3;

	CarregaTextura("Texturas/jogador.png");
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;

	reseta_colidiu();
	reseta_velocidade();

	velocidadeX = 0.0f;
	velocidadeY = 0.0f;
	alturaPulo = 260.0f;
	podePular = true;
	empurrado = false;

}

Jogador::~Jogador()
{

}

void Jogador::Executar(float dT)
{
	mover(dT);
	Atualiza_Contador(dT);
}

void Jogador::mover(float dT)
{
	if(!empurrado)
		velocidadeX = 0.0f;

	if (colidiu_cima)
	{
		velocidadeY = 0.0f;
	}

	if (!colidiu_baixo && abs(y) >= getAltura()/2.f)
	{
		velocidadeY += 981.0f * dT;
	}
	else if(!empurrado)
	{
		podePular = true;
		velocidadeY = 0.0f;
	}

	if (abs(y) <= getAltura() / 2.f)
		empurrado = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!colidiu_direita && !empurrado)
			velocidadeX += velocidadeEscalar;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (!colidiu_esquerda && !empurrado)
			velocidadeX -= velocidadeEscalar;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && podePular && !empurrado)
	{
		podePular = false;
		velocidadeY = -sqrt(2.0f * 981.0f * alturaPulo);
	}

	float dx = velocidadeX * dT;
	float dy = velocidadeY * dT;

	Deslocar(dx, dy);
}

void Jogador::reseta_colidiu()
{
	colidiu_baixo = colidiu_cima = colidiu_direita = colidiu_esquerda = false;
}

void Jogador::reseta_velocidade()
{
	velocidadeEscalar = 400.0f;
}

void Jogador::setVelocidadeY(float v)
{
	velocidadeY = v;
}

void Jogador::setVelocidadeX(float v)
{
	velocidadeX = v;
}

void Jogador::setEmpurrado(bool emp)
{
	empurrado = emp;
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

void Jogador::Pontua(Inimigo* pI)
{
	int valorInimigo = pI->getValor();
	for (int i = 0; i < valorInimigo; i++)
	{
		this->operator++();
	}
	/*Temporário!!!!!*/
	cout << pontos << endl;
}

void Jogador::operator++()
{
	pontos++;
}
/*
void Jogador::Atualiza_Contador(float dT, bool zera)
{
	if (zera)
		contador_tempo = 0.f;
	else 
		contador_tempo += dT;
}

float Jogador::getContador()
{
	return contador_tempo;
}
*/
