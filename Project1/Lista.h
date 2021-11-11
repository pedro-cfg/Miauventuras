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
        /*Elemento<TL>* paux;
        while (pPrimeiro != NULL)
		{
            paux = pPrimeiro->getProx();
            delete pPrimeiro;
            pPrimeiro = paux;
        }*/
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

	int Quantidade() {
		return tam;
	}
};

#endif