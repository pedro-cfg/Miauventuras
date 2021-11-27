#include "stdafx.h"
#include "Obstaculo.h"

Obstaculo::Obstaculo() :
	Entidade(),
	EhPlataforma(false)
{
}

Obstaculo::~Obstaculo() 
{
}

const bool Obstaculo::getEhPlataforma() const
{
	return EhPlataforma;
}

void Obstaculo::GravarInfo(fstream& arquivo)
{
	arquivo.write((char*)&x, sizeof(x));
	arquivo.write((char*)&y, sizeof(y));
}

void Obstaculo::Carregar(fstream& arquivo)
{
	arquivo.read((char*)&x, sizeof(x));
	arquivo.read((char*)&y, sizeof(y));

	Reposicionar(x, y);
}
