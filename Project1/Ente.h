#ifndef _ENTE_H_
#define _ENTE_H_

class Gerenciador_Grafico;

class Ente 
{
protected:
	static Gerenciador_Grafico* pGG;
	float contador_tempo;
public:
	Ente();
	virtual~Ente();

	static void setGerenciadorGrafico(Gerenciador_Grafico* pG);

	virtual void Executar(float dT) = 0;
	virtual void desenhar(){}

	void Atualiza_Contador(float dT, bool zera = false);
};

#endif 
