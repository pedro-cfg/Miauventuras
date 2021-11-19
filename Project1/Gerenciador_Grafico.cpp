#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico(Menu* pM) :
	janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!"),
	vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(LARGURA_EXIBICAO, ALTURA_EXIBICAO)),
	marcador1(0, 0),
	pM(pM)
{
	InicializaMapaTexturas();

	fundo.setSize((sf::Vector2f)(mapa_texturas[FUNDO1]->getSize()));
	fundo.setTexture(mapa_texturas[FUNDO1]);
	fundo.setPosition(sf::Vector2f(-1000.f, -1080.f));
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{
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

void Gerenciador_Grafico::AjustarVista(Jogador* jogador)
{
	float coordY = jogador->getY();
	float coordX = jogador->getX() + 200.f;
	if (coordY > -380)
		coordY = -380;
	if (coordX < 57)
		coordX = 57;
	if (coordX > 8950)
		coordX = 8950;
	vista.setCenter(coordX, coordY);
	marcador1.getforma().setPosition(coordX + 800, coordY - 400);
	marcador1.AtualizaMarcador();
	DesenhaForma(fundo);
	DesenhaForma(marcador1.getforma());
}

void Gerenciador_Grafico::RestaurarVista()
{
	vista.setCenter(800.f, 420.f);
}

void Gerenciador_Grafico::EventosJanela(int& estado_jogo)
{
	sf::Event event;
	while (janela.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			janela.close();
			break;
		case sf::Event::Resized:
			RedimensionarVista();
			break;
		case sf::Event::KeyReleased:
			if (estado_jogo == 0)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::W:
					pM->opcao_acima();
					break;
				case sf::Keyboard::S:
					pM->opcao_abaixo();
					break;
				case sf::Keyboard::Space:
					pM->Escolher_Opcao();
					break;
				}
			}
			else {
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					estado_jogo = 4;
					break;
				}
			}
			break;
		default:
			break;
		}
	}
}

void Gerenciador_Grafico::DesenhaTexto(sf::Text* texto)
{
	janela.draw(*texto);
	janela.draw(*(texto + 1));
	janela.draw(*(texto + 2));
	janela.draw(*(texto + 3));
	janela.draw(*(texto + 4));
	/*janela.draw(*(texto + 5));*/
	janela.setView(vista);
}

void Gerenciador_Grafico::DesenhaForma(sf::RectangleShape& forma)
{
	janela.draw(forma);
}

void Gerenciador_Grafico::DesenhaTudo(ListaEntidades& lista)
{
	lista.Desenha();
	janela.setView(vista);
}

void Gerenciador_Grafico::MudaFundo(int fase)
{
	if (fase == 1)
		fundo.setTexture(mapa_texturas[FUNDO1]);
	else
		fundo.setTexture(mapa_texturas[FUNDO2]);
}

map<string, sf::Texture*> Gerenciador_Grafico::getMapaTexturas() const
{
	return mapa_texturas;
}

void Gerenciador_Grafico::InicializaMapaTexturas()
{
	sf::Texture* tJ = new sf::Texture();
	tJ->loadFromFile(JOGADOR1);
	mapa_texturas.insert(map<string, sf::Texture*>::value_type(JOGADOR1, tJ));

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

void Gerenciador_Grafico::LimparTela()
{
	janela.display();
	janela.clear();
}

void Gerenciador_Grafico::FecharJanela()
{
	janela.close();
}

Gerenciador_Grafico::Marcador_Vida* Gerenciador_Grafico::getMarcador()
{
	return &marcador1;
}

Gerenciador_Grafico::Marcador_Vida::Marcador_Vida(float x1, float y1) :
	x(0), y(0), pJogador(NULL)
{
	x = x1;
	y = y1;

	CarregaTextura("Texturas/Numeros/1.png");
	CarregaTextura("Texturas/Numeros/2.png");
	CarregaTextura("Texturas/Numeros/3.png");
	CarregaTextura("Texturas/Numeros/4.png");
	CarregaTextura("Texturas/Numeros/5.png");
	CarregaTextura("Texturas/Numeros/6.png");
	CarregaTextura("Texturas/Numeros/7.png");

	forma_marcador.setSize((sf::Vector2f)texturas[0]->getSize());
	forma_marcador.setTexture(texturas[0]);
	forma_marcador.setOrigin(forma_marcador.getSize() / 2.0f);
	forma_marcador.setPosition(sf::Vector2f(x, y));
}

Gerenciador_Grafico::Marcador_Vida::~Marcador_Vida()
{
	int tam = (int)texturas.size();
	for (int i = 0; i < tam; i++)
	{
		if (texturas[i] != NULL)
		{
			delete texturas[i];
		}
	}
	texturas.clear();
}

void Gerenciador_Grafico::Marcador_Vida::CarregaTextura(string caminho)
{
	sf::Texture* pTextura = new sf::Texture();
	pTextura->loadFromFile(caminho);

	texturas.push_back(pTextura);
}

void Gerenciador_Grafico::Marcador_Vida::setJogador(Jogador* pJ)
{
	pJogador = pJ;
}

void Gerenciador_Grafico::Marcador_Vida::AtualizaMarcador()
{
	int vidas = pJogador->getVidas();

	if (0 < vidas && vidas <= 7)
	{
		forma_marcador.setTexture(texturas[vidas - 1]);
	}
}

sf::RectangleShape& Gerenciador_Grafico::Marcador_Vida::getforma()
{
	return forma_marcador;
}

