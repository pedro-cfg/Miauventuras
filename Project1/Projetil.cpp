#include "stdafx.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Projetil::Projetil()
{
	CarregaTextura("Texturas/projetil.png");
	velocidadeEscalar = 700.f;
	contador_tempo = 0.f;
	setTipo();
}

Projetil::Projetil(Aranha* pAr) :
	Entidade() 
{
	x = pAr->getX();
	y = pAr->getY();
	CarregaTextura("Texturas/projetil.png");
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

void Projetil::setTipo()
{
	tipo = "Projetil";
}

void Projetil::Recuperar(float cX, float cY, float XI, int numVidas)
{
	Reposicionar(cX, cY);

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

