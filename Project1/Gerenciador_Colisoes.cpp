#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(ListaEntidades* pL)
{
	pLista = pL;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
	LimpaListas();
	pLista = NULL;
}


void Gerenciador_Colisoes::LimpaListas()
{
	LIs.clear();
	LOs.clear();
	LPs.clear();
}

void Gerenciador_Colisoes::Checa_Colisao(Jogador* pJ)
{
	pJ->reseta_colidiu();
	pJ->reseta_velocidade();

	Colisao_Com_Inimigos(pJ);
	Colisao_Com_Obstaculos(pJ);
	Colisao_Com_Projeteis(pJ);
}

void Gerenciador_Colisoes::Colisao_Com_Inimigos(Jogador* pJ)
{
	iteInim = LIs.begin();

	bool colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo;

	/*Colis?o com inimigos*/
	while (iteInim != LIs.end())
	{
		colidiuEsquerda = colidiuDireita = colidiuCima = colidiuBaixo = false;

		Inimigo* pInim = (*iteInim);
		Entidade* pAux = static_cast<Entidade*> (pInim);
		iteInim++;

		if (pAux != NULL)
		{
			Checa_Colisao_Individual(static_cast<Personagem*>(pJ), pAux, colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
		}
		if (colidiuCima || colidiuEsquerda || colidiuDireita)
		{
			pJ->setEmpurrado(true);
			if (pJ->getContador() > 1.f)
			{
				pJ->operator--();
			}
			pJ->Atualiza_Contador(0.f, true);
			if (colidiuEsquerda || colidiuCima)
			{
				if (!pInim->getEhChefao())
					pJ->setVelocidadeX(500.f);
				else
					pJ->setVelocidadeX(800.f);
			}
			if (colidiuDireita)
			{
				if (!pInim->getEhChefao())
					pJ->setVelocidadeX(-500.f);
				else
					pJ->setVelocidadeX(-800.f);
			}
			if (!pInim->getEhChefao())
				pJ->setVelocidadeY(-500.f);
			else
				pJ->setVelocidadeY(-800.f);
		}
		else if (colidiuBaixo)
		{
			pInim->operator--();
			if (pInim->Morreu())
			{
				pJ->operator+=(pInim);
				if (pInim->getEhChefao())
				{
					pJ->setVenceu(true);
				}
				Excluir(pInim);
			}
			if (!pInim->getEhChefao())
				pJ->setVelocidadeY(-500.f);
			else {
				pJ->setVelocidadeY(-800.f);
				pJ->setVelocidadeX(-600.f);
			}
		}

	}
}

void Gerenciador_Colisoes::Colisao_Com_Obstaculos(Jogador* pJ)
{
	iteObs = LOs.begin();

	bool colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo;

	/*Colis?o com obst?culos*/
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
				pObs->ExecutaImpedimento(static_cast<Personagem*>(pJ), colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
			}
			else
			{
				pObs->ExecutaImpedimento(pJ);
			}
		}
	}
}

void Gerenciador_Colisoes::Colisao_Com_Projeteis(Jogador* pJ)
{
	iteProj = LPs.begin();

	bool colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo;

	/*Colis?o com proj?teis*/
	while (iteProj != LPs.end())
	{
		colidiuEsquerda = colidiuDireita = colidiuCima = colidiuBaixo = false;

		Projetil* pProj = (*iteProj);
		Entidade* pAux = static_cast<Entidade*> (pProj);
		iteProj++;

		if (pAux != NULL)
		{
			Checa_Colisao_Individual(static_cast<Personagem*>(pJ), pAux, colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
		}

		if (colidiuEsquerda || colidiuBaixo || colidiuCima || colidiuDireita)
		{
			pJ->operator--();
			Excluir(pProj);
		}
	}
}

void Gerenciador_Colisoes::Checa_Colisao_Inimigos()
{
	iteInim = LIs.begin();
	while (iteInim != LIs.end())
	{
		Inimigo* pI = (*iteInim);
		iteInim++;

		pI->reseta_colidiu();
		pI->reseta_velocidade();

		iteObs = LOs.begin();
		bool colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo;

		while (iteObs != LOs.end())
		{
			colidiuEsquerda = colidiuDireita = colidiuCima = colidiuBaixo = false;

			Obstaculo* pObs = (*iteObs);
			Entidade* pAux = static_cast<Entidade*> (pObs);
			iteObs++;

			if (pObs->getEhPlataforma())
			{
				if (pAux != NULL)
				{
					Checa_Colisao_Individual(static_cast<Personagem*>(pI), pAux, colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
				}

				if (colidiuBaixo)
				{
					pI->InimigoEmPlataforma(pObs);
				}

				if (colidiuEsquerda || colidiuBaixo || colidiuCima || colidiuDireita)
				{
					pObs->ExecutaImpedimento(static_cast<Personagem*>(pI), colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
				}
			}
		}
	}
}

void Gerenciador_Colisoes::Checa_Colisao_Individual(Personagem* pP, Entidade* pOutro, bool& esq, bool& dir, bool& cima, bool& baixo)
{
	float posicaoX = pP->getX();
	float posicaoY = pP->getY();

	float meio_tamanhoX = pP->getLargura() / 2.0f;
	float meio_tamanhoY = pP->getAltura() / 2.0f;

	float posicao_outroX = pOutro->getX();
	float posicao_outroY = pOutro->getY();

	float meio_tamanho_outroX = pOutro->getLargura() / 2.0f;
	float meio_tamanho_outroY = pOutro->getAltura() / 2.0f;

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
			if (deltaY > 0.f)
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
	pI->diminui_cont();
	LIs.remove(pI);
	pLista->Retirar(static_cast<Entidade*>(pI));
}

void Gerenciador_Colisoes::Excluir(Projetil* pP)
{
	LPs.remove(pP);
	pLista->Retirar(static_cast<Entidade*>(pP));
}