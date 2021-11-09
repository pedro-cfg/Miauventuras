#include "stdafx.h"
#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(Entidade* jog)
{
	jogador = jog;
	colidiu_baixo = colidiu_cima = colidiu_direita = colidiu_esquerda = false;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {

}

void Gerenciador_Colisoes::Checa_Colisao()
{
	colidiu_baixo = colidiu_cima = colidiu_direita = colidiu_esquerda = false;
	list<Inimigo*>::const_iterator iteInim = LIs.begin();
	list<Obstaculo*>::const_iterator iteObs = LOs.begin();
	while (iteInim != LIs.end()) {
		Checa_Colisao_Individual(*iteInim);
		iteInim++;
	}
	while (iteObs != LOs.end()) {
		Checa_Colisao_Individual(*iteObs);
		iteObs++;
	}
}

void Gerenciador_Colisoes::Checa_Colisao_Individual(Entidade* segundo)
{
	sf::Vector2f posicao = jogador->getForma().getPosition();
	sf::Vector2f meio_tamanho = jogador->getForma().getSize() / 2.f;
	sf::Vector2f posicao_outro = segundo->getForma().getPosition();
	sf::Vector2f meio_tamanho_outro = segundo->getForma().getSize() / 2.f;

	float deltaX = posicao.x - posicao_outro.x;
	float deltaY = posicao.y - posicao_outro.y;
	float intersecaoX = abs(deltaX) - (meio_tamanho.x + meio_tamanho_outro.x);
	float intersecaoY = abs(deltaY) - (meio_tamanho.y + meio_tamanho_outro.y);

	if (intersecaoX < 0.f && intersecaoY < 0.f) {
		if (abs(intersecaoX) < abs(intersecaoY)) {
			if (deltaX > 0.f)
				colidiu_esquerda = true;
			else
				colidiu_direita = true;
		}
		else {
			if (deltaY > 0.f)
				colidiu_cima = true;
			else
				colidiu_baixo = true;
		}
	}
}

bool Gerenciador_Colisoes::getColidiuCima() const {
	return colidiu_cima;
}

bool Gerenciador_Colisoes::getColidiuBaixo() const {
	return colidiu_baixo;
}

bool Gerenciador_Colisoes::getColidiuDireita() const {
	return colidiu_direita;
}

bool Gerenciador_Colisoes::getColidiuEsquerda() const {
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
