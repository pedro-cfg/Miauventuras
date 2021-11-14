#include "Gerenciador_Colisoes.h"
//#include "Entidade.h"

/*
Gerenciador_Colisoes::Gerenciador_Colisoes(ListaEntidades* pL, Gerenciador_Grafico* pG)
{
	pLista = pL;
	pGerenciador_Grafico = pG;
}*/

Gerenciador_Colisoes::Gerenciador_Colisoes(ListaEntidades* pL)
{
	pLista = pL;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{

}

void Gerenciador_Colisoes::Checa_Colisao(Jogador* pJ)
{
	pJ->reseta_colidiu();
	pJ->reseta_velocidade();

	iteInim = LIs.begin();
	iteObs = LOs.begin();
	iteProj = LPs.begin();

	bool colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo;

	while (iteInim != LIs.end())
	{
		colidiuEsquerda = colidiuDireita = colidiuCima = colidiuBaixo = false;

		Inimigo* pInim = (*iteInim);
		Entidade* pAux = static_cast<Entidade*> (pInim);
		iteInim++;

		if (pAux != NULL)
		{
			Checa_Colisao_Individual(pJ, pAux, colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
		}
		if (colidiuCima || colidiuEsquerda || colidiuDireita)
		{
			if (pJ->getContador() > 1.f) 
			{
				pJ->sofreDano();
			}
			pJ->Atualiza_Contador(0.f, true);
		}
		else if (colidiuBaixo)
		{
			pInim->sofreDano();
			if (pInim->getVidas() <= 0)
			{
				Excluir(pInim);
				pJ->Pontua(pInim);
			}
			pJ->setVelocidadeY(-500.f);
		}

	}

	while (iteObs != LOs.end())
	{
		colidiuEsquerda = colidiuDireita = colidiuCima = colidiuBaixo = false;

		Obstaculo* pObs = (*iteObs);
		Entidade* pAux = static_cast<Entidade*> (pObs);
		iteObs++;

		if (pAux != NULL)
		{
			Checa_Colisao_Individual(pJ, pAux, colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
		}

		if (colidiuEsquerda || colidiuBaixo || colidiuCima || colidiuDireita)
		{
			if (pObs->getEhPlataforma())
			{
				pObs->ExecutaImpedimento(pJ, colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
			}
			else
			{
				pObs->ExecutaImpedimento(pJ);
			}
		}
	}

	while (iteProj != LPs.end())
	{
		colidiuEsquerda = colidiuDireita = colidiuCima = colidiuBaixo = false;

		Projetil* pProj = (*iteProj);
		Entidade* pAux = static_cast<Entidade*> (pProj);
		iteProj++;

		if (pAux != NULL)
		{
			Checa_Colisao_Individual(pJ, pAux, colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
		}

		if (colidiuEsquerda || colidiuBaixo || colidiuCima || colidiuDireita)
		{
			pJ->sofreDano();
			Excluir(pProj);
		}
	}
}

void Gerenciador_Colisoes::Checa_Colisao_Individual(Jogador* pJ, Entidade* outro, bool& esq, bool& dir, bool& cima, bool& baixo)
{
	float posicaoX = pJ->getX();
	float posicaoY = pJ->getY();

	float meio_tamanhoX = pJ->getLargura() / 2.0f;
	float meio_tamanhoY = pJ->getAltura() / 2.0f;

	float posicao_outroX = outro->getX();
	float posicao_outroY = outro->getY();

	float meio_tamanho_outroX = outro->getLargura() / 2.0f;
	float meio_tamanho_outroY = outro->getAltura() / 2.0f;

	float deltaX = posicaoX - posicao_outroX;
	float deltaY = posicaoY - posicao_outroY;
	float intersecaoX = abs(deltaX) - (meio_tamanhoX + meio_tamanho_outroX);
	float intersecaoY = abs(deltaY) - (meio_tamanhoY + meio_tamanho_outroY);

	if (intersecaoX < 0.f && intersecaoY < 0.f && abs(abs(intersecaoX) - abs(intersecaoY))> 0.1f)
	{
		if (abs(intersecaoX) < abs(intersecaoY))
		{
			if (deltaX > 0.f)
			{
				esq = true;
			}
			else
			{
				dir = true;
			}
		}
		else
		{
			if (deltaY > -1 * meio_tamanhoY)
			{
				cima = true;
			}
			else
			{
				baixo = true;
			}
		}
	}
}

void Gerenciador_Colisoes::Inserir(Inimigo* pI)
{
	LIs.push_back(pI);
}

void Gerenciador_Colisoes::Inserir(Obstaculo* pO)
{
	LOs.push_back(pO);
}

void Gerenciador_Colisoes::Inserir(Projetil* pP)
{
	LPs.push_back(pP);
}

void Gerenciador_Colisoes::Excluir(Inimigo* pI)
{
	LIs.remove(pI);
	pLista->Retirar(static_cast<Entidade*>(pI));
}

void Gerenciador_Colisoes::Excluir(Projetil* pP)
 {
  	LPs.remove(pP);
	pLista->Retirar(static_cast<Entidade*>(pP));
}
