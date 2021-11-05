#ifndef _ENTE_H_
#define _ENTE_H_

class Ente {
protected:
	int id;
public:
	Ente();
	~Ente();
	virtual void Executar() = 0;
	void imprimir_se();
};

#endif 
