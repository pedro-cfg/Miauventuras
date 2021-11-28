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

	const float getVelX() const;
	const float getVelY() const;

	void Carregar(fstream& arquivo);
	void GravarInfo(fstream& arquivo);
};

#endif 