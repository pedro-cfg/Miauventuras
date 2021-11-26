#include "stdafx.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include "Gerenciador_Colisoes.h"

Projetil::Projetil()
{
	CarregaTextura(PROJETIL);
	velocidadeEscalar = 700.f;
	contador_tempo = 0.f;
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

	contador_tempo = 0.f;
}

Projetil::~Projetil() 
{
}
void Projetil::Executar(float dT)
{
	mover(dT);
	if (contador_tempo > 3.f) 
	{
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

void Projetil::Carregar(fstream& arquivo)
{
	arquivo.read((char*)&x, sizeof(x));
	arquivo.read((char*)&y, sizeof(y));
	arquivo.read((char*)&velocidadeX, sizeof(velocidadeX));
	arquivo.read((char*)&velocidadeY, sizeof(velocidadeY));

	Reposicionar(x, y);
}

void Projetil::Gravar()
{
	fstream arquivo;
	arquivo.open("Persistencia/Projeteis.bin", ios::binary | ios::out | ios::app);

	GravarInfo(arquivo);

	arquivo.close();
}

void Projetil::GravarInfo(fstream& arquivo)
{
	arquivo.write((char*)&x, sizeof(x));
	arquivo.write((char*)&y, sizeof(y));
	arquivo.write((char*)&velocidadeX, sizeof(velocidadeX));
	arquivo.write((char*)&velocidadeY, sizeof(velocidadeY));
}

void Projetil::mover(float dT)
{
	velocidadeY += 981.0f * dT;

	Atualiza_Contador(dT);

	float dx = velocidadeX * dT;
	float dy = velocidadeY * dT;

	Deslocar(dx, dy);
}