#include "MaquinaEstados.h"
#include "Estado.h"

MaquinaEstados::MaquinaEstados(idEstado idInicial, Estado* estadoInicial)
{
	incluirEstado(idInicial, estadoInicial);
	estadoAtual = estadoInicial;
	idEstadoAtual = idInicial;
	Estado::setMaquinaEstados(this);
}

MaquinaEstados::~MaquinaEstados()
{
}

void MaquinaEstados::ExecutaEstadoAtual(float dT)
{
	if (estadoAtual)
	{
		estadoAtual->ExecutaEstado(dT);
	}
}

void MaquinaEstados::setEstadoAtual(idEstado e)
{
	estadoAtual = mapaEstados[e];
	idEstadoAtual = e;
}

idEstado MaquinaEstados::getIdEstadoAtual() const
{
	return idEstadoAtual;
}

Estado* MaquinaEstados::getEstadoAtual() const
{
	return estadoAtual;
}

void MaquinaEstados::incluirEstado(idEstado id, Estado* e)
{
	mapaEstados.insert(map<idEstado, Estado*>::value_type(id, e));
}

Estado* MaquinaEstados::buscaEstado(idEstado id)
{
	return (mapaEstados[id]);
}
