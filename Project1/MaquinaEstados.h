#ifndef _MAQUINA_ESTADOS_H_
#define _MAQUINA_ESTADOS_H_

#include "stdafx.h"

enum idEstado
{
	MENU_PRINCIPAL,
	MENU_FASES,
	MENU_NUM_JOGADORES,
	MENU_PLACAR,
	MENU_PAUSA,
	MENU_NOME,
	MENU_FIM,
	PRIMEIRA_FASE,
	SEGUNDA_FASE
};

class Estado;

/*Gerencia a mudança de estado do programa*/
class MaquinaEstados
{
private:
	Estado* estadoAtual;
	idEstado idEstadoAtual;
	map<idEstado, Estado*> mapaEstados;
public:
	MaquinaEstados(idEstado idInicial, Estado* estadoInicial);
	~MaquinaEstados();

	void ExecutaEstadoAtual(float dT);

	void setEstadoAtual(idEstado id);
	idEstado getIdEstadoAtual() const;
	Estado* getEstadoAtual() const;

	void incluirEstado(idEstado id, Estado* e);
	Estado* buscaEstado(idEstado id);
};

#endif