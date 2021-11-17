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

	reseta_velocidade();

	alturaPulo = 350.0f;
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
	if (getVidas() <= 0) {
		pLista->~ListaEntidades();
		pGC->~Gerenciador_Colisoes();
	}
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

void Jogador::reseta_velocidade()
{
	velocidadeEscalar = 400.0f;
}

void Jogador::setEmpurrado(bool emp)
{
	empurrado = emp;
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
