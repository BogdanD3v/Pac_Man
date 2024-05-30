#pragma once

#include "Map.h"
#include "PacMan.h"
#include "CollisionManager.h"
#include "UserInterface.h"
#include "Ghost.h"

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:

	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	std::vector<Ghost*> ghosts;

	int points;

	Map map;

	PacMan pacMan;

	Ghost* ghost;

	CollisionManager collision;

	UserInterface ui;

	void initializeWindow();

	void initializeMap();

	void initializeGhosts();

	void renderPacMan(sf::RenderWindow& window);

	void endOfGame();

public:

	Game();
	virtual ~Game();

	const bool running() const;

	void pollEvents();
	void update();
	void render();
};