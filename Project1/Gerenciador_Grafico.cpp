#include "Gerenciador_Grafico.h"
using namespace Menus;

Gerenciador_Grafico::Gerenciador_Grafico() :
	janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!"),
	vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(LARGURA_EXIBICAO, ALTURA_EXIBICAO)),
	cor_fundo(173, 216, 230),
	marcador1(-800, -400),
	marcador2(800, -400)
{
	InicializaMapaTexturas();

	fundo.setSize((sf::Vector2f)(mapa_texturas[FUNDO1]->getSize()));
	fundo.setTexture(mapa_texturas[FUNDO1]);
	fundo.setPosition(sf::Vector2f(-1000.f, -1080.f));
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
	/*Desaloca as texturas*/
	map<string, sf::Texture*>::const_iterator it = mapa_texturas.begin();
	while (it != mapa_texturas.end())
	{
		sf::Texture* pAux = it->second;
		if (pAux != NULL)
		{
			delete pAux;
		}
		it++;
	}
	mapa_texturas.clear();
}

bool Gerenciador_Grafico::JanelaAberta()
{
	return janela.isOpen();
}

void Gerenciador_Grafico::RedimensionarVista()
{
	float razao = (float)janela.getSize().x / (float)janela.getSize().y;

	vista.setSize(ALTURA_EXIBICAO * razao, ALTURA_EXIBICAO);
}

void Gerenciador_Grafico::AjustarVista(Jogador1* pJ1, Jogador2* pJ2)
{
	float coordY = 0, coordX = 0;
	if (pJ1 && pJ2)
	{
		coordY = ((pJ1->getY() + pJ2->getY()) / 2.0f);
		coordX = ((pJ1->getX() + pJ2->getX()) / 2.0f) + 200.0f;
	}
	else if (pJ1)
	{
		coordY = (pJ1->getY());
		coordX = (pJ1->getX()) + 200.0f;
	}
	else if (pJ2)
	{
		coordY = (pJ2->getY());
		coordX = (pJ2->getX()) + 200.0f;
	}
	if (coordY > -380)
		coordY = -380;
	if (coordX < 57)
		coordX = 57;
	if (coordX > 8950)
		coordX = 8950;
	vista.setCenter(coordX, coordY);
}

void Gerenciador_Grafico::RestaurarVista()
{
	vista.setCenter(800.f, 420.f);
}

void Gerenciador_Grafico::EventosJanela(MaquinaEstados* pMaqEstados)
{
	sf::Event event;
	while (janela.pollEvent(event))
	{
		idEstado id = pMaqEstados->getIdEstadoAtual();
		switch (event.type)
		{
		case sf::Event::Closed:
			janela.close();
			break;
		case sf::Event::Resized:
			RedimensionarVista();
			break;
		case sf::Event::KeyReleased:
			if (id == MENU_PRINCIPAL || id == MENU_FASES || id == MENU_NUM_JOGADORES
				|| id == MENU_PAUSA || id == MENU_PLACAR || id == MENU_FIM)
			{
				Menu* pM = static_cast<Menu*>(pMaqEstados->getEstadoAtual());
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					pM->opcao_acima();
					break;
				case sf::Keyboard::Down:
					pM->opcao_abaixo();
					break;
				case sf::Keyboard::Enter:
					pM->Escolher_Opcao();
					break;
				}
			}
			else
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					if (id == PRIMEIRA_FASE || id == SEGUNDA_FASE)
						pMaqEstados->setEstadoAtual(MENU_PAUSA);
					break;
				case sf::Keyboard::Enter:
					if (id == MENU_NOME)
					{
						MenuNome* pM = static_cast<MenuNome*>(pMaqEstados->getEstadoAtual());
						pM->Escolher_Opcao();
					}
					break;
				}
			}
			break;
		case sf::Event::TextEntered:
			if (id == MENU_NOME && event.text.unicode <= 128)
			{
				MenuNome* pM = static_cast<MenuNome*>(pMaqEstados->getEstadoAtual());
				char tecla = static_cast<char>(event.text.unicode);
				if (tecla == '\b')
					pM->retiraTexto();
				else
					pM->incluiTexto(tecla);
			}
			break;
		default:
			break;
		}
	}
}

void Gerenciador_Grafico::DesenhaTexto(sf::Text* texto, int tamanho)
{
	for (int i = 0; i < tamanho; i++)
		janela.draw(*(texto + i));
	janela.setView(vista);
}

void Gerenciador_Grafico::DesenhaForma(sf::RectangleShape& forma)
{
	janela.draw(forma);
}

void Gerenciador_Grafico::DesenhaTudo(ListaEntidades& lista, Jogador1* pJ1, Jogador2* pJ2)
{
	DesenhaForma(fundo);
	if (pJ1)
	{
		marcador1.AtualizaMarcador(&vista);
		DesenhaForma(marcador1.getForma());
		pJ1->desenhar();
	}
	if (pJ2)
	{
		marcador2.AtualizaMarcador(&vista);
		DesenhaForma(marcador2.getForma());
		pJ2->desenhar();
	}
	lista.Desenha();
	janela.setView(vista);
}

void Gerenciador_Grafico::MudaFundo(int fase)
{
	if (fase == 1)
	{
		setCorFundo(151, 240, 254);
		fundo.setTexture(mapa_texturas[FUNDO1]);
	}
	else if (fase == 2)
	{
		setCorFundo(188, 202, 255);
		fundo.setTexture(mapa_texturas[FUNDO2]);
	}
}

void Gerenciador_Grafico::setCorFundo(int R, int G, int B)
{
	cor_fundo.r = R;
	cor_fundo.g = G;
	cor_fundo.b = B;
}

map<string, sf::Texture*> Gerenciador_Grafico::getMapaTexturas() const
{
	return mapa_texturas;
}

void Gerenciador_Grafico::InicializaMapaTexturas()
{
	sf::Texture* tJ1 = new sf::Texture();
	tJ1->loadFromFile(JOGADOR1);
	mapa_texturas.insert(map<string, sf::Texture*>::value_type(JOGADOR1, tJ1));

	sf::Texture* tJ2 = new sf::Texture();
	tJ2->loadFromFile(JOGADOR2);
	mapa_texturas.insert(map<string, sf::Texture*>::value_type(JOGADOR2, tJ2));

	sf::Texture* tA = new sf::Texture();
	tA->loadFromFile(ARANHA);
	mapa_texturas.insert(map<string, sf::Texture*>::value_type(ARANHA, tA));

	sf::Texture* tL = new sf::Texture();
	tL->loadFromFile(LAGARTIXA);
	mapa_texturas.insert(map<string, sf::Texture*>::value_type(LAGARTIXA, tL));

	sf::Texture* tR = new sf::Texture();
	tR->loadFromFile(RATAO);
	mapa_texturas.insert(map<string, sf::Texture*>::value_type(RATAO, tR));

	sf::Texture* tP = new sf::Texture();
	tP->loadFromFile(PLATAFORMA);
	mapa_texturas.insert(map<string, sf::Texture*>::value_type(PLATAFORMA, tP));

	sf::Texture* tT = new sf::Texture();
	tT->loadFromFile(TEIA);
	mapa_texturas.insert(map<string, sf::Texture*>::value_type(TEIA, tT));

	sf::Texture* tE = new sf::Texture();
	tE->loadFromFile(ESPINHO);
	mapa_texturas.insert(map<string, sf::Texture*>::value_type(ESPINHO, tE));

	sf::Texture* tPr = new sf::Texture();
	tPr->loadFromFile(PROJETIL);
	mapa_texturas.insert(map<string, sf::Texture*>::value_type(PROJETIL, tPr));

	sf::Texture* tF1 = new sf::Texture();
	tF1->loadFromFile(FUNDO1);
	mapa_texturas.insert(map<string, sf::Texture*>::value_type(FUNDO1, tF1));

	sf::Texture* tF2 = new sf::Texture();
	tF2->loadFromFile(FUNDO2);
	mapa_texturas.insert(map<string, sf::Texture*>::value_type(FUNDO2, tF2));
}

void Gerenciador_Grafico::AtualizarTela()
{
	janela.display();
	janela.clear(cor_fundo);
}

void Gerenciador_Grafico::FecharJanela()
{
	janela.close();
}

Marcador_Vida* Gerenciador_Grafico::getMarcador1()
{
	return &marcador1;
}
Marcador_Vida* Gerenciador_Grafico::getMarcador2()
{
	return &marcador2;
}