#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include "Personagem.h"

class Inimigo: public Personagem
{
protected:
	float Xinicial;
	float amplitude;
	int valor;
public:
	Inimigo();
	~Inimigo();

	void setTipo();

	int getValor() const;

	void Executar(float dT);
	void mover(float dT);
};

#endif