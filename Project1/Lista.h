#ifndef _LISTA_H_
#define _LISTA_H_

#include "stdafx.h"

/*Lista template*/
template <class TL >
class Lista
{
private:
	template <class TE >
	class Elemento
	{
	private:
		Elemento<TE>* pProx;
		TE* pInfo;
	public:
		Elemento(TE* pInfo)
		{
			this->pInfo = pInfo;
			pProx = nullptr;
		}
		~Elemento()
		{
			if (pInfo != NULL)
			{
				delete pInfo;
			}
		}
		TE* getInfo()
		{
			return pInfo;
		}
		void setProx(Elemento<TE>* el)
		{
			pProx = el;
		}
		Elemento<TE>* getProx()
		{
			return pProx;
		}
	};

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

	void Limpar()
	{
		Elemento<TL>* paux;
		while (pPrimeiro != NULL)
		{
			paux = pPrimeiro->getProx();
			delete pPrimeiro;
			pPrimeiro = paux;
		}
		pUltimo = NULL;
		tam = 0;
	}

	int Quantidade()
	{
		return tam;
	}
};

#endif