#include "Jogador.h"
#include "Gerenciador_Colisoes.h"

Jogador::Jogador(float x, float y):
    Personagem()
{
    velocidadeEscalar = 400.0f;
    velocidadeX = 0.0f;
    velocidadeY = 0.0f;
    alturaPulo = 150.0f;
    podePular = true;
	this->x = x;

	this->y = y;
	forma.setPosition(sf::Vector2f((float)x, (float)y));
	CarregaTextura("Texturas/jogadortmp.png");
}

Jogador::~Jogador() 
{

}

void Jogador::mover(float dT)
{
    velocidadeX = 0.0f;

    if (gerenciador->getColidiuCima())
        velocidadeY = 0.f;

    if (!gerenciador->getColidiuBaixo())
        velocidadeY += 981.0f * dT;
    else
    {
        podePular = true;
        velocidadeY = 0.0f;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (!gerenciador->getColidiuDireita())
            velocidadeX += velocidadeEscalar;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (!gerenciador->getColidiuEsquerda())
            velocidadeX -= velocidadeEscalar;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && podePular && gerenciador->getColidiuBaixo())
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