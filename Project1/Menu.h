#ifndef _MENU_H_
#define _MENU_H_

#include "Ente.h"

class FasePrimeira;

class Menu: public Ente 
{
private:
	int indice;
	sf::Font fonte;
	sf::Text texto[3];
	FasePrimeira* pF;
public:
	Menu(float largura, float altura, FasePrimeira* pFase);
	~Menu();

	void InicializaTexto(float largura, float altura);

	void Executar(float dT);
	void imprimir_se();

	void Escolher_Opcao(sf::Window& janela);

	void opcao_acima();
	void opcao_abaixo();
};

#endif