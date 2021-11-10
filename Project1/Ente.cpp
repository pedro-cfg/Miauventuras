#include "Ente.h"
#include "Gerenciador_Grafico.h"

Ente::Ente() :
	gerenciar_graficos(NULL)
{

}

Ente::~Ente() {

}

void Ente::setGerenciadorGrafico(Gerenciador_Grafico* pG)
{
	gerenciar_graficos = pG;
}

void Ente::Executar() {

}

void Ente::imprimir_se() {

}

