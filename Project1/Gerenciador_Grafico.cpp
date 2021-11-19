#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico(Menu* pM) :
	janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!"),
	vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(LARGURA_EXIBICAO, ALTURA_EXIBICAO)),
	marcador1(0, 0),
	pM(pM)
{
	//sf::RenderWindow janela(sf::VideoMode(LARGURA_JANELA, ALTURA_JANELA), "Teste!");
	//sf::View vista(sf::Vector2f(0.f, 0.f), sf::Vector2f(640.f, 360.f));
	textura_fundo1.loadFromFile("Texturas/fundo1.png");
	textura_fundo2.loadFromFile("Texturas/fundo2.png");
	fundo.setSize((sf::Vector2f)textura_fundo1.getSize());
	fundo.setTexture(&textura_fundo1);
	fundo.setPosition(sf::Vector2f(-1000.f, -1080.f));
}

Gerenciador_Grafico::~Gerenciador_Grafico()
{

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
		fundo.setTexture(&textura_fundo1);
	else
		fundo.setTexture(&textura_fundo2);
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

