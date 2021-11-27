#include "stdafx.h"
#include "Fase.h"
#include "Gerenciador_Grafico.h"
using namespace Menus;

Fase::Fase() :
	Ente(),
	Estado(),
	gerenciador_colisoes(&lista_entidades),
	pJ1(NULL),
	pJ2(NULL)
{
}

Fase::~Fase()
{
	pJ1 = NULL;
	pJ2 = NULL;
}

void Fase::ExecutaEstado(float dT)
{
	this->Executar(dT);
}

void Fase::Executar(float dT)
{
	if (pJ1)
	{
		gerenciador_colisoes.Checa_Colisao(static_cast<Jogador*>(pJ1));
		pJ1->Executar(dT);
	}
	if (pJ2)
	{
		gerenciador_colisoes.Checa_Colisao(static_cast<Jogador*>(pJ2));
		pJ2->Executar(dT);
	}
	gerenciador_colisoes.Checa_Colisao_Inimigos();

	lista_entidades.Executar(dT);

	pGG->AjustarVista(pJ1, pJ2);

	pGG->DesenhaTudo(lista_entidades, pJ1, pJ2);

	Passou_Fase();
	MorteJogadores();
}

void Fase::Gerar_Objetos()
{
	srand((unsigned int)time(NULL));
	Gerar_Inimigos();
	Gerar_Obstaculos();
}

void Fase::Gerar_Inimigos()
{
	Gerar_Chefao();
	int instancias, posicao;

	/*Alcance de instâncias: 3-5*/
	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++)
	{
		posicao = (rand() % 9000) + 300;
		Aranha* pA = new Aranha((float)posicao, -1000);
		lista_entidades.Inserir(static_cast<Entidade*>(pA));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pA));
	}

	/*Alcance de instâncias: 3-5*/
	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++)
	{
		posicao = (rand() % 9000) + 300;
		Lagartixa* pL = new Lagartixa((float)posicao, -1000);
		lista_entidades.Inserir(static_cast<Entidade*>(pL));
		gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pL));
	}
}

void Fase::Gerar_Obstaculos()
{
	Gerar_Plataformas();
	int instancias, posicao;

	/*Alcance de instâncias: 3-5*/
	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++) {
		posicao = (rand() % 9000) + 300;
		Espinho* pE = new Espinho((float)posicao, -75);
		lista_entidades.Inserir(static_cast<Entidade*>(pE));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pE));
	}

	/*Alcance de instâncias: 3-5*/
	instancias = (rand() % 3) + 3;
	for (int i = 0; i < instancias; i++) {
		posicao = (rand() % 9000) + 300;
		Teia* pT = new Teia((float)posicao, -200);
		lista_entidades.Inserir(static_cast<Entidade*>(pT));
		gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pT));
	}
}

void Fase::Inserir_Entidade(Entidade* pE)
{
	lista_entidades.Inserir(pE);
}

void Fase::reseta_fase(Jogador1* p1, Jogador2* p2, bool reinicio)
{
	lista_entidades.Limpar();
	gerenciador_colisoes.LimpaListas();
	reseta_entidades_cont();
	pJ1 = p1;
	pJ2 = p2;
	if (pJ1)
	{
		if (reinicio)
			pJ1->reseta_jogador(true, true);
		else
			pJ1->reseta_jogador();
	}
	if (pJ2)
	{
		if (reinicio)
			pJ2->reseta_jogador(true, true);
		else
			pJ2->reseta_jogador();
	}

	Gerar_Objetos();

	Entidade::setPonteiroLista(&lista_entidades);
	Entidade::setGerenciadorColisoes(&gerenciador_colisoes);
}

void Fase::reseta_entidades_cont()
{
	Aranha::reseta_cont();
	Lagartixa::reseta_cont();
	Ratao::reseta_cont();
	Plataforma::reseta_cont();
	Teia::reseta_cont();
	Espinho::reseta_cont();
}

void Fase::MorteJogadores()
{
	if (pJ1 && pJ1->Morreu())
	{
		pJ1->reseta_jogador();
		pJ1 = NULL;
	}
	if (pJ2 && pJ2->Morreu())
	{
		pJ2->reseta_jogador();
		pJ2 = NULL;
	}
	if (!(pJ1 || pJ2))
	{
		pMaquinaEstados->setEstadoAtual(MENU_FIM);
		MenuFim* pMenu = static_cast<MenuFim*>(pMaquinaEstados->getEstadoAtual());
		pMenu->setVitoria(false);
	}
}

void Fase::Limpar()
{
	lista_entidades.Limpar();
	pJ1 = NULL;
	pJ2 = NULL;
	gerenciador_colisoes.LimpaListas();
}

void Fase::Gravar()
{
	GravarJogadores();
	GravarEntidades();
}

void Fase::GravarJogadores()
{
	fstream arquivo;
	arquivo.open(JOGADORESFASE_SAVE, ios::binary | ios::out | ios::trunc);

	bool p1 = false, p2 = false;
	if (pJ1)
		p1 = true;
	if (pJ2)
		p2 = true;
	arquivo.write((char*)&p1, sizeof(p1));
	arquivo.write((char*)&p2, sizeof(p2));

	arquivo.close();
}

void Fase::GravarEntidades()
{
	int cont;
	fstream arquivo;

	arquivo.open(ARANHAS_SAVE, ios::binary | ios::out | ios::trunc);
	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		cont = Aranha::getQuantidade();
		arquivo.write((char*)&cont, sizeof(cont));
	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();

	arquivo.open(ESPINHOS_SAVE, ios::binary | ios::out | ios::trunc);
	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		cont = Espinho::getQuantidade();
		arquivo.write((char*)&cont, sizeof(cont));
	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();

	arquivo.open(LAGARTIXAS_SAVE, ios::binary | ios::out | ios::trunc);
	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		cont = Lagartixa::getQuantidade();
		arquivo.write((char*)&cont, sizeof(cont));
	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();

	arquivo.open(PLATAFORMAS_SAVE, ios::binary | ios::out | ios::trunc);
	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		cont = Plataforma::getQuantidade();
		arquivo.write((char*)&cont, sizeof(cont));
	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();

	arquivo.open(RATAO_SAVE, ios::binary | ios::out | ios::trunc);
	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		cont = Ratao::getQuantidade();
		arquivo.write((char*)&cont, sizeof(cont));
	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();

	arquivo.open(TEIAS_SAVE, ios::binary | ios::out | ios::trunc);
	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		cont = Teia::getQuantidade();
		arquivo.write((char*)&cont, sizeof(cont));
	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();

	lista_entidades.Gravar();
}

void Fase::Carregar(Jogador1* p1, Jogador2* p2)
{
	Entidade::setPonteiroLista(&lista_entidades);
	Entidade::setGerenciadorColisoes(&gerenciador_colisoes);
	Limpar();

	CarregarJogadores(p1, p2);
	CarregarEntidades();
}

void Fase::CarregarEntidades()
{
	CarregarInimigos();
	CarregarObstaculos();
}

void Fase::CarregarJogadores(Jogador1* p1, Jogador2* p2)
{
	fstream arquivo;

	arquivo.open(JOGADORESFASE_SAVE, ios::binary | ios::in);
	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		bool j1 = false, j2 = false;
		arquivo.read((char*)&j1, sizeof(j1));
		arquivo.read((char*)&j2, sizeof(j2));

		if (j1)
			pJ1 = p1;
		if (j2)
			pJ2 = p2;
	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();
}

void Fase::CarregarInimigos()
{
	fstream arquivo;
	int cont;

	arquivo.open(ARANHAS_SAVE, ios::binary | ios::in);

	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		arquivo.read((char*)&cont, sizeof(cont));
		for (int i = 0; i < cont; i++)
		{
			Aranha* pAux = new Aranha();

			pAux->Carregar(arquivo);

			lista_entidades.Inserir(static_cast<Entidade*>(pAux));
			gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pAux));
		}

	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();

	arquivo.open(LAGARTIXAS_SAVE, ios::binary | ios::in);

	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		arquivo.read((char*)&cont, sizeof(cont));
		for (int i = 0; i < cont; i++)
		{
			Lagartixa* pAux = new Lagartixa();

			pAux->Carregar(arquivo);

			lista_entidades.Inserir(static_cast<Entidade*>(pAux));
			gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pAux));
		}
	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();

	arquivo.open(RATAO_SAVE, ios::binary | ios::in);
	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		arquivo.read((char*)&cont, sizeof(cont));
		for (int i = 0; i < cont; i++)
		{
			Ratao* pAux = new Ratao();

			pAux->Carregar(arquivo);

			lista_entidades.Inserir(static_cast<Entidade*>(pAux));
			gerenciador_colisoes.Inserir(static_cast<Inimigo*>(pAux));
		}
	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();
}

void Fase::CarregarObstaculos()
{
	fstream arquivo;
	int cont;

	arquivo.open(ESPINHOS_SAVE, ios::binary | ios::in);
	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		arquivo.read((char*)&cont, sizeof(cont));
		for (int i = 0; i < cont; i++)
		{
			Espinho* pAux = new Espinho();

			pAux->Carregar(arquivo);

			lista_entidades.Inserir(static_cast<Entidade*>(pAux));
			gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pAux));
		}
	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();

	arquivo.open(PLATAFORMAS_SAVE, ios::binary | ios::in);
	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		arquivo.read((char*)&cont, sizeof(cont));
		for (int i = 0; i < cont; i++)
		{
			Plataforma* pAux = new Plataforma();

			pAux->Carregar(arquivo);

			lista_entidades.Inserir(static_cast<Entidade*>(pAux));
			gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pAux));
		}
	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();

	arquivo.open(TEIAS_SAVE, ios::binary | ios::in);
	try
	{
		if (!arquivo)
			throw "ERRO AO ABRIR ARQUIVO";

		arquivo.read((char*)&cont, sizeof(cont));
		for (int i = 0; i < cont; i++)
		{
			Teia* pAux = new Teia();

			pAux->Carregar(arquivo);

			lista_entidades.Inserir(static_cast<Entidade*>(pAux));
			gerenciador_colisoes.Inserir(static_cast<Obstaculo*>(pAux));
		}
	}
	catch (const char* erro)
	{
		cerr << erro << endl;
	}
	arquivo.close();
}