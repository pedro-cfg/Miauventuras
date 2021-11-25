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
