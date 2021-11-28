#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include "Personagem.h"

class Obstaculo;

class Inimigo: public Personagem
{
protected:
	float Xinicial;
	float amplitude;
	float tempo;
	int valor;
	float direcao;
	bool ehChefao;
public:
	Inimigo();
	virtual~Inimigo();

	int getValor() const;
	const bool getEhChefao() const;

	virtual void Executar(float dT);
	virtual void mover(float dT);

	float getDirecao() const;
	float getVelX() const;

	virtual void reseta_velocidade();
	virtual void diminui_cont() = 0;
	
	void InimigoEmPlataforma(Obstaculo* pO);

	const float getXinicial() const;

	virtual void GravarInfo(fstream& arquivo);
	virtual void Carregar(fstream& arquivo);
};

#endif