#ifndef _INIMIGO_H_
#define _INIMIGO_H_

#include "Personagem.h"
class Plataforma;

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

	virtual void reseta_velocidade();
	
	void InimigoEmPlataforma(Plataforma* pP);
};

#endif