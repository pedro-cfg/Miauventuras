#ifndef _PLATAFORMA_H_
#define _PLATAFORMA_H_

#include "Obstaculo.h"

class Plataforma: public Obstaculo 
{
public:
	Plataforma(float x, float y);
	~Plataforma();
};

#endif