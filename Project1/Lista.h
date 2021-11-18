#ifndef _LISTA_H_
#define _LISTA_H_

#include "stdafx.h"
//#include "Elemento.h"

template <class TIPO >
class Lista
{
private:
	class Elemento
	{
	private:
		Elemento* pProx;
		TIPO* pInfo;
	public:
		Elemento(TIPO* pInfo)
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
		TIPO* getInfo()
		{
			return pInfo;
		}
		void setProx(Elemento* el)
		{
			pProx = el;
		}
		Elemento* getProx()
		{
			return pProx;
		}
	};

	int tam;
	Elemento* pPrimeiro;
	Elemento* pUltimo;
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
	void Inserir(TIPO* pitem)
	{
		Elemento* pnovo = new Elemento(pitem);
		if (pPrimeiro == NULL)
			pPrimeiro = pUltimo = pnovo;
		else
		{
			pUltimo->setProx(pnovo);
			pUltimo = pUltimo->getProx();
		}
		tam++;
	}

	TIPO* Buscar(const int ppos)
	{
		Elemento* paux = pPrimeiro;
		if (ppos >= 0 && ppos < tam)
		{
			for (int i = 0; i < ppos; i++)
				paux = paux->getProx();
			return paux->getInfo();
		}
		else
			return NULL;
	}

	void Retirar(TIPO* pitem)
	{
		Elemento* paux = pPrimeiro;
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
		Elemento* paux;
		while (pPrimeiro != NULL)
		{
			paux = pPrimeiro->getProx();
			delete pPrimeiro;
			pPrimeiro = paux;
		}
	}

	//void Limpar(int ind = 0)
	//{
	//	Elemento<TL>* paux1 = pPrimeiro;
	//	//Elemento<TL>* paux2 = NULL;

	//	for (int i = 1; i < ind; i++)
	//	{
	//		paux1 = paux1->getProx();
	//	}

	//	TL* pT = new TL;

	//	for (int i = ind; i < tam; i++) {
	//		pT = Buscar(i);
	//		Retirar(pT);
	//	}

	//	pUltimo = paux1;
	//	tam = ind;
	//	if (pUltimo != NULL)
	//		pUltimo->setProx(NULL);
	//	/*while (paux1 != NULL)
	//	{
	//		paux2 = paux1->getProx();
	//		delete paux1;
	//		paux1 = paux2;
	//		tam--;
	//	}*/
	//}

	int Quantidade()
	{
		return tam;
	}
};

#endif