#ifndef _ESTADO_H_
#define _ESTADO_H_

#include "MaquinaEstados.h"

class Estado
{
protected:
	static MaquinaEstados* pMaquinaEstados;
public:
	Estado();
	~Estado();
	static void setMaquinaEstados(MaquinaEstados* pMaquina);
	virtual void ExecutaEstado(float dT);
};

#endif