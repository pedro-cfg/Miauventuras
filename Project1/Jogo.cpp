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
	Estado::setMaquinaEstados(&maquina_de_estados);
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
	fstream arquivo;
	arquivo.open("Persistencia/memoria.bin", ios::binary | ios::out | ios::trunc);

	int faseJ1 = pJ1->getFase();
	int faseJ2 = pJ2->getFase();
	arquivo.write((char*)&faseJ1, sizeof(faseJ1));
	arquivo.write((char*)&faseJ2, sizeof(faseJ2));

	bool dois_jogadores = menu_fases.getDoisJogadores();
	arquivo.write((char*)&dois_jogadores, sizeof(dois_jogadores));

	GravarJogadores(arquivo);

	if (faseJ1 == 2 || faseJ2 == 2)
		segunda_fase.GravarLista(arquivo);
	else
		primeira_fase.GravarLista(arquivo);
}

void Jogo::Carregar()
{
	fstream arquivo;
	arquivo.open("Persistencia/memoria.bin", ios::binary | ios::in);

	int faseJ1, faseJ2;
	arquivo.read((char*)&faseJ1, sizeof(faseJ1));
	arquivo.read((char*)&faseJ2, sizeof(faseJ2));

	bool dois_jogadores;
	arquivo.read((char*)&dois_jogadores, sizeof(dois_jogadores));
	Menu::setDoisJogadores(dois_jogadores);

	LerJogador(arquivo);

	if (faseJ1 == 2 || faseJ2 == 2) 
	{
		MudaFundo(2);
		pJ1->setFase(2);
		pJ2->setFase(2);
		segunda_fase.LerLista(arquivo, pJ1, pJ2);
		maquina_de_estados.setEstadoAtual(SEGUNDA_FASE);
	}
	else 
	{
		MudaFundo(1);
		pJ1->setFase(1);
		pJ2->setFase(1);
		primeira_fase.LerLista(arquivo, pJ1, pJ2);
		maquina_de_estados.setEstadoAtual(PRIMEIRA_FASE);
	}
}

void Jogo::GravarJogadores(fstream& arquivo)
{
	float x, y, x2, y2;
	int vidas, vidas2, pontos, pontos2, tamanhoNome1, tamanhoNome2;
	string nome1, nome2;

	x = pJ1->getX();
	y = pJ1->getY();
	vidas = pJ1->getVidas();
	pontos = pJ1->getPontuacao();

	x2 = pJ2->getX();
	y2 = pJ2->getY();
	vidas2 = pJ2->getVidas();
	pontos2 = pJ2->getPontuacao();

	nome1 = pJ1->getNome();
	nome2 = pJ2->getNome();
	tamanhoNome1 = nome1.size();
	tamanhoNome2 = nome2.size();

	arquivo.write((char*)&x, sizeof(x));
	arquivo.write((char*)&y, sizeof(y));
	arquivo.write((char*)&vidas, sizeof(vidas));
	arquivo.write((char*)&pontos, sizeof(pontos));

	arquivo.write((char*)&x2, sizeof(x2));
	arquivo.write((char*)&y2, sizeof(y2));
	arquivo.write((char*)&vidas2, sizeof(vidas2));
	arquivo.write((char*)&pontos2, sizeof(pontos2));

	arquivo.write((char*)&tamanhoNome1, sizeof(tamanhoNome1));
	arquivo.write((char*)&nome1[0], tamanhoNome1);
	arquivo.write((char*)&tamanhoNome2, sizeof(tamanhoNome2));
	arquivo.write((char*)&nome2[0], tamanhoNome2);

}

void Jogo::LerJogador(fstream& arquivo)
{
	float x, y, x2, y2;
	int vidas, vidas2, pontos, pontos2, tamanhoNome1, tamanhoNome2;
	string nome1, nome2;

	arquivo.read((char*)&x, sizeof(x));
	arquivo.read((char*)&y, sizeof(y));
	arquivo.read((char*)&vidas, sizeof(vidas));
	arquivo.read((char*)&pontos, sizeof(pontos));

	pJ1->setVidas(vidas);
	pJ1->setPontuacao(pontos);
	pJ1->Reposicionar(x, y);

	arquivo.read((char*)&x2, sizeof(x2));
	arquivo.read((char*)&y2, sizeof(y2));
	arquivo.read((char*)&vidas2, sizeof(vidas2));
	arquivo.read((char*)&pontos2, sizeof(pontos2));

	pJ2->setVidas(vidas2);
	pJ2->setPontuacao(pontos2);
	pJ2->Reposicionar(x2, y2);

	arquivo.read((char*)&tamanhoNome1, sizeof(tamanhoNome1));
	nome1.resize(tamanhoNome1);
	arquivo.read((char*)&nome1[0], tamanhoNome1);
	arquivo.read((char*)&tamanhoNome2, sizeof(tamanhoNome2));
	nome2.resize(tamanhoNome2);
	arquivo.read((char*)&nome2[0], tamanhoNome2);
}

void Jogo::MudaFundo(int fase)
{
	gerenciador_grafico.MudaFundo(fase);
}


