#include "Ente.h"
#include "Gerenciador_Grafico.h"

/*Ponteiro estático para gerenciador gráfico*/
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

