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
    bool isValidMove(const sf::Vector2f& position, Map&);
    void changeDirection();

public:
    Ghost();

    bool loadTexture(const std::string& filename);

    void setPosition(const sf::Vector2f& position);

    void move(Map&);

    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition();
};
