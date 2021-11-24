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
	contador_tempo = 0.f;
}

Ente::~Ente() 
{
}

void Ente::Atualiza_Contador(float dT, bool zera)
{
	if (zera)
	{
		contador_tempo = 0.f;
	}
	else
	{
		contador_tempo += dT;
		if (contador_tempo > 20.f)
			contador_tempo = 0.f;
	}
}
