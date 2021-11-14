#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include "Personagem.h"

class Inimigo: public Personagem
{
protected:
	float Xinicial;
	float amplitude;
	int valor;
	float direcao;
public:
	Inimigo();
	~Inimigo();

	void setTipo();

	int getValor() const;

	virtual void Executar(float dT);
	void mover(float dT);

	float getDirecao() const;
};

#endif