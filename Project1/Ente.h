#ifndef _ENTE_H_
#define _ENTE_H_

//#include "Gerenciador_Grafico.h"
class Gerenciador_Grafico;

class Ente 
{
protected:
	static Gerenciador_Grafico* pGG;
public:
	Ente();
	~Ente();

	static void setGerenciadorGrafico(Gerenciador_Grafico* pG);

	//virtual void Executar(float dT);
	void imprimir_se();
};

#endif 
