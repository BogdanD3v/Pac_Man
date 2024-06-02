#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Map.h"

class Ghost
{
private:

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f direction;
    float velocity;

    sf::Vector2f getNextPosition();
    bool isValidMove(const sf::Vector2f&, Map&);
    void changeDirection();

public:
    Ghost();
    ~Ghost();

    bool loadTexture(const std::string&);

    void setPosition(const sf::Vector2f&);

    void move(Map&);

    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition();
};
