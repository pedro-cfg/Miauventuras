#include "Ente.h"
#include "Gerenciador_Grafico.h"

/*Ponteiro est�tico para gerenciador gr�fico*/
Gerenciador_Grafico* Ente::pGG = NULL;

void Ente::setGerenciadorGrafico(Gerenciador_Grafico* pG)
{
	pGG = pG;
}

Ente::Ente()
{

}

Ente::~Ente() {

}


/*
void Ente::Executar(float dT) {

}*/

void Ente::imprimir_se() {

}

