#include "Aranha.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

int Aranha::cont = 0;
int Aranha::getQuantidade()
{
	return cont;
}

Aranha::Aranha() :
	Inimigo()
{
	cont++;
	pProj = NULL;
	CarregaTextura(ARANHA);
	valor = 1;
}

Aranha::Aranha(float x, float y) :
	Inimigo()
{
	cont++;
	pProj = NULL;
	CarregaTextura(ARANHA);
	forma.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;

	Xinicial = x;

	valor = 1;

}

Aranha::~Aranha()
{
	cont--;
}

void Aranha::Executar(float dT)
{
	mover(dT);
	Atualiza_Contador(dT);
	if (contador_tempo > 3.0f)
	{
		pGC->Excluir(pProj);
		lancaProjetil();
		Atualiza_Contador(dT, true);
	}
}

void Aranha::lancaProjetil()
{
	Projetil* pNovo = new Projetil(this);

	if (pNovo)
	{
		pProj = pNovo;
		pLista->Inserir(pProj);
		pGC->Inserir(pProj);
	}
}

void Aranha::Gravar()
{
	fstream arquivo;
	arquivo.open(ARANHAS_SAVE, ios::binary | ios::out | ios::app );

	GravarInfo(arquivo);

	arquivo.close();
}

void Aranha::GravarInfo(fstream& arquivo)
{
	arquivo.write((char*)&x, sizeof(x));
	arquivo.write((char*)&y, sizeof(y));
	arquivo.write((char*)&Xinicial, sizeof(Xinicial));
	arquivo.write((char*)&vidas, sizeof(vidas));
	arquivo.write((char*)&velocidadeEscalar, sizeof(velocidadeEscalar));
	arquivo.write((char*)&velocidadeX, sizeof(velocidadeX));
	arquivo.write((char*)&velocidadeY, sizeof(velocidadeY));
	pProj->GravarInfo(arquivo);
}

void Aranha::Carregar(fstream& arquivo)
{
	arquivo.read((char*)&x, sizeof(x));
	arquivo.read((char*)&y, sizeof(y));
	arquivo.read((char*)&Xinicial, sizeof(Xinicial));
	arquivo.read((char*)&vidas, sizeof(vidas));
	arquivo.read((char*)&velocidadeEscalar, sizeof(velocidadeEscalar));
	arquivo.read((char*)&velocidadeX, sizeof(velocidadeX));
	arquivo.read((char*)&velocidadeY, sizeof(velocidadeY));

	Projetil* pNovo = new Projetil();

	if (pNovo)
	{
		pProj = pNovo;
		pProj->Carregar(arquivo);
		pLista->Inserir(pProj);
		pGC->Inserir(pProj);
	}

	Reposicionar(x, y);
	direcao = (abs(velocidadeX) / velocidadeX);
}
