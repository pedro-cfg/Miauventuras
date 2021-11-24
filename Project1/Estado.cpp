#include "Estado.h"

MaquinaEstados* Estado::pMaquinaEstados = NULL;

void Estado::setMaquinaEstados(MaquinaEstados* pMaquina)
{
	pMaquinaEstados = pMaquina;
}

Estado::Estado()
{
}

Estado::~Estado()
{
}