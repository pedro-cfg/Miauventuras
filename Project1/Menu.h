#ifndef _MENU_H_
#define _MENU_H_

#include "Ente.h"

class FasePrimeira;

class Menu: public Ente 
{
private:
	int indice;
	int* estado_jogo;
	bool* dois_jogadores;
	int estado_menu;
	int tamanho_texto;
	bool inicializar;
	sf::Font fonte;
	sf::Text texto[6];
public:
	Menu(float largura, float altura, int* estado, bool* dois_j);

	~Menu();

	void InicializaTexto();
	
	void Executar(float dT);
	void imprimir_se();

	void setTamanhoTexto(int tam);
	void setEstadoMenu(int estado);
	void setInicializar(bool ini);

	void Escolher_Opcao();

	float CalculaTamanho(sf::Text texto);

	void opcao_acima();
	void opcao_abaixo();
};

#endif