#ifndef _ENTE_H_
#define _ENTE_H_

class Gerenciador_Grafico;

class Ente 
{
protected:
	static Gerenciador_Grafico* pGG;
public:
	Ente();
	~Ente();

	static void setGerenciadorGrafico(Gerenciador_Grafico* pG);

	virtual void Executar();
	void imprimir_se();
};

#endif 
