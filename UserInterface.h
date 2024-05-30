#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class UserInterface
{
private:

	sf::Text score;
	sf::Font font;

public:

	UserInterface();

	void draw(sf::RenderWindow& window);
	void update(int);

};

