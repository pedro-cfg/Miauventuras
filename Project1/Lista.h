#ifndef _LISTA_H_
#define _LISTA_H_

#include "Elemento.h"

template <class TL >
class Lista {
private: 
    int tam;
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;
public:
    Lista() {
        pPrimeiro = pUltimo = NULL;
        tam = 0;
    }
    ~Lista() {
        Elemento<TL>* paux;
        while (pPrimeiro != NULL) {
            paux = pPrimeiro->getProx();
            delete pPrimeiro;
            pPrimeiro = paux;
        }
    }
	void inserir(TL* pitem) {
		Elemento<TL>* pnovo = new Elemento<TL>(pitem);
		if (pPrimeiro == NULL)
			pPrimeiro = pUltimo = pnovo;
		else {
			pUltimo->setProx(pnovo);
			pUltimo = pUltimo->getProx();
		}
		tam++;
	}
	TL* buscar(const int ppos) {
		Elemento<TL>* paux = pPrimeiro;
		if (ppos >= 0 && ppos < tam) {
			for (int i = 0; i < ppos; i++)
				paux = paux->getProx();
			return paux->getValor();
		}
		else
			return NULL;
	}
	int quantidade() {
		return tam;
	}
};

#endif