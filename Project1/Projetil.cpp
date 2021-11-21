#include "stdafx.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Projetil::Projetil()
{
	CarregaTextura(PROJETIL);
	velocidadeEscalar = 700.f;
	contador_tempo = 0.f;
	setTipo();
}

Projetil::Projetil(Aranha* pAr) :
	Entidade() 
{
	x = pAr->getX();
	y = pAr->getY();
	CarregaTextura(PROJETIL);
	forma.setPosition(sf::Vector2f(x, y));

	velocidadeEscalar = 700.f;
	velocidadeX = velocidadeEscalar * pAr->getDirecao();
	velocidadeY = -velocidadeEscalar;

	setTipo();
	contador_tempo = 0.f;
}

Projetil::~Projetil() 
{

}
void Projetil::Executar(float dT)
{
	mover(dT);
	if (contador_tempo > 3.f) {
		pGC->Excluir(this);
		Atualiza_Contador(0.f, true);
	}
}

const float Projetil::getVelX() const
{
	return velocidadeX;
}

const float Projetil::getVelY() const
{
	return velocidadeY;
}

void Projetil::setTipo()
{
	tipo = "Projetil";
}

void Projetil::Recuperar(float cX, float cY, float XI, int numVidas, float velX, float velY)
{
	Reposicionar(cX, cY);

	velocidadeX = velX;
	velocidadeY = velY;

	pLista->Inserir(this);
	pGC->Inserir(this);
}

void Projetil::mover(float dT)
{
	velocidadeY += 981.0f * dT;

	Atualiza_Contador(dT);

	float dx = velocidadeX * dT;
	float dy = velocidadeY * dT;

	Deslocar(dx, dy);
}

