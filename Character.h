#pragma once

#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Logger.h"

class Character
{
private:

	sf::Vector2f currentDirection;
    sf::Vector2f position;
	float velocity;

protected:

	Character(sf::Vector2f);

public:

    virtual ~Character();

    virtual bool loadTexture(const std::string&, Logger&) = 0;

    virtual void setPosition(const sf::Vector2f&) = 0;

    virtual void move(Map&) = 0;

    virtual void draw(sf::RenderWindow&) = 0;

    virtual sf::Vector2f getPosition() = 0;
};

