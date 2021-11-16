#ifndef _ENTE_H_
#define _ENTE_H_

//#include "Gerenciador_Grafico.h"
class Gerenciador_Grafico;

class Ente 
{
protected:
	static Gerenciador_Grafico* pGG;
	bool executando;
	float contador_tempo;
public:
	Ente();
	~Ente();

	static void setGerenciadorGrafico(Gerenciador_Grafico* pG);

	virtual void Executar(float dT);
	virtual void imprimir_se();

	void Atualiza_Contador(float dT, bool zera = false);

	void setExecutando(bool exec);
};

#endif 
