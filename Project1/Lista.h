#ifndef _LISTA_H_
#define _LISTA_H_

#include "stdafx.h"
#include "Elemento.h"

template <class TL >
class Lista 
{
private: 
    int tam;
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;
public:
    Lista() 
	{
        pPrimeiro = pUltimo = NULL;
        tam = 0;
    }
    ~Lista() 
	{
		Limpar();
		pPrimeiro = pUltimo = NULL;
		tam = 0;
    }
	void Inserir(TL* pitem) 
	{
		Elemento<TL>* pnovo = new Elemento<TL>(pitem);
		if (pPrimeiro == NULL)
			pPrimeiro = pUltimo = pnovo;
		else 
		{
			pUltimo->setProx(pnovo);
			pUltimo = pUltimo->getProx();
		}
		tam++;
	}

	TL* Buscar(const int ppos) 
	{
		Elemento<TL>* paux = pPrimeiro;
		if (ppos >= 0 && ppos < tam)
		{
			for (int i = 0; i < ppos; i++)
				paux = paux->getProx();
			return paux->getInfo();
		}
		else
			return NULL;
	}

	void Retirar(TL* pitem) 
	{
		Elemento<TL>* paux = pPrimeiro;
		if (pPrimeiro != NULL && pPrimeiro->getInfo() == pitem) 
		{
			pPrimeiro = pPrimeiro->getProx();
			delete paux;
			tam--;
		}
		else 
		{
			while (paux->getProx() != NULL) 
			{
				if (paux->getProx()->getInfo() == pitem) 
				{
					if (paux->getProx()->getProx() == NULL)
						pUltimo = paux;
					paux->setProx(paux->getProx()->getProx());
					tam--;
				}
				else 
				{
					paux = paux->getProx();
				}
			}
			paux = paux->getProx();
			delete paux;
		}
	}

	void Limpar(int ind = 0)
	{
		Elemento<TL>* paux1 = pPrimeiro;
		Elemento<TL>* paux2 = NULL;

		for (int i = 0; i < ind; i++)
		{
			paux1 = paux1->getProx();
		}

		while (paux1 != NULL)
		{
			paux2 = paux1->getProx();
			delete paux1;
			paux1 = paux2;
			tam--;
		}
	}

	int Quantidade() 
	{
		return tam;
	}
};

#endif