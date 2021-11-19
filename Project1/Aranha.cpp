#include "Aranha.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Aranha::Aranha():Inimigo()
{
	CarregaTextura(ARANHA);
	setTipo();
	valor = 1;
}

Aranha::Aranha(float x, float y):
	Inimigo()
{
	CarregaTextura(ARANHA);
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;

	Xinicial = x;

	valor = 1;
	setTipo();
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

void Aranha::setTipo()
{
	tipo = "Aranha";
}

void Aranha::Recuperar(float cX, float cY, float XI, int numVidas)
{
	setVidas(numVidas);
	Reposicionar(cX, cY);
	
	Xinicial = XI; 

	pLista->Inserir(this);
	pGC->Inserir(this);
}

