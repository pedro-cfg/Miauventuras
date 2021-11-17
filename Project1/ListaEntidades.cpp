#include "ListaEntidades.h"
#include "Entidade.h"

ListaEntidades::ListaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
	LEs.~Lista();
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

void ListaEntidades::Limpar(int ind)
{
	LEs.Limpar(ind);
}
