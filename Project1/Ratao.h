#ifndef _RATAO_H_
#define _RATAO_H_

#include "Inimigo.h"

class Ratao: public Inimigo 
{
private:
	static int cont;
public:
	Ratao();
	Ratao(float x, float y);
	~Ratao();

	static int getQuantidade();

	static void reseta_cont();
	void diminui_cont();
	void Gravar();
};

#endif 