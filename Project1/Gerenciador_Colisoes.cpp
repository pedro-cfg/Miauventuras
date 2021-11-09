#include "stdafx.h"
#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(Personagem* jog)
{
	jogador = jog;
	colidiu_baixo = colidiu_cima = colidiu_direita = colidiu_esquerda = false;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {

}

void Gerenciador_Colisoes::Checa_Colisao(Personagem* segundo)
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

void Gerenciador_Colisoes::Reset_Checagem()
{
	colidiu_baixo = colidiu_cima = colidiu_direita = colidiu_esquerda = false;
}

bool Gerenciador_Colisoes::getColidiuCima() {
	return colidiu_cima;
}

bool Gerenciador_Colisoes::getColidiuBaixo() {
	return colidiu_baixo;
}

bool Gerenciador_Colisoes::getColidiuDireita() {
	return colidiu_direita;
}

bool Gerenciador_Colisoes::getColidiuEsquerda() {
	return colidiu_esquerda;
}
