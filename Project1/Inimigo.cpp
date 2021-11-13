#include "Inimigo.h"

Inimigo::Inimigo():
	Personagem()
{
	setTipo();
	//vidas = 3;
}

Inimigo::~Inimigo() 
{

}

void Inimigo::setTipo() {
	tipo = "Inimigo";
}


