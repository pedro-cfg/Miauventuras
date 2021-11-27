#ifndef _ESTADO_H_
#define _ESTADO_H_

#include "MaquinaEstados.h"

/*Classe abstrata*/
class Estado
{
protected:
	static MaquinaEstados* pMaquinaEstados;
public:
	Estado();
	virtual~Estado();
	static void setMaquinaEstados(MaquinaEstados* pMaquina);

	/*Método executado polimorficamente*/
	virtual void ExecutaEstado(float dT) = 0;
};

#endif