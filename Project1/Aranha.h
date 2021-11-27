#ifndef _ARANHA_H_
#define _ARANHA_H_

#include "Inimigo.h"

class Projetil;

class Aranha: public Inimigo 
{
private:
	static int cont;
	Projetil* pProj;
public:
	Aranha();
	Aranha(float x, float y);
	~Aranha();

	static int getQuantidade();

	void Executar(float dT);
	void lancaProjetil();

	void Gravar();
	void GravarInfo(fstream& arquivo);
	void Carregar(fstream& arquivo);
};

#endif