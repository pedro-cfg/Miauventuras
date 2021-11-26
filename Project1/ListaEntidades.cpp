#include "ListaEntidades.h"
#include "Entidade.h"

ListaEntidades::ListaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
	Limpar();
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

void ListaEntidades::Limpar()
{
	LEs.Limpar();
}

void ListaEntidades::Gravar(fstream& arquivo)
{
	Entidade* pE = NULL;
	int tam = LEs.Quantidade();

	arquivo.write((char*)&tam, sizeof(tam));

	for (int i = 0; i < tam; i++) {
		pE = LEs.Buscar(i);
		pE->Gravar_Individual(arquivo);
	}
}

//void ListaEntidades::Gravar_Individual(Entidade* pE, fstream& arquivo)
//{
//	float x, y, Xinicial = 0.f, velX = 0.f, velY = 0.f;
//	int vidas = 0;
//
//	x = pE->getX();
//	y = pE->getY();
//	string tipo = pE->getTipo();
//
//	int tamanho_tipo = tipo.size();
//	arquivo.write((char*)&tamanho_tipo, sizeof(tamanho_tipo));
//	arquivo.write((char*)&tipo[0], tamanho_tipo);
//
//	if (tipo == "Aranha" || tipo == "Lagartixa" || tipo == "Ratao") {
//		Inimigo* pI = static_cast<Inimigo*>(pE);
//		Xinicial = pI->getXinicial();
//		vidas = pI->getVidas();
//		velX = pI->getVelX();
//	}
//	else if (tipo == "Projetil") {
//		Projetil* pP = static_cast<Projetil*>(pE);
//		velX = pP->getVelX();
//		velY = pP->getVelY();
//	}
//
//	arquivo.write((char*)&x, sizeof(x));
//	arquivo.write((char*)&y, sizeof(y));
//	arquivo.write((char*)&Xinicial, sizeof(Xinicial));
//	arquivo.write((char*)&vidas, sizeof(vidas));
//	arquivo.write((char*)&velX, sizeof(velX));
//	arquivo.write((char*)&velY, sizeof(velY));
//}