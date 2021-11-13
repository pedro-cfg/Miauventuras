#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
}

void ListaEntidades::Inserir(Entidade* pE)
{
	LEs.Inserir(pE);
}

void ListaEntidades::Retirar(Entidade* pE)
{
	LEs.Retirar(pE);
}

void ListaEntidades::Executar(float dT)
{
	for (int i = 0; i < LEs.Quantidade(); i++)
	{
		Entidade* pE = LEs.Buscar(i);

		if (pE != NULL)
		{
			pE->Executar(dT);
		}
	}
}

void ListaEntidades::Desenha()
{
	for (int i = 0; i < LEs.Quantidade(); i++)
	{
		Entidade* pE = LEs.Buscar(i);

		if (pE != NULL)
		{
			pE->desenhar();
		}
	}
}
