#ifndef _PROJETIL_H_
#define _PROJETIL_H_

#include "Entidade.h"
#include "Aranha.h"
#include "Gerenciador_Colisoes.h"

class Projetil: public Entidade 
{
private:
	float velocidadeEscalar;
	float velocidadeX;
	float velocidadeY;

public:
	Projetil();
	Projetil(Aranha* pAr);
	~Projetil();

	void mover(float dT);
	void Executar(float dT);

	static void Excluir(Projetil* pP);

	void setTipo();

	void Recuperar(float cX, float cY, float XI = 0.f, int numVidas = 0);
};

#endif 