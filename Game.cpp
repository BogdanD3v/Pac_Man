#include "Game.h"

void Game::initializeWindow()
{
	this->videoMode.height = 900;
	this->videoMode.width = 736;

	this->window = new sf::RenderWindow(this->videoMode, "PAC-MAN", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initializeMap()
{
	map.load("MapScheme.txt");
}

void Game::initializeGhosts() 
{
	for (float i = 0; i < 6; i++) 
	{
		Character* character = new Ghost({ 272 + (i * 32.f), 336 });
		if (character->loadTexture("textures/blinky.png"))
			ghosts.push_back(character);
		else
			std::cerr << "Failed to initialize ghost!" << "\n";
	}
}


void Game::renderPacMan(sf::RenderWindow& window)
{
	pacMan.draw(window);
}

Game::Game() : points(0)
{
	this->initializeWindow();
	this->initializeMap();
	this->initializeGhosts();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (this->ev.key.code == sf::Keyboard::W)
				pacMan.setDesiredMove({ 0, -1 });
			else if (this->ev.key.code == sf::Keyboard::S)
				pacMan.setDesiredMove({ 0, 1 });
			else if (this->ev.key.code == sf::Keyboard::A)
				pacMan.setDesiredMove({ -1, 0 });
			else if (this->ev.key.code == sf::Keyboard::D)
				pacMan.setDesiredMove({ 1, 0 });
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();

	if (map.isPointCollected(pacMan))
	{
		points++;
	}

	ui.update(points);

	collision.isGhostCollision(pacMan, ghosts);

	if (!collision.isWallCollision(pacMan, map)) 
	{
		pacMan.move();
	}

	for (auto& ghost : ghosts)
	{
		ghost->move(map);
	}
}

void Game::render()
{
	this->window->clear(sf::Color::Black);

	if (points >= 243 || collision.ghostCollisionState())
	{
		ui.drawEndScreen(*window);
	}
	else
	{
		map.draw(*window);

		pacMan.draw(*window);

		for (auto& ghost : ghosts)
		{
			ghost->draw(*window);
		}

		ui.drawScoreTitle(*window);

		ui.drawScore(*window);
	}

	this->window->display();
}
