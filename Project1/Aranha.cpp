#include "Aranha.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Aranha::Aranha(float x, float y):
	Inimigo()
{
	CarregaTextura("Texturas/aranha.png");
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;

	Xinicial = x;

	valor = 1;

}

Aranha::~Aranha() 
{

}

void Aranha::Executar(float dT)
{
	mover(dT);
	Atualiza_Contador(dT);
	if (contador_tempo > 3.0f)
	{
		lancaProjetil();
		Atualiza_Contador(dT, true);
	}
}

void Aranha::lancaProjetil()
{
	Projetil* pNovo = new Projetil(this);
	
	if (pNovo)
	{
		pLista->Inserir(pNovo);
		pGC->Inserir(pNovo);
	}
}