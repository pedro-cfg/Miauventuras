#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador* jog)
{
	jogador = jog;
	colidiu_baixo = colidiu_cima = colidiu_direita = colidiu_esquerda = false;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() 
{

}

void Gerenciador_Colisoes::Checa_Colisao()
{
	colidiu_baixo = colidiu_cima = colidiu_direita = colidiu_esquerda = false;
	list<Inimigo*>::const_iterator iteInim = LIs.begin();
	list<Obstaculo*>::const_iterator iteObs = LOs.begin();
	while (iteInim != LIs.end()) 
	{
		Entidade* pAux = static_cast<Entidade*> (*iteInim);
		Checa_Colisao_Individual(pAux);
		iteInim++;
	}
	while (iteObs != LOs.end()) 
	{
		Entidade* pAux = static_cast<Entidade*> (*iteObs);
		Checa_Colisao_Individual(pAux);
		iteObs++;
	}
}

void Gerenciador_Colisoes::Checa_Colisao_Individual(Entidade* segundo)
{
	float posicaoX = (float)jogador->getX();
	float posicaoY = (float)jogador->getY();

	float meio_tamanhoX = jogador->getLargura() / 2.0f;
	float meio_tamanhoY = jogador->getAltura() / 2.0f;

	float posicao_outroX = (float)segundo->getX();
	float posicao_outroY = (float)segundo->getY();

	float meio_tamanho_outroX = jogador->getLargura() / 2.0f;
	float meio_tamanho_outroY = jogador->getAltura() / 2.0f;

	float deltaX = posicaoX - posicao_outroX;
	float deltaY = posicaoY - posicao_outroY;
	float intersecaoX = abs(deltaX) - (meio_tamanhoX + meio_tamanho_outroX);
	float intersecaoY = abs(deltaY) - (meio_tamanhoY + meio_tamanho_outroY);

	if (intersecaoX < 0.f && intersecaoY < 0.f) 
	{
		if (abs(intersecaoX) < abs(intersecaoY)) 
		{
			if (deltaX > 0.f)
				colidiu_esquerda = true;
			else
				colidiu_direita = true;
		}
		else 
		{
			if (deltaY > 0.f)
				colidiu_cima = true;
			else
				colidiu_baixo = true;
		}
	}
}

bool Gerenciador_Colisoes::getColidiuCima() const 
{
	return colidiu_cima;
}

bool Gerenciador_Colisoes::getColidiuBaixo() const 
{
	return colidiu_baixo;
}

bool Gerenciador_Colisoes::getColidiuDireita() const 
{
	return colidiu_direita;
}

bool Gerenciador_Colisoes::getColidiuEsquerda() const 
{
	return colidiu_esquerda;
}

void Gerenciador_Colisoes::InserirInimigo(Inimigo* pI)
{
	LIs.push_back(pI);
}

void Gerenciador_Colisoes::InserirObstaculo(Obstaculo* pO)
{
	LOs.push_back(pO);
}
