#ifndef _ENTE_H_
#define _ENTE_H_

class Gerenciador_Grafico;

class Ente 
{
protected:
	Gerenciador_Grafico* gerenciar_graficos;
public:
	Ente();
	~Ente();

	void setGerenciadorGrafico(Gerenciador_Grafico* pG);
	virtual void Executar();
	void imprimir_se();
};

#endif 
