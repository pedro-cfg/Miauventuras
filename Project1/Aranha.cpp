#include "Aranha.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Aranha::Aranha() :
	Inimigo()
{
	CarregaTextura(ARANHA);
	valor = 1;
}

Aranha::Aranha(float x, float y) :
	Inimigo()
{
	CarregaTextura(ARANHA);
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

void Aranha::Recuperar(float cX, float cY, float XI, int numVidas, float velX, float velY)
{
	setVidas(numVidas);
	Reposicionar(cX, cY);

	direcao = velX / abs(velX);
	Xinicial = XI;

	pLista->Inserir(this);
	pGC->Inserir(this);
}

void Aranha::Gravar_Individual(fstream& arquivo)
{
	string tipo = "Aranha";
	int tamanho_tipo = tipo.size();
	arquivo.write((char*)&tamanho_tipo, sizeof(tamanho_tipo));
	arquivo.write((char*)&tipo[0], tamanho_tipo);

	arquivo.write((char*)&x, sizeof(x));
	arquivo.write((char*)&y, sizeof(y));
	arquivo.write((char*)&Xinicial, sizeof(Xinicial));
	arquivo.write((char*)&vidas, sizeof(vidas));
	arquivo.write((char*)&velocidadeEscalar, sizeof(velocidadeEscalar));
	arquivo.write((char*)&velocidadeEscalar, sizeof(velocidadeEscalar));
}
