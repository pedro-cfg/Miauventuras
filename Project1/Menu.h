#ifndef _MENU_H_
#define _MENU_H_

#include "Ente.h"
#include "Estado.h"

class FasePrimeira;
class Jogador;
class Jogo;

namespace Menus {

	class Menu : public Ente, public Estado
	{
	protected:
		static Jogo* pJogo;
		static bool dois_jogadores;

		int indice;

		int linhas_texto;

		static bool eventoPlacar;

		sf::Font fonte;
		sf::Text texto[7];
	public:
		Menu();
		virtual~Menu();

		static void setPonteiroJogo(Jogo* pJ);
		static void setDoisJogadores(bool DJ);
		static bool getDoisJogadores();

		virtual void InicializaTexto();
		virtual void Escolher_Opcao() = 0;

		void ExecutaEstado(float dT);
		virtual void Executar(float dT);

		void desenhar();

		float CalculaTamanho(sf::Text texto);

		void opcao_acima();
		void opcao_abaixo();

		void SalvarPontuacao();

		void setCorTexto();
	};

}

#endif