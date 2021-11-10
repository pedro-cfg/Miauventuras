#ifndef _FASE_H_
#define _FASE_H_

#include "Ente.h"

class Fase: public Ente 
{
public:    
	Fase();
	~Fase();
	//virtual void Executar();
	void gerenciar_colisoes();
};

#endif