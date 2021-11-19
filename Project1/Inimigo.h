#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include "Personagem.h"

class Obstaculo;

class Inimigo: public Personagem
{
protected:
	float Xinicial;
	float amplitude;
	int valor;
	float direcao;
	bool ehChefao;
public:
	Inimigo();
	~Inimigo();

	/*void setTipo();*/

	int getValor() const;
	bool getEhChefao() const;

	virtual void Executar(float dT);
	void mover(float dT);

	float getDirecao() const;

	virtual void reseta_velocidade();
	
	void InimigoEmPlataforma(Obstaculo* pO);

	const float getXinicial() const;
};

#endif