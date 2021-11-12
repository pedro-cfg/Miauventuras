#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(Lista<Entidade>* pL)
{
	pLista = pL;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes()
{

}

void Gerenciador_Colisoes::Checa_Colisao(Jogador* pJ)
{
	pJ->zera_colidiu();
	list<Inimigo*>::const_iterator iteInim = LIs.begin();
	list<Obstaculo*>::const_iterator iteObs = LOs.begin();
	while (iteInim != LIs.end())
	{
		Entidade* pAux = static_cast<Entidade*> (*iteInim);
		iteInim++;
		if(pAux != NULL)
			Checa_Colisao_Individual(pJ, pAux);
	}
	while (iteObs != LOs.end())
	{
		Entidade* pAux = static_cast<Entidade*> (*iteObs);
		iteObs++;
		Checa_Colisao_Individual(pJ, pAux);
	}
}

void Gerenciador_Colisoes::Checa_Colisao_Individual(Jogador* pJ, Entidade* outro)
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
			if (deltaX > 0.f) {
				pJ->setColidiuEsquerda(true);
			}
			else
				pJ->setColidiuDireita(true);
		}
		else
		{
			if (deltaY > 0.f)
				pJ->setColidiuCima(true);
			else
				pJ->setColidiuBaixo(true);
		}
		if (outro->getTipo() == "Inimigo") {
			Inimigo* pI = static_cast<Inimigo*>(outro);
			Executa_Colisao(pJ, pI);
		}
		else if (outro->getTipo() == "Obstaculo") {
			Obstaculo* pO = static_cast<Obstaculo*>(outro);
			Executa_Colisao(pJ, pO);
		}
	}
}

void Gerenciador_Colisoes::Executa_Colisao(Jogador* pJ, Inimigo* inimigo)
{
	if (pJ->getColidiuDireita()) {
		pJ->operator--();
		pJ->setColidiuDireita(false);
		for (int i = 0; i < 150; i++) {
			pJ->Movimentar(-1.f, 0.f);
			pJ->setX(pJ->getX() - 1.f);
			if (pJ->getX() > -143.f) {
				pJ->getMarcador()->Movimentar(-1.f, 0.f);
				pJ->getMarcador()->setX(pJ->getMarcador()->getX() - 1.f);
			}
		}
	}
	else if (pJ->getColidiuEsquerda()) {
		pJ->operator--();
		pJ->setColidiuEsquerda(false);
		for (int i = 0; i < 150; i++) {
			pJ->Movimentar(1.f, 0.f);
			pJ->setX(pJ->getX() + 1.f);
			pJ->getMarcador()->Movimentar(1.f, 0.f);
			pJ->getMarcador()->setX(pJ->getMarcador()->getX() + 1.f);
		}
	}
	else if (pJ->getColidiuBaixo()) {
		inimigo->operator--();
		for (int i = 0; i < 150; i++) {
			pJ->Movimentar(0.f, -1.f);
			pJ->setY(pJ->getY() - 1.f);
		}
		if (inimigo->getVidas() == 0) {
			ExcluirInimigo(inimigo);
		}
	}
	switch (pJ->getVidas())
	{
	case 1:
		pJ->getMarcador()->CarregaTextura("Texturas/Numeros/numero1.png");
		break;
	case 2:
		pJ->getMarcador()->CarregaTextura("Texturas/Numeros/numero2.png");
		break;
	case 3:
		pJ->getMarcador()->CarregaTextura("Texturas/Numeros/numero3.png");
		break;
	}
}

void Gerenciador_Colisoes::Executa_Colisao(Jogador* pJ, Obstaculo* obstaculo)
{
}

void Gerenciador_Colisoes::InserirInimigo(Inimigo* pI)
{
	LIs.push_back(pI);
}

void Gerenciador_Colisoes::InserirObstaculo(Obstaculo* pO)
{
	LOs.push_back(pO);
}

void Gerenciador_Colisoes::ExcluirInimigo(Inimigo* pI)
{
	LIs.remove(pI);
	pLista->Retirar(pI);
}

void Gerenciador_Colisoes::ExcluirObstaculo(Obstaculo* pO)
{
}
