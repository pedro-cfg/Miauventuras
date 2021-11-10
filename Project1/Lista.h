#ifndef _LISTA_H_
#define _LISTA_H_

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
        pPrimeiro = pUltimo = nullptr;
        tam = 0;
    }
    ~Lista() 
	{
        Elemento<TL>* paux;
        while (pPrimeiro != nullptr)
		{
            paux = pPrimeiro->getProx();
            delete pPrimeiro;
            pPrimeiro = paux;
        }
    }
	void inserir(TL pitem) 
	{
		Elemento<TL>* pnovo = new Elemento<TL>(pitem);
		if (pPrimeiro == nullptr)
			pPrimeiro = pUltimo = pnovo;
		else 
		{
			pUltimo->setProx(pnovo);
			pUltimo = pUltimo->getProx();
		}
		tam++;
	}
	TL buscar(const int ppos) 
	{
		Elemento<TL>* paux = pPrimeiro;
		if (ppos >= 0 && ppos < tam) 
		{
			for (int i = 0; i < ppos; i++)
				paux = paux->getProx();
			return paux->getInfo();
		}
		else
			return nullptr;
	}
	int quantidade() {
		return tam;
	}
};

#endif