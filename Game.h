#pragma once

#include "Map.h"
#include "PacMan.h"
#include "CollisionManager.h"
#include "UserInterface.h"
#include "Ghost.h"
#include "Character.h"
#include "ObjectManager.hpp"

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

	int points;

	Map map;

	PacMan pacMan;

	CollisionManager collision;

	UserInterface ui;

	ObjectManager<Character*> ghostManager;

	void initializeWindow();

	void initializeMap();

	void initializeGhosts();

	void renderPacMan(sf::RenderWindow& window);

public:

	Game();
	virtual ~Game();

	const bool running() const;

	void pollEvents();
	void update();
	void render();
};