#include "stdafx.h"
#include "Jogo.h"

Jogo::Jogo() :
	pJ1(NULL),
	pJ2(NULL),
	gerenciador_grafico(),
	menu_principal(),
	menu_fases(),
	menu_nome(),
	menu_num_jogadores(),
	menu_pausa(),
	menu_placar(),
	menu_fim(),
	primeira_fase(),
	segunda_fase(),
	maquina_de_estados(MENU_PRINCIPAL, &menu_principal)
{
	Inicializar();
	Executar();
}

Jogo::~Jogo()
{
	if (pJ1 != NULL)
	{
		delete pJ1;
	}
	if (pJ2 != NULL)
	{
		delete pJ2;
	}
}

void Jogo::Executar()
{
	float dT = 0.0f;
	sf::Clock relogio;

	while (gerenciador_grafico.JanelaAberta())
	{
		dT = relogio.restart().asSeconds();

		gerenciador_grafico.EventosJanela(&maquina_de_estados);

		maquina_de_estados.ExecutaEstadoAtual(dT);

		gerenciador_grafico.AtualizarTela();
	}
}

void Jogo::Inicializar()
{
	Menu::setPonteiroJogo(this);
	Ente::setGerenciadorGrafico(&gerenciador_grafico);

	pJ1 = new Jogador1(0, -100);
	pJ2 = new Jogador2(0, -100);

	gerenciador_grafico.getMarcador1()->setJogador(static_cast<Jogador*>(pJ1));
	gerenciador_grafico.getMarcador2()->setJogador(static_cast<Jogador*>(pJ2));

	InicializarEstados();
}

void Jogo::InicializarEstados()
{
	maquina_de_estados.incluirEstado(MENU_PRINCIPAL, static_cast<Estado*>(&menu_principal));
	maquina_de_estados.incluirEstado(MENU_FASES, static_cast<Estado*>(&menu_fases));
	maquina_de_estados.incluirEstado(MENU_NUM_JOGADORES, static_cast<Estado*>(&menu_num_jogadores));
	maquina_de_estados.incluirEstado(MENU_PLACAR, static_cast<Estado*>(&menu_placar));
	maquina_de_estados.incluirEstado(MENU_PAUSA, static_cast<Estado*>(&menu_pausa));
	maquina_de_estados.incluirEstado(MENU_NOME, static_cast<Estado*>(&menu_nome));
	maquina_de_estados.incluirEstado(MENU_FIM, static_cast<Estado*>(&menu_fim));
	maquina_de_estados.incluirEstado(PRIMEIRA_FASE, static_cast<Estado*>(&primeira_fase));
	maquina_de_estados.incluirEstado(SEGUNDA_FASE, static_cast<Estado*>(&segunda_fase));
}

Jogador1* Jogo::getJogador1() const
{
	return pJ1;
}

Jogador2* Jogo::getJogador2() const
{
	return pJ2;
}

FasePrimeira* Jogo::getPrimeiraFase()
{
	return &primeira_fase;
}

FaseSegunda* Jogo::getSegundaFase()
{
	return &segunda_fase;
}

void Jogo::Gravar()
{
	GravarJogadores();
	GravarFase();
}

void Jogo::Carregar()
{
	CarregarJogadores();
	CarregarFase();
}

void Jogo::CarregarJogadores()
{
	fstream arquivo;
	arquivo.open(JOGADORES_SAVE, ios::binary | ios::in);

	bool dois_jogadores;
	arquivo.read((char*)&dois_jogadores, sizeof(dois_jogadores));
	Menu::setDoisJogadores(dois_jogadores);

	pJ1->Carregar(arquivo);
	pJ2->Carregar(arquivo);

	arquivo.close();
}

void Jogo::CarregarFase()
{
	if (pJ1->getFase() == 2 || pJ2->getFase() == 2)
	{
		MudaFundo(2);
		pJ1->setFase(2);
		pJ2->setFase(2);
		segunda_fase.Carregar(pJ1, pJ2);
		maquina_de_estados.setEstadoAtual(SEGUNDA_FASE);
	}
	else
	{
		MudaFundo(1);
		pJ1->setFase(1);
		pJ2->setFase(1);
		primeira_fase.Carregar(pJ1, pJ2);
		maquina_de_estados.setEstadoAtual(PRIMEIRA_FASE);
	}
}

void Jogo::GravarJogadores()
{
	fstream arquivo;
	arquivo.open(JOGADORES_SAVE, ios::binary | ios::out | ios::trunc);

	bool dois_jogadores = Menu::getDoisJogadores();
	arquivo.write((char*)&dois_jogadores, sizeof(dois_jogadores));

	pJ1->GravarInfo(arquivo);
	pJ2->GravarInfo(arquivo);

	arquivo.close();
}

void Jogo::GravarFase()
{
	if (pJ1->getFase() == 2 || pJ2->getFase() == 2)
		segunda_fase.Gravar();
	else
		primeira_fase.Gravar();
}

void Jogo::MudaFundo(int fase)
{
	gerenciador_grafico.MudaFundo(fase);
}


