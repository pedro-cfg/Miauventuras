#include "Gerenciador_Colisoes.h"
#include "FasePrimeira.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(ListaEntidades* pL)
{
	pLista = pL;
	pF1 = NULL;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{
}

void Gerenciador_Colisoes::Fim_de_Fase(Jogador* pJ)
{
	if (  pJ->getVidas() <= 0 || pJ->getX() >= 9915.f) {
		pLista->Limpar(1);
		LimpaListas();
		Ente::setExecutando(0);
		pJ->reseta_jogador();
		pF1->Gerar_Objetos();
	}
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
			Checa_Colisao_Individual(static_cast<Personagem*>(pJ), pAux, colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
		}
		if (colidiuCima || colidiuEsquerda || colidiuDireita)
		{
			pJ->setEmpurrado(true);
			if (pJ->getContador() > 1.f) {
				pJ->sofreDano();
			}
			pJ->Atualiza_Contador(0.f, true);
			if (colidiuEsquerda || colidiuCima) {
				pJ->setVelocidadeX(500.f);
			}
			if (colidiuDireita) {
				pJ->setVelocidadeX(-500.f);
			}
			pJ->setVelocidadeY(-500.f);
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
				pObs->ExecutaImpedimento(static_cast<Personagem*>(pJ), colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
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
			Checa_Colisao_Individual(static_cast<Personagem*>(pJ), pAux, colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
		}

		if (colidiuEsquerda || colidiuBaixo || colidiuCima || colidiuDireita)
		{
			pJ->sofreDano();
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
					pI->InimigoEmPlataforma(static_cast<Plataforma*>(pObs));

				if (colidiuEsquerda || colidiuBaixo || colidiuCima || colidiuDireita)
				{
					pObs->ExecutaImpedimento(static_cast<Personagem*>(pI), colidiuEsquerda, colidiuDireita, colidiuCima, colidiuBaixo);
				}
			}
		}
	}
}

void Gerenciador_Colisoes::Checa_Colisao_Individual(Personagem* pP, Entidade* outro, bool& esq, bool& dir, bool& cima, bool& baixo)
{
	float posicaoX = pP->getX();
	float posicaoY = pP->getY();

	float meio_tamanhoX = pP->getLargura() / 2.0f;
	float meio_tamanhoY = pP->getAltura() / 2.0f;

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

void Gerenciador_Colisoes::setPrimeiraFase(FasePrimeira* pF)
{
	pF1 = pF;
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

void Gerenciador_Colisoes::Excluir(Jogador* pJ)
{
	pLista->Retirar(static_cast<Entidade*>(pJ));
}
